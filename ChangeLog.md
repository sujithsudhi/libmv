Releases


# Introduction #

This page summarizes the main changes of the different versions of libmv.
A complete changelog can be found in http://code.google.com/p/libmv/source/browse/trunk/ChangeLog.

# Libmv 0.1 #
Released on **March 26, 2011**.

Changes since libmv 0.0.2:
## API changes ##
  * New libraries
    * Base (library)
      * Added a simple id generator
      * Added a scoped pointer
      * Added a simple vector class
      * Added various unit tests
    * Camera (library)
      * Added a generic camera class (with a pixel-to-ray function)
      * Added a pinhole camera class
      * Added a lens distortion class _(for radial and tangential correction)_
      * Added various unit tests
    * Descriptor (library)
      * Added a generic class descriptor, inherited by every descriptors
      * Added a descriptor factory
      * Added a DAISY descriptor
      * Added a Dipole descriptor
      * Added a Simpliest descriptor
      * Added a SURF descriptor _(limitations?)_
      * Added unit tests (daisy)
    * Detector (library)
      * Added a generic class detector, inherited by every detectors
      * Added a detector factory
      * Added a FAST detector
      * Added a MSER detector
      * Added an Orientation detector
      * Added a STAR detector
      * Added a SURF detector
      * Added unit tests (orientation)
    * Logging files
      * Added a logging file that should be included for logging purpose
    * Optimize (library)
      * Added a simple automatic differentiation (jet.h)
    * Reconstruction (library)
      * Added a reconstruction class which store all cameras and structures
      * Added point structure triangulations and re-triangulations for euclidean or projective reconstructions (mapping.h)
      * Added a metric sparse bundle adjustment (optimization.h)
      * Added euclidean specific reconstruction functions (reconstruction from a video, camera resection, initial reconstruction 2 views, incremental reconstruction for keyframes and non keyframes)
      * Added projective specific reconstruction functions (camera resection, initial reconstruction 2 views, reconstruction upgrade to metric)
      * Added a simple image selection based on the homography score
      * Added a keyframe selection method based on the common
      * Added exports to PLY files and blender script (python)
      * Added some common tools for the reconstruction (such as selection of all reconstructed or non reconstructed points, etc.)
      * Added a basic unit test on reconstruction
    * Scene\_graph (library)
      * Added a scene graph class
      * Added a simple scene graph class _(difference with the previous one?)_
      * Added various unit tests
    * Tools (library)
      * Added an Exif reader file
      * Added a tool.h file
  * Libraries updates
    * Correspondence (library)
      * Added a generic array matcher class (ArrayMatcher)
      * Added an array matcher based on a brute force approach
      * Added an array matcher based on a Kd-tree approach
      * Added an array matcher based on the Flann library
      * Updated a simple bipartite graph
      * Added a new version of the bipartite graph (barely started)
      * Added and updated a generic Feature class, with PointFeature and LineFeature classes.
      * Added feature matching functions based on BF, Kd-tree or Flann
      * Added a feature set class
      * Added a kdtree class (with a PriorityQueue)
      * Updated the KLT tracker
      * Added a matches class that store all matches and 2D tracks
      * Added import/export of matches functions (text format)
      * Added a robust matcher nRobustViewMatching
      * Added a point tracker and a robust one with epipolar filtering
      * Added a points-on-a-plane tracker with homography filtering (useful for natural features augmented reality)
      * Added various unit tests
    * Image (library)
      * Updated the n-dimensional array used to store image pixels
      * Updated a blob\_response that computes the 'interestingness' of an image at a certain scale
      * Updated a generic cache interface,  an image cache and a cached image sequence
      * Updated Gaussian and other types of convolutions
      * Updated a generic image class (byte/float/int/short)
      * Updated a RGB to gray image conversion function
      * Added some image drawing  functions (ellipse, circle, line) based on the Bersenham approach
      * Updated some image input/output functions (PNG, JPEG, PNM)
      * Updated an image pyramid class
      * Updated an image sequence class,  filters and input/output functions
      * Updated a generic integral image class
      * Updated a lru cache class //more info needed
      * Updated a mock\_image\_sequence class //more info needed
      * Updated some non maximal suppression functions
      * Updated a pyramid sequence class
      * Updated some image sampling functions
      * Updated a surf file
      * Updated a surf\_descriptor file
      * Updated a generic tuple class //more info needed
      * Added and updated various unit tests
    * Multiview (library)
      * Added an affine 2d estimation (+ a robust version)
      * Added a linear autocalibration method
      * Added two bundle adjustment methods (full/sparse). It is basically a wrapper to SSBA
      * Added some conditioning functions (isotropic and non isotropic normalizations)
      * Added two euclidean resection methods  (EPnP or AnsarDaniilidis) (+ a robust version)
      * Added the five points algorithm (relative pose estimation) (+ a robust version)
      * Updated and added some fundamental matrix estimations (7 points, 8 points) (+ a robust version)
      * Added a rank 2 fundamental matrix parameterization
      * Added some essential matrix estimations (5 points, 8 points) and extraction fro (+ a robust version)
      * Added some functions for extracting the essential matrix from a fundamental matrix and camera pose from the essential matrix or the focal from the fundamental
      * Added an homography estimation (+ a robust version)
      * Added two point reconstruction for uncalibrated N views methods (standard, algebraic)
      * Updated the reconstruction from six points of N views.
      * Added a panography stitching (minimalistic: 2 points) function (+ a robust version)
      * Updated and added some useful projection functions and tools (homogeneous to/from euclidean, root mean square error,
      * Added a uniform random sample function that picks a random subset of the integers [0, total), in random order.
      * Added a projective resection method (+ a robust version)
      * Added a generic structure class and a point structure class
      * Updated a test data sets generator for unit tests
      * Updated the two view point triangulation using the DLT method (triangulation.h)
      * Added a two view point triangulation using DLT + the camera canonical form (twoviewtriangulation.h)
      * Added a two view kernel for robust two view solvers
      * Updated the robust estimation system (RANSAC)
      * Added various unit tests
    * Numeric (library)
      * Updated the non sparse, generic dogleg / LM
      * Updated the numeric derivative estimation system
      * Updated the basic numerical functions (nullspace, etc.), it's mainly a wrapper to Eigen
      * Updated the cubic polymial solver
  * New Extras folder with a calibration target
## Third parties ##
  * New libraries
    * Added colamd library, version 2.7.1 for all platforms
    * Added daisy library, version 1.8.0 for all platforms
    * Added fast library, version 2.1 for all platforms
    * Added flann library, version 1.2 for all platforms
    * Added jpeg library, version [r7](https://code.google.com/p/libmv/source/detail?r=7) for Win and Mac platforms
    * Added png library, version 1.2.37 for all platforms
    * Added MserDetector library, version [r3399](https://code.google.com/p/libmv/source/detail?r=3399) for all platforms
    * Added ldl library, version 2.0.1 for all platforms
    * Added pthreads-w32 library, version 2.8.0 for Win platform
    * Added OpenExif library, version 2.1.4 for all platforms
    * Added msinttypes, version [r24](https://code.google.com/p/libmv/source/detail?r=24) for Win platform
    * Added ssba library, version 1.0 for all platforms
    * Added StarDetector library, version 2.0 for all platforms
    * Added ufconfig, version 3.4.0 for all platforms
    * Added zlib library, version 1.2.3 for Unix and Win platforms
  * Third parties updates
    * Updated eigen library, version 2.0.3
    * Updated glog library, version 0.2.1
    * Updated gtest library, version 1.3.0
## Tools (command line applications) ##
  * New tools
    * Added a detector repeatability tool
    * Added a tool that extract ExifData from images
    * Added a stitching tool (homography warping)
    * Added a tool (nViewMatching) that estimates the matches of a set of images
    * Added a points detector that extracts points feature from an image and draws the detected features
    * Added a reconstruct\_video tool that takes a file containing tracks matches as input and estimate the 3D reconstruction. Save all results into a .ply/.py file.
    * Added a point tracker tool that takes images as input and gives point tracks with matches. Save all results into a .txt file.
  * Tools updates
    * Updated the tool that detects interest points using FAST detector and SURF descriptor and draws the detected features
    * Updated the experimental tool that generates random data
    * Updated the track tool that uses KTL
## UIs (Qt based applications) ##
  * New UIs
    * Added an application for two views reconstruction (tvr)
    * Added an application for n views reconstruction (nvr). Barely started.
  * Updates
    * Updated the image viewer application
## Build/tests system ##
  * New components
    * Added a ConfigureBuild cmake file which contains the compiler/linker rules for all platforms
    * Added a LibmvVersion cmake file which contains the version of libmv
    * Added a Documentation cmake file which contains the documentation rule
    * Added a Packaging cmake file which contains the packaging rules for all platforms
    * Added a Installation cmake file which contains the installation rules and macros for all platforms
    * Added a cmake\_uninstal\_cmake.in file which contains the uninstallation target
    * Added a Testing cmake file which contains the testing rules and macros
    * Added a revision.h.in which is used for defining the libmv version as preprocessor definitions
    * Added CMake modules
      * Added a FindJPEG cmake file which contains the rules for finding libjpeg
      * Added a FindLibmv cmake file which contains the rules for finding libmv. This file should be used for building external app/lib.
  * Updates
    * Updated various CMakeLists.txt
    * Removed files FindBLAS, FIndLAPACK, CheckFortranFunctionsExists
## Documentation ##
  * Added various class/function documentations
## Bug fix ##
  * Fixed [https://code.google.com/p/libmv/issues/detail?id=](https://code.google.com/p/libmv/issues/detail?id=) BoxIntegral gives negative values
  * Fixed [https://code.google.com/p/libmv/issues/detail?id=](https://code.google.com/p/libmv/issues/detail?id=) Compilation fails because of undefined references to lapack functions.
  * Fixed [https://code.google.com/p/libmv/issues/detail?id=](https://code.google.com/p/libmv/issues/detail?id=) Possible licensing conflict
  * Fixed [https://code.google.com/p/libmv/issues/detail?id=](https://code.google.com/p/libmv/issues/detail?id=) Compiling on Windows
  * Fixed [https://code.google.com/p/libmv/issues/detail?id=](https://code.google.com/p/libmv/issues/detail?id=) Compiling failure in release mode
  * Fixed [https://code.google.com/p/libmv/issues/detail?id=](https://code.google.com/p/libmv/issues/detail?id=) Linear autocalibration does not work.
  * Fixed [https://code.google.com/p/libmv/issues/detail?id=](https://code.google.com/p/libmv/issues/detail?id=) Image\_Test cmake error
  * Fixed [https://code.google.com/p/libmv/issues/detail?id=](https://code.google.com/p/libmv/issues/detail?id=) Align issue in tvr code (maybe another `vector<Mat34>`?)
  * Fixed [bug 13](https://code.google.com/p/libmv/issues/detail?id=3) tvr 3d view assertion failure
  * Fixed [bug 18](https://code.google.com/p/libmv/issues/detail?id=8) bug colored image read
  * Fixed [bug 19](https://code.google.com/p/libmv/issues/detail?id=9) Recent change in makefiles make image\_io test failed
  * Fixed [bug 20](https://code.google.com/p/libmv/issues/detail?id=0) compile patch for linux under -r 916
  * Fixed [bug 22](https://code.google.com/p/libmv/issues/detail?id=2) No .py created


# Libmv 0.02 #
Released on **February 14, 2009**.

  * Added a dense reconstruction via plane sweep algorithm.

# Libmv 0.01 #
Released on **February 12, 2009**.

First release of libmv. Primary goal is to get something released that people can play with, even if it is extremely basic.

  * Contains a single executable for reconstructing from 2 uncalibrated images.
  * The output is a blender script, containing two cameras at the appropriate position, and the cloud of reconstructed points.
  * Builds on Linux, Windows, Mac.

Internally:

  * Has basic USURF implementation.
  * Has basic non-sparse bundle adjustment.