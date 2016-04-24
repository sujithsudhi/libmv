# Introduction #
This document describes how libmv is interfaced in blender. It does not give you a full description of the libmv API, but merely tries to describe how the libmv API is used within blender.


## C and H files ##
  * The interface file is called BF\_libmv.cpp and is located HERE.
  * libmv is placed under blender\external\libmv
  * the UI menus live here


## Classes ##
There is one class that holds data which is exchanged between libmv and blender. Settings as well as some results are stored here. Extending the sharing of data between the two of them simply requires extending this class.

> class libmvData
> {
> > class libmvConfig


> TrackedSequence

> EuclideanReconstruction
> }


# Blender interface #
There is one source file that interfaces between libmv and blender. It wraps all implementation so the sources stay clean and extending functionality or changing libmv API is easily maintained.


# libmv\_track #
This is the main function. The calling parameters are:

The following list globally describes the order of function calls to libmv and the meaning of the respective calls. This list is not complete by any means and just serves as a guide. For more information see Keirs thesis.

  1. track\_sequence: Run the KLT tracking program on each frame, to track the sequence and obtain correspondences across frames.
  1. undistort\_track: Unwarp the radial distortion from the tracks using camera calibration information.
  1. pick\_keyframes: Find keyframes using an image-based bucketing heuristic.
  1. reconstruct\_keyframes(_nview): Perform projective reconstruction from pairs of keyframes, using the three-frame reconstruction algorithm where the third frame is between the two keyframes.
  1. bundle\_adjust\_subsets: Bundle adjust the subsets independently, using a robust Huber cost function instead of simple squared error, so as to prevent outliers from skewing the results. This is actually done in the reconstruct program in the previous step.
  1. merge\_hierarchical: Merge the subsets together via structure pasting. The algorithm is a combination of RANSAC with the one-frame structure pasting method. Outliers are detected and removed, using the same robust fitting technique used during three-frame reconstruction.
  1. resection\_reconstruction: Resection the remaining cameras, also using RANSAC as above to handle outliers, and also bundle adjust the resulting projective reconstruction.
  1. ProjectiveReconstruction->trim\_outliers: Upgrade to a metric reconstruction by finding the plane at infinity, and then transform the cameras and structure by the rectifying homography.
  1. ProjectiveReconstruction->bundle\_adjust: Run a final metric bundle adjustment.
  1. For evaluation, there is code to compare the obtained reconstruction to ground truth. This automatically aligns the reconstruction with ground truth for comparison._


## coplanarity ##
To constrain the solver features can be grouped and are set to be coplanar. This requires the need to be able to select distinct features and group them together.


# Blender UI #
The blender UI is kept as clean as possible and numerous settings that libmv allows you to do are hidden in BF\_libmv.c.
An example of the new tracker menus is shown in the following image.

![http://libmv.googlecode.com/svn/wiki/blender_track_menu.jpg](http://libmv.googlecode.com/svn/wiki/blender_track_menu.jpg)


## Tracker dialog ##
The tracker dialog shows the following items:

  * start frame of the tracking sequence (integer, 1)
  * end frame of the tracking sequence (integer, frame count)

  * number of features to track (integer, 500)
  * number of RANSAC rounds in 3point reconstruction (integer, 300)

  * camera intrinsics (file path)

  * bundle adjust subsets after each one is created (boolean, true)
  * use nview rather than threeview code for subsets (boolean, true)
  * trim outliers before bundling (boolean, false)
  * force points to be in front of camera (boolean, true)
  * first subset of the sequence to use (integer, 1)
  * last subset of the sequence to use (integer, frame count)

  * track button to start the feature tracking (push button)
  * solve button to start the 3D solver (push button)


## Constraints dialog ##
  * Selected features are coplanar (link feature groups to a planar object like a bone or have a system like the modifier stack eg constraint stack)


## Visualization dialog ##
This dialog allows you to do some settings on how to visualize the tracking process

  * show tracks: show the feature tracks
  * show features: show features as 2D points in the camera
  * track length: fade track after X frames


# Todo #
  * Investigate whether or not to save extended settings in an XML file in the root of the blender directory. This way we can keep the UI clean and still provide maximal flexibility to the user.
  * Enabling selection of individual features, one way of solving this is to create empties for each feature in the image plane and add an IPO curve for the moving in XY direction. The user can modify the movement of features in consecutive frames before running the 3D solver.