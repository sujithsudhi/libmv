Contents


# Introduction #

Libmv has several applications and tools, this page describes some of them.

# Mosaicing video #
## Description ##
**Mosaicing\_video** is a tool for making a mosaic from a video (list of images). It uses the following simple approach:

From the given features matches, the chained relatives matrices are estimated (affine or homography) and images are warped and written in a global mosaic image. The overlapping zones are blended and the last image takes 50% of the blending.

  * First release: libmv >0.1

### Example ###
```
mosaicing_video frame1.jpg frameN.jpg -m matches.txt -o mosaic.jpg 
```
### Limitations ###
  * Images must be radially corrected.
  * images must be given in the same order/number than when the **tracker** were called.
  * Only for video
  * It's a draft!
## Results or screenshots ##
_TODO: add here a screenshot_


# Reconstruct video #
## Description ##
**Reconstruct\_video** is a tool that localizes a camera and sparsely reconstruct the 3D scene.

  * First release: libmv 0.1

### Example ###
```
reconstruct_video -i matches.txt -o recons.ply -w 640 -h 480 -f 515.295
```
### Limitations ###
  * matches.txt can be obtained using the **tracker** tool

## Results or screenshots ##
_TODO: add here some screenshots_


# Stabilize video #
## Description ##
**Stabilize** is a tool for stabilizing a video.
It uses the following simple approach:
From the given features matches, the chained relatives matrices are estimated (euclidean, similarity, affine or homography) and images are warped so that the features keep the same position in every images.
  * First release: libmv >0.1

### Example ###
```
stabilize frame1.jpg frameN.jpg -m matches.txt -of ouput_folder/
```
### Limitations ###
  * This version supports **only fixed camera** (no moving camera)
  * The colors are not smoothed, ie. **the pixel colors are not stabilized**
  * The empty spaces are filled with the previous stabilized images and are not blended/smoothed.
  * Images must be radially corrected.
  * images must be given in the same order/number than when the **tracker** were called.
  * Only for video
  * It's a draft!

## Results or screenshots ##
_TODO: add here a video_


# Tracker #
## Description ##
**Tracker** is a point tracker tool that takes images as input and gives point tracks with matches as output. It saves all results into a .txt file.
  * First release: libmv 0.1

### Example ###
```
tracker frame1.jpg frameN.jpg -o matches.txt
```
### Limitations ###
  * Images must be radially corrected.

## Results or screenshots ##
_TODO: add here some images or a video?_

# Undistort #
## Description ##
**Undistort** is a tool for undistorting images using known lens distortion coefficients. It supports radial (up to 5 coef.) and tangential distortions (up to 2 coef). Undistorted images are saved in the specified output folder with a suffix ("undist").
  * First release: libmv >0.1

We use the Brown's distortion model
Variables:
  * `(x,y)`: 2D point in the image (pixel)
  * `(u,v)`: the undistorted 2D point (pixel)
  * radial\_distortion `(k1, k2, k3, ...)`: vector containing the    radial distortion
  * tangential\_distortion_`(p1, p2)`: vector containing the  tangential distortion
  * `(cx,cy)`: camera principal point_

### Example ###
```
undistort image1.jpg imageN.jpg -k1 0.02 -fx 515.295 -of ouput_folder/
```
### Limitations ###
  * All images must have the same size.
  * The output images are not resized

## Results or screenshots ##
_TODO: add here some images_

# XXX #
_TODO: describe others tools/UIs._