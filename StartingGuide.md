Content


# Introduction #

**libmv** is a structure from motion library, which plans to one day take raw video footage or photographs, and produce full camera calibration information and dense 3D models.

**libmv** is cut in different modules (image/detector/descriptor/multiview) that allow to resolve part of the SfM process. Each module purpose documented functional implementation that rely on an Interface. The user could choose to use the available implementation or to customize the module by writing is own by using the same general interface.

# Libraries #

## Numeric ##
**Numeric** contains matrix and vector operations, for fixed size and dynamically sized matrices and vectors. We actively use the Eigen library.

  * Standard matrix and vector operations.
  * Linear algebra routines (nullspace, pseudo-inverse, etc).

## Image ##
**Image** contains structures and algorithms related to image handling.

  * Image container (1->3 channel, various bit depth),
  * Image Convertion (RGB to Gray),
  * Image Drawing (Line, Circle, Rotated Ellipse),
  * Image linear transformation (rotation, translation, generic warp),
  * Image Sequence,
  * Image Pyramid.

  * Image IO
    * JPG, PNM, PGM, PNG.

  * Depends on _numeric_

## Detector ##
**Detector** contains different points and regions detectors.

  * Corner detector (FAST),
  * SURF/ STAR,
  * MSER.

  * Depends on _image, correspondence_

## Descriptor ##
**Descriptor** contains various 2D descriptors.
  * Sparse patch (Simplest),
  * SURF,
  * DAISY,
  * DIPOLE (WIP).

  * Depends on _image, correspondence_

## Correspondence ##
**Correspondence** contains data structures for representing and manipulating correspondences between images (feature matching and tracking).

  * ArrayMatcher (Nearest Neighbor search)
    * Brute Force,
    * KDTREE (2 implementations : libmv, flann)

  * FindCandidateMatch
    * Symmetric nearest neighbour,
    * Lowe Ratio.

  * Matches
    * Allow to maintain tracks between images features.

  * NViewMatching
    * Robust filtered matches between N Images.

  * Tracker

  * Depends on _numeric, image_

## Multiview ##
**Multiview** contains various basic structures and algorithms for estimating the 2D or 3D motion of a camera and the 3D structure of a rigid scene.

  * 2D Rigid geometric constraint
    * From known correspondences (linear & robust estimation, nonlinear will follow)
      * Euclidean
      * Similarity
      * Affine
      * Homography

  * 3D Rigid geometric constraint
    * From known correspondences (linear estimation, nonlinear will follow)
      * Euclidean (Euler, Angle Axis, Quaternion)
      * Similarity
      * Affine
      * Homography

  * 2 View Tensor
    * Linear solvers
      * Fundamental Matrix 7 Points
      * Fundamental Matrix 8 points
      * Essential Matrix (+R,t extraction)

  * N View Tensor
    * Linear solvers
      * 6 Points solver

  * Robust estimation
    * Random Sample Consensus (linear)
      * RANSAC

  * 2D Conditioning
    * Isotropic
    * Anisotropic

  * Camera pose
    * 5 Points solver
    * 8 Points solver
    * Projective resection
    * Euclidean resection
      * Ansar and Daniilidis method
      * EPnP

  * Triangulation
    * 2 Views triangulation
    * N Views triangulation
      * Geometric method
      * Algebraic method

  * Autocalibration
    * Linear
    * Nonlinear

  * Euclidean Bundle Adjustment
    * Wrapper to _simple sparse BA_

  * Panography
    * Minimal solver

  * Depends on _numeric_

## Camera ##
**Camera** contains structures and algorithms related to camera and lens.
  * Pinhole camera
  * Lens: radial and tangential correction

  * Depends on _numeric, multiview_

## Reconstruction ##
**Reconstruction** contains advanced algorithms for estimating the 3D motion of a camera and the 3D structure of a rigid scene from a video (and in the future, from an unordered image set).

  * Images selection
    * Keyframe selection (based on the number of shared tracks)

  * Euclidean reconstruction
    * 2 Views robust initial reconstruction
    * Incremental reconstruction (keyframes) by resection
    * Non-keyframes resection

  * Mapping
    * Euclidean and Projective mapping

  * Reconstruction IO
    * Export to Blender Python Script (.py)
    * Export to PLY

  * Depends on _numeric, multiview, camera_


## Tools ##
**Tools** contains some useful tools.
  * Reading JPEG EXIF meta data.

# Applications and Tools #

**libmv** has also several applications and tools , see the dedicated page [ApplicationsAndTools](ApplicationsAndTools.md).