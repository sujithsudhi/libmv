When I have time to spend on libmv, I plan out what I want to accomplish here and check things off as I go.

#### Saturday, November 15th, 2008 ####
  * Replaced FLENS with Eigen2.
  * Work on reconstruction data structure.

#### Saturday, July 26th, 2008 ####
  * Implemented start of correspondences data structure.
  * Still to do: rework KLT code to use new correspondences data structure.

#### Thursday, July 11th, 2008 ####
  * Added start of a bipartite graph class for storing correspondences and reconstructions.
  * Started writing tracker base class definitions.

#### Tuesday, July 9th, 2008 ####
  * Refactored GoodFeaturesToTrack().

#### Saturday, July 5th, 2008 ####
  * Write simple image convolution for blurring and image derivatives (needed for KLT).
  * Switch FLENS to zero-based indexing.

#### Friday, July 4th, 2008 ####
  * ~~Trivial image loading in Qt via libmv image class~~

#### Thursday, July 3rd, 2008 ####
  * ~~Switch to GTest instead of testsoon~~
  * ~~Write GEMM specializations for tiny matrices~~
  * Focal length estimation for fundamental matrix.

#### Wednesday, July 2nd, 2008 ####
  * ~~Add comma list initializers to TinyMatrix / TinyVector.~~
  * Focal length estimation from fundamental matrix via hartley's method.

#### Sunday, June 29th, 2008 ####

  * ~~Expand components page, by looking at libmv1.~~
  * ~~Based on the components, figure out a reasonable directory hierarchy.~~
  * ~~Update current code and build to follow the new structure~~
  * ~~Make third\_party directory, and check FLENS into it.~~
  * ~~Write ThirdPartyCode wiki page~~
  * ~~Make FLENS build inside libmv~~
  * ~~Figure out where to put FLENS-libmv tests~~
    * We will write unit tests for new functionality we add to flens, but inside the libmv unit test system. This is because FLENS unfortunately doesn't have a unit test system.
    * **Put them in `third_party/flens`, named the same way as other libmv tests.** See `tinyvector_test.cc`.
  * ~~Add copying between TinyMatrices and dense matrices to FLENS (I'll sync it upstream later).~~
  * Add comma list initializers to TinyMatrix / TinyVector.
  * ~~Add numerics directory, and write nullspace() function and tests.~~
  * Create structure-from-motion directory and add nview triangulation and tests.
  * ~~Put MIT license boilerplate on existing code.~~
  * ~~Write page about tracking, summarizing the notes I made at ICVS2008~~
  * ~~Upload old tracking examples from my defense to YouTube, and link to them from the front page~~.

#### Saturday, June 28th, 2008 ####

  * Wrote simple tiny and dynamic matrix/vector library (with tests!).
  * Realized FLENS is better, so just use that.
  * Wrote several wiki pages (WorkPlan, MajorComponents, MinimizationLibrary, etc)
  * Switched to MIT license.

#### Even older stuff ####

[Old log](http://wiki.blender.org/index.php/User:Keir/TrackingDiary) from when I was writing my thesis.