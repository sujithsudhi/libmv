# Introduction #

There are many image libraries to chose from. In libmv there are a couple of constraints on what libraries we can use, because we want to remain commercial friendly. Furthermore, we would like whatever image library we chose to be sufficiently understandable that we can modify it if necessary.

Because the focus is on tracking, our initial needs are fairly limited:
  * loading the image,
  * converting to grayscale,
  * and access its pixels with subpixel precision.

Given that the needs are few, that we want to reduce libmv's dependencies to a minimum, and that we want to have control on how the images behave, we have decided to design our own image library.

## Goals ##
  * Simple and compact image container, which do not necessarily own the pixel data.
  * Easy access to the raw image data.
  * Easy conversion from and to other image types without copying pixel data.
  * Friendly access to pixel data as `image(i,j,k)`.
  * Basic support for different pixel formats (grayscale, RGB, RGBA, ...) and channel arranging strategies (an array of RGB values vs. 3 arrays, one per color).
  * Read and write in a variety of formats.  Initially, `.pgm` (trivial), `.png` (via `libpng`), and jpg (via `libjpeg`).
  * Different interpolation methods (nearest, linear, cubic).
  * Support for building image pyramids.


## Non-Goals ##
  * A video library.  For now video will be read as a sequence of image files.
  * Drawing functionality.


# Desired Behavior #

Construction and assignation.
```
Image im(480,640,3); // Creates a 480 rows, 640 columns and 3 channels image.
assert(im.Height() == 480);
assert(im.Width() == 640);
assert(im.Depth() == 3);
Image im2(im); // Creates a deep copy of the image.  Pixel data is copied.
ImageView im_view = im.view(); // Creates a view of im that shares data with im.
Image im3; // Creates an empty image;
im3 = im;  // Assignation copies data;
im3 = im_view;  // Copies data viewed by im_view.
```

Accessing to pixels.
```
Image im(480,640,3);
im(y,x,v); // Access pixel at row y, column x, channel v
           // In debug mode it does boundary checking.
im(y,x); // Access pixel at row y, column x of a grayscale image
         // In debug mode it checks that im.Depth() == 1;
```

# Design #
The image container and the algorithms that use it and the io functions should be separated, so that the container remains simple.

## The container ##
2D images can be easily represented as 3D arrays whose indices represent row, column and channel.  We have two options here:
  * write a dedicated image container, or
  * use an existing 3D array container, eventually from FLENS.

Writing a dedicated container is not hard.  For example, here are the basic parts of a simple template class that would do the job:
```
/// A simple image class storing pixel values in a 3D array.
/// Acces to component v of pixel (x,y) as im(y,x,v).
template <typename T>
class Image
{
  /// The number of elements in each dimension.
  int shape_[3];
  /// How to jump to neighbors in each dimension.
  int strides_[3];
  /// Pointer to the first element.
  T *data_;
  /// A shared pointer to the data buffer so that pixels get deleted
  /// when last image using them is deleted.
  boost::shared_array<T> shared_buffer_; 

 public:
  Image(int s0, int s1, int s2) {
    Reset(s0,s1,s2);
  }
  
  /// Set the shape of the image and allocates the pixels.
  void Reset(int s0, int s1, int s2) {
    shape_[0] = s0;
    shape_[1] = s1;
    shape_[2] = s2;
    strides_[2] = 1;
    strides_[1] = strides_[2] * shape_[2];
    strides_[0] = strides_[1] * shape_[1];
    if(size()>0)
      data_ = new T[size()];
    else
      data_ = NULL;
    data_buffer.reset(data_);
  }
  
  /// Return the number of elements along an axis.
  int Shape(int axis) const {
    return shape_[axis];
  }

  /// Return de distance between neighboring elements along axis.
  int Strides(int axis) const {
    return strides_[axis];
  }

  /// Return the total number of elements.
  int Size() const {
    return Shape(0) * Shape(1) * Shape(2);
  }

  /// Return the number of rows of the image.
  int Height() const {
	  return Shape(0);
  }

  /// Return the number of columns of the image.
  int Width() const {
	  return Shape(1);
  }
  
  /// Return the number of channels of the image.
  int Depth() const {
	  return Shape(2);
  }

  /// Return a pointer to the element
  T *TopLeftPtr() {
    return data_;
  }

  /// Return the number of elements between the origin and a given position.
  int Offset(int i0, int i1, int i2) const {
    return i0 * Strides(0)
	 + i1 * Strides(1)
	 + i2 * Strides(2);
  }
  
  /// Return a reference to element (i0,i1,i2).
  T &operator()(int i0, int i1, int i2) {
    return *( TopLeftPtr() + Offset(i0,i1,i2) );
  }

  /// Return a constant reference to element (i0,i1,i2).
  const T &operator()(int i0, int i1, int i2) const {
    return *( TopLeftPtr() + Offset(i0,i1,i2) );
  }
  
  /// Return true if (i0,i1,i2) is inside the image. 
  bool Contains(int i0, int i1, int i2) const {
    return i0 >= 0 && i0 < Shape(0)
	&& i1 >= 0 && i1 < Shape(1)
	&& i2 >= 0 && i2 < Shape(2);
  }
};
```



## Multidimensional arrays ##

The image class bellow can easily be generalized to an arbitrary number of dimensions.  Although there is no urgent need for a multidimensional array type, it will certainly be useful at some point since it is a basic and very versatile data structure.  Examples of uses include voxels (3D arrays), voxels with colors (4D arrays), color histograms (3D array), coordinate lists (2D array)...

It may be a good idea to build a ArrayND class from the beginning.  If we do so, then the Image class can heritate from the 3D array, and add some syntactic sugar such as `Height()` and `Width()` methods.

We have to see how this n-dimensional arrays can inter-operate, or be build from FLENS structures.


## Image algorithms ##

Assuming that we are going to build the ArrayND class, then there are certain image algorithms like interpolation that should better be considered ArrayND algorithms, since they are not intrinsically restricted to 2D arrays.  Since the image class will heritate from the array class, this algorithms will work with images also.  Other functionalities, such as io are exclusive for images.