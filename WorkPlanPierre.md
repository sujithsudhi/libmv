# Currently working on #

- ~~Test FLANN (Fast Library for Approximate Nearest Neighbors) for integration in libmv.~~
  * ~~Make a Flann wrapper that work as the same of libmv KDTree class.~~

- Minimal solution for panoramic stitching :
http://people.cs.ubc.ca/~mbrown/minimal/minimal.html
  * ~~2 Points solution shared focal length (minimal case).~~
  * 2 Points solution shared focal length (least square fitted on N points)
    * focal
    * ~~rotation~~
  * 3 Points solution != focal length.

- Write a short test to assert invariance of detector.
  * Compute repeatability of detection over an image sequence with known transformation.
    * ~~compute position repeatability and accuracy.~~
    * compute rotation repeatability and accuracy.
    * compute scale repeatability and accuracy.

- Add basic rotation invariance :
  * ~~for FAST detector.~~
  * ~~for STAR detector. (WIP)~~

- Make TVR crash proof (avoid crash when we click on a menu not in the good order).

# Task State #
**~~Done~~** Todo/Comment

## Multiview ##
  * ~~Add seven points fundamental matrix estimation.~~
  * ~~Write down a tool to render image warping given two image => homography\_warping.cc.~~
  * Add Orsa robust matching (http://www.math-info.univ-paris5.fr/~moisan/epipolar/). A Ransac like but without hard threshold to check inliers/outliers at model verification time.

## Minimal solution for panoramic stitching ##

  * ~~understand the 2 point algorithm and code/test it~~
    * An error have been found in a calculus detail of the paper.
  * Todo :
    * Understand and code the 3 point solution. (not an obligation).
    * ~~Write down the robust estimation. => HomographyFromCorrespondences2PointRobust.~~
      * Seems to be quite unstable, the focal length cannot be estimated in all the case. Also I don't have a method to get the focal length from N correspondences.

## Feature extraction \ Detector ##
  * ~~Write down the **FAST Corner Detector** wrapper for libmv (Keir helps a lot)~~
    * ~~Add basic rotation invariant estimation.~~
  * ~~Write down the **STAR blob Detector** (based on OpenCV code. It's a SURF like patented free)~~
    * ~~Add basic rotation invariant estimation.~~
  * ~~Write down the **MSER detector** (based on OpenCV code)~~
    * ~~Add rotated ellipse drawing.~~

## Feature extraction \ Descriptor ##
  * ~~Integrate **Daisy** descriptor (A Fast Local Descriptor for Dense Matching). (Keir helps a lot)~~
  * ~~Basic descriptor to make **FAST** usable. (**Simpliest** descriptor a 8\*8 patch)~~
    * ~~A basic oriented patch descriptor~~
    * ~~Use basic sampling grid for the descriptor (8\*8 sparse sampling).~~
    * If times use a quantizer to compress descriptor size :
      * use a HIPS like descriptor http://mi.eng.cam.ac.uk/~sjt59/hips.html
    * Add dissociated **dipole descriptor** (20 values and seems as reliable as SIFT)
      * ~~Naive implementation in image space gives very good result for panoramic purpose~~

## Feature descriptor matching ##
  * ~~Look to FLANN (Fast Library for Approximate Nearest Neighbors) to replace libmv putative matches research.~~
  * Make KDTREE use a generic distance method. In order to use ( L2/ L1 / CEMD distance).
  * ? KDTREE Best Bin First BBF ? (in order to find N neighbors).

  * ~~- Write down a generic Arrays matcher class :
    * Could be used to perform Linear match (test all putatives distances and select the best one).
    * Could be used to perform Hierarchical matching (libmv KDTree)
    * Could be used to perform Hierarchical matching (Flann KDTree)~~

  * ~~Write down a 2d affine motion estimation.~~
  * ~~Write a short test to assert invariance of detector (done via detector repeatability).
    * robust to translation,
    * robust to rotation,
    * robust to scale (Fast is not Scale invariant).
    * We must take a look to YAPE (Yet Another Point Extractor) from LePetit Group (CVLab).
    * We must take a look to StartDetector from OpenCV 2.0 (Surf like but patent free keypoint detector).~~

## Interface ##

  * design a basic interface that can be an equivalent of TVR for multiview purpose.
    * Thanks to Matthias, this part if in WIP (see the nview application)
    * Must support from 2 to N views.
    * Make a Panoramic or SFM (structure from motion) mode.

## Design ##
  * ~~Write down a generic feature localization/extraction feature. (Done by Keir)~~

## Image database (Academic) ##

Ponce Group : http://www-cvr.ai.uiuc.edu/ponce_grp/data/

Visual Geometry Group : http://www.robots.ox.ac.uk/~vgg/data/

Amsterdam Library of Object Images (ALOI) : http://staff.science.uva.nl/~aloi/

EPFL cvlab : http://cvlab.epfl.ch/data/index.php

Zubud Dataset : http://www.vision.ee.ethz.ch/datasets/index.en.html

Notre Dame de Paris (dataset 715 images) : http://phototour.cs.washington.edu/datasets/

Image Stitching database (homography between images with Ground Through):
http://math.ipm.ac.ir/vision/VDownloads.html