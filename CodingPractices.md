# Introduction #

It is extremely important that a project has a style guide, and that it is followed closely. It is not particularly important which style guide (within reason), as long as there is one, and the code consistently follows it. See [this post](http://lwn.net/Articles/270620/) on LKML from a notable kernel hacker about one developer's realization of the value of uniform style.

**We follow the Google coding conventions. See the [Google C++ Style Guide](http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml) for more details.** Below are some of the things in the style guide, mainly around formatting.

## Commit messages ##

```
One line summary.

Longer explanation if one is necessary; perhaps explain 
why the change was necessary or other details about the change.

- Feel free to add.
- Bulleted sections.
- But NOT on the first line.
```

Do NOT put any hyphen or punctuation in front of the summary line:
```
- Don't make messages like this! BAD!
- They look really bad when you go to updates on Google code.
```
Notice that the first line has a '-' which appears in the one line summary for changes on code.google.com. This is why the first line should not have such punctuation characters.

## Comments ##

All comments must be full sentences. This means at the very least, they all start with a capital letter and end with a period.

# C++ conventions #

## 80 character lines ##
All lines should be 80 characters or less. Function calls that are too long should be indented up to their opening brace, or indented 4 characters on a new line. The two styles are:
```
  MyLongFooName my_foo = ReallyLongFunctionHere(param1,
                                                param2,
                                                param3);
```
or
```
  MyLongFooName my_foo = ReallyLongFunctionHere(
      param1, param2, param3);
```
Sometimes it is clearer to break after the `=`. In that case indent 4 spaces on the new line. For example:
```
  MyLongFooNameIsGettingOutOfHandHuge my_foo_with_a_gigantic_name =
      ReallyLongFunctionHere(param1, param2, param3);
```

## 2-space indents ##

Use 2-space indents with no tabs anywhere. Exception is `public/protected/private` which are indented one space. For example:
```
class MyFoo {
 public:
  void FooMethod();
  void MoreFoo();
 private:
  int num_foos_;
};
```

## Brace on same line ##
Always put opening curly braces on the same line. For example:
```
void Foo() {
  // ...
}

void Foo()  // Bad!
{
  // ...
}
```

## No exceptions ##
Though libraries may throw them, our code does not.

## Spaces around operators ##
```
int x = y * 4;
```
not
```
int x=y*4; // Bad!
int x = y*4; // Bad!
```

## Naming ##

Classes, functions, and methods are CamelCase (but not lowerCamelCase). Example:
```
void Function(int x, int y) {
  // Do stuff.
}

class MyClass {
  void AllMethodsAreCapitalized();
  int MoreCapitalizedMethods();
};
```
Variables should be `named_with_underscores`.
```
int my_variable, num_cameras;
```
Member variables should be named with a trailing underscore.
```
class Foo {
 public:
  ...
 private:
  int num_something_;
  vector<Foo *> other_foos_;
};
```

## Placement of `*` and '&' ##

Put these next to the variable.
```
int *x;
int* x; // Bad!

vector<Foo *> foos;
vector<Foo*> foos; // Bad!

const vector<int> &numbers;
const vector<int>& numbers; // Bad!
```

## Input and output parameters ##

  * Use `const Type &input_param` for inputs that are not changed.
  * Use `Type *output_param` for outputs that are modified.

For example:
```
void ReadSiftCorrespondences(const string &filename,
                             vector<Correspondence> *correspondences) {
  // Open filename.
  // Read correspondences into correspondences vector.
}
```

This has the nice property that it is always apparent what is happening to parameters just from a callsite, without having to look up the function definition.

# Unit tests #

Most code checked in should be covered by a unit test. Yes, even the vision code! In the short term it seems easier to Just Do It, not writing tests, however this does not work out in the long term. There are several benefits to writing comprehensive unit tests. See some of the following articles [1](http://dlsthoughts.blogspot.com/2005/08/cost-benefits-of-unit-testing.html), [2](http://www.codeproject.com/KB/architecture/onunittesting.aspx), [3](http://www.code-magazine.com/Article.aspx?quickid=0411031).

We use a slightly patched version of [testsoon](http://testsoon.sourceforge.net/) for unittesting.

## Adding a new test ##

Give a file and a header, `foo.cc` and `foo.h`, put the test in `foo_test.cc`. This keeps tests in the same place as the code, which is generally desired. Some tests use generated matrices from Python via numpy; name those `foo_test_data.py`.

For example, in the simple case there are files:
```
foo.cc
foo.h
foo_test.cc
```
If there is a single data file (for example a small png), it would be named the same as the test. For example:
```
foo.cc
foo.h
foo_test.cc
foo_test.png
```
If there is more test data, then it would go in a subdirectory named after the test
```
foo.h
foo.cc
foo_test.cc
foo_test/image1.png
foo_test/image2.png
foo_test/...
```
If there is test data to be shared across multiple tests, put it in `testdata/`. For example:
```
foo.h
foo.cc
foo_test.cc
bar.h
bar.cc
bar_test.cc
testdata/image1.png
testdata/image2.png
```
where both `foo_test.cc` and `bar_test.cc` use the data inside testdata.

# Doxygen conventions #

Functions that are expected to become part of libmv's public API should get doxygen comments. Here is the preferred style:
```
/*!
    The Tracks class stores \link Marker reconstruction markers \endlink.
    
    The Tracks container is intended as the store of correspondences between
    images, which must get created before any 3D reconstruction can take place.
    
    The container has several fast lookups for queries typically needed for
    structure from motion algorithms, such as \l MarkersForTracksInBothImages().
    
    \sa Marker
*/
class Tracks {
 public:
  /*!
      Inserts a marker into the set. If there is already a marker for the given
      \a image and \a track, the existing marker is replaced. If there is no
      marker for the given \a image and \a track, a new one is added.
    
      \a image and \a track are the keys used to retrieve the markers with the
      other methods in this class.
    
      \note To get an identifier for a new track, use \l MaxTrack() + 1.
  */
  void Insert(int image, int track, double x, double y);

```

# Formatting and naming conventions for Python #

  * Follow [standard Python style (PEP8)](http://www.python.org/dev/peps/pep-0008/).