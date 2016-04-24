# Currently working on #
  * The reconstruction data structure.
  * Simple guis for testing current code.


# To do #

  * Reconstruction structure
    * Define the FeatureSet, Structure, Reconstruction, ...
    * Fix Kd-tree implementation:
      * Avoid moving the original points
      * Add min/max bounds to nodes to correctly approximate the L2 distance when prunning
  * Autocalibration:
    * Two views: find what works best between Hartley, Sturm and Pollefeys (linear to find a 2d solution space + quadratic to fix the ambiguity).
    * ~~N-views: fix implementation of Pollefeys linear method~~
  * Two view reconstruction gui:
    * ~~Set up a basic application enabling to open 2 images~~
    * ~~Compute surf on each image~~
    * ~~Display surf detections~~
    * ~~Find candidate matches using kdtree~~
    * ~~Compute robust matches and fundamental matrix~~
    * ~~Compute cameras' internal parameters~~
    * ~~Compute metric reconstruction~~
    * ~~Visualize it~~
    * ~~Bundle adjust the metric reconstruction~~
    * Try Sturm04 method for estimating a common focal length
    * Add the images to the camera background image in blender
  * Simple gui for KLT tracking
  * Check if doxygen's output looks ok
  * Implement matrix fliping functions and use them in K\_From\_AbsoluteConic