# Introduction #

libmv consists of many components, which are summarized here.

  * NumericLibrary - `numeric/`
    * Standard matrix and vector operations, for fixed size and dynamically sized matrices and vectors.
    * Linear algebra routines (nullspace, pseudo-inverse, etc).
    * IO routines for printing `numpy` formatted arrays, etc.
    * Built as a thin set of extensions to FLENS.
  * ImageLibrary - `image/`
    * Image class, maybe built on the matrix library.
    * Image IO image.
    * Cached, stacked image processing. This is useful for, e.g., the KLT tracker.
  * CorrespondenceLibrary - `correspondence/`
    * Data structures for representing and manipulating correspondences between images
      * There are still many decisions to be made here; see BrainstormingOrganizationAndPlanning.
    * Algorithms for finding correspondences between images, either in a sequence or heterogeneous images.
      * KLT (video)
      * NCC (video)
      * SIFT (photos)
      * SURF (photos)
    * Probably will depend on `numeric`.
  * CameraLibrary - `camera/`
    * Camera models - projective, metric, linear push-broom, radia distortion, etc.
    * Camera calibration from calibration objects (determine focal length, lens distortion, etc) for higher-quality reconstructions.
    * Correcting known radial distoriton.
    * Depends on `numeric`.
  * ReconstructionContainerLibrary - `reconstruction/`
    * Containers for reconstructions.
    * Designing this part will be very tricky to get right, as there are many constraints.
    * `TODO(keir):` Figure out requirements for reconstruction library -- in place bundle adjust? Immutable?
    * IO for converting to other useful formats - e.g. blender.
  * RobustEstimationLibrary - `robust_estimation/`
    * A library for estimating relations from noisy data.
  * StructureFromMotionLibrary - `multiview/`
    * Algorithms for converting correspondences into motion estimates, either projective or metric. Most of the interesting parts of libmv will go here. This will depend on the robust estimation library.
    * Autocalibration
    * Computation kernels for multiview relations
      * Sixpoint NView
      * Two-view calibrated, uncalibrated.
      * Homography
    * Robust estimators for various relations using the `robust_estimation` code.
  * MinimizationLibrary - `minimize/`
    * Bundle adjuster - Fast minimization of large sparse nonlinear systems.
      * Designing a robust, scalable bundle adjuster is non-trivial but will be of value to many projects besides just libmv.
    * EM-fitting. This is used inside the old libmv1 robust fitting; we may not use it in libmv2.
  * EvaluationLibrary - `evaluation/`
    * A system for running experiments, comparing the quality of the results, and making plots showing how each reconstruction strategy compared to the others.
    * Ground truth loader. Probably only OpenEXR as produced by Blender for now.
    * Python scripts to run experiments. May be scons-based for fast re-running of experiments.
  * BlenderPatches - `../contrib/blender/`
    * Patches to blender to enable it to produce the ground truth data for image sequences it renders. Hopefully these can get into upstream blender so it is not necessary to patch blender to produce ground truth data.