## TODO ##
  * Improve this reconstruction process. (remove all the TODO, write some reconstruction tests)
  * Handle lens distortions.
  * We need a projective bundle adjustment in order to minimize cumulated errors in the uncalibrated process
  * We also need a pose refinement process (calibrated/uncalibrated), and why not a structure refinement one.
For this three last optimizations, we cannot use ssba. Maybe we should have our own generic (pose|structure|bundle) nonlinear solver.
Besides, Eigen3 will provide an interesting nonlinear optimization module that we could use for this...
  * Switch to Eigen 3.
  * A better UI, with a 3D view should be nice too.
  * Update the wiki
  * Write some unit tests
  * Creates a GUI dedicated to videos (split nview)

<a href='Hidden comment: 
== Tracker ==
* ~~remove the useless template TImage.~~ -We will define a pyramid image tracker class.-
* replace the matcher pointer by an Enum.
* find a way to make the tracker class to be the owner of the detector/describer classes, keeping in mind that the user should be able to choose its detector/describer (+parameters) : _use template/functors ?_
* ~~find a solution to the Featureset delete issue:~~ _a structure/class with the matches and a vector/list of Features ?_
* only match the new featureSet with one of the descriptor (and not all) of known features : a feature has approximately the same descriptor in every images
* ~~make a robust Traker (epipolar filtering)~~ _see nvr, as a new  function/class ?_
* make a robust Traker for planar scene (homography filtering) _see nvr, a PlanarTracker class ?_
* add a parameter (?) to the feature detection in order to detect only the N best corners (proceed a feature filtering based on the features scores)
* add a prediction step (based on a 2D or 3D movement model)
* see the OpenTL architecture http://www.opentl.org/architecture.html

=== Image pyramid ===
* extend the Tracker in order to handle images pyramid (intra/inter-level features matching)
* how can we store the association of a feature with a pyramid level (and not an image)?

=== Masks ===
* add a mask system so that we can associate a mask to an image. Every feature detectors should then only detect features in the visible zone (window).
* add a mask system (?) in the matching process in order to handle predicted features (ellipsoid, rectangle, ...)

= SLAM (large scale) =

== References ==

- Mouragnon, _et al_, A visual real-time SLAM for large scale displacement, IVC"09

M. Lhuillier"s homepage: http://wwwlasmea.univ-bpclermont.fr/Personnel/Maxime.Lhuillier

- Hauke Strasdat, J. M. M. Montiel, and Andrew J. Davison: Scale Drift-Aware Large Scale Monocular SLAM , Robotics: Science and Systems, 2010 http://www.doc.ic.ac.uk/~ajd/Publications/strasdat_etal_rss2010.pdf

LGPL source code (mainly a sparse bundle adjustment): http://www.openslam.org/robotvision.html

== Overview ==
* Camera Tracking
* 2D Tracking
* Windowed tracker NxM px mask
* Local tracking (only track in the N last views)
* Robust pose estimation(resection)
* Linear pose estimation (3 or 5 points) + RANSAC (detect & remove outliers)
* Non-linear pose refinement
* Keyframe detection
* Enough correspondences in the N last views, enough inliers, ...
* Mapping (only for keyframes)
* Triangulation (intersection)
* Linear 3D points triangulation of inliers
* Refinement
* global/local Bundle Adjustment

= PTAM (small workspace) =

== References ==

Klein _et al_, A visual real-time SLAM for small workspace, ISMAR"07

PDF : http://www.robots.ox.ac.uk/~gk/publications/KleinMurray2007ISMAR.pdf

Slides : http://www.robots.ox.ac.uk/~gk/publications/Slides_KleinMurray2007ISMAR.pdf

G. Klein"s homepage: http://www.robots.ox.ac.uk/~gk/PTAM

== Overview ==

..a variant of SLAM.

* FAST-10 detector / Patch 8x8px based descriptor
* image pyramid (4 levels)
* a camera motion model
* 2D predicted features reprojection
* Affine warp patch (predicted "descriptors")
* coarse resection (reproject 50 best points)
* no RANSAC but M-estimator (Tukey) with 10 iterations WLS
* and various other stuffs
'></a>