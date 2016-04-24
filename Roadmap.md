Content

## Introduction ##
We're going to release libmv and need to know which features are needed for which release.

The basic idea is to have something like this:

**Libmv 0.x:**
  * Initial match moving algorithms with known camera intrinsics
  * Unstable API

**Libmv 1.0:**
  * **Targeted application**: Matchmoving
  * Efficient match moving with known camera intrinsics (automatic tracking + 3D estimation)
  * A simple video stabilization
  * Stable API + Complete Unit tests

**Libmv 2.0:**
  * **Targeted application**: Unordered image reconstruction (ala Bundler)
  * Reconstruction from an unordered image set
  * Generic Bundle Adjustment library (ala SBA/SSBA [BundleAdjustment](BundleAdjustment.md))
  * Match moving with unknown camera intrinsics?
  * Libmv 2.0: Stable API + Complete Unit tests

**Libmv 3.0:**
  * **Targeted application**:  Dense 3D reconstruction (+clustering?) (ala PMVS/CMVS)
  * Dense 3D reconstruction
  * Image super-resolution/gigapixel?
  * Image clustering (ala cmvs)?

The **next major release will be 1.0** and **packages will be made**.

Before this release, we will produce several unstable versions (0.Y), where Y will be increased each time that a major feature reaches the **DONE** state.

## Features and Todo list ##

### Version 1.x ###

| **Component** | **Feature Description** | **Priority** | **Who**`*` | **Comments**  | **Target** | **Status** |
|:--------------|:------------------------|:-------------|:-----------|:--------------|:-----------|:-----------|
| reconstruction | General calibrated reconstruction from video  | high         |  julien    |               | 1.0        | GOOD       |
| reconstruction | Keyframe selection method   | high         | julien     |               | 1.0        | GOOD       |
| correspondence | Write tracker unit test  | high         | julien     |               | 1.0        | STARTED    |
| camera & tool | Lens distortion correction | high         |            | _need full tests + move to camera lib_  | 1.0        | GOOD       |
| reconstruction | Write reconstruction unit test  | medium       |julien      |               | 1.0        | STARTED    |
| reconstruction | Robust initial reconstruction, 2 views   | medium       | julien     |               | 1.0        | GOOD       |
| multiview & optimization | Camera optimization (euclidean) | medium       |            | _needs parameterization, error, jacobian, optimization_  | 1.0        | STARTED    |
| multiview & optimization | Point structure optimization (euclidean) | medium       |            | _needs parameterization, error,  jacobian, optimization_  | 1.0        | STARTED    |
| general       | Make libmv build for Mac OS  | medium       | vess/marco |               | 1.0        | **DONE**   |
| general       | Packaging scripts using CPack  | low          |            | _linux: done, win:done, mac: todo_  | 1.0        | GOOD       |
| general       | Make a documentation rule using cmake (doxygen) | low          |            | _in src/CMake/Documentation.cmake_  | 1.0        | **DONE**   |
| general       | Make libmv examples     | low          |            |               | 1.0        | TODO       |
| general       | Make a changelog        | low          |            |               | 1.0        | **DONE**   |
| third parties | Installation rules for third parties (headers) | low          |            | _to be tested in mac_  | 1.0        | GOOD       |
| tracker/correspondence | Adapt the tracker for marker (patch/color) based tracking | medium       |            | _for greenscreen environment_  | 1.0        | TODO       |
| tracker/correspondence | Fast window traker      | low          |            | _circle:draft, ellipse:todo_  | 1.0        | DRAFT      |
| tracker/correspondence | Guided traker (with tracks prediction) | low          |            |               | 1.0        | TODO       |
| contrib       | Define/rewrite interfaces with Blender | low          |            |               | 1.0        | TODO       |
| tracker/correspondence | ImagePyramid tracker    | low          |            |               | 1.1        | STARTED    |
| tool          | Video stabilization (fixed camera)  | low          |            | _need Homography optimization_  | 1.1        | DRAFT      |
| tool          | Video stabilization (moving camera)  | low          |            | _same as fixed camera with a lowpass filter on the 2D motion estimation (as a start)_  | 1.1        | TODO       |
| camera        | Lens distortion estimation (using lines/grid) | medium       |            |               | 1.1        | TODO       |
| tracker/correspondence | Re-tracker: use apriori tracks (user defined) to enhance the tracking | low          |            |               | 1.1        | TODO       |
| camera & tool | Rolling shutter correction / calibration? | medium       |            | _affect most of the CMOS cameras_  | 1.2        | TODO       |
| tracker/correspondence | F+H traker [Torr98](Torr98.md) | low          |            | _useful when bad structure/motion_  | 1.2        | TODO       |


### Version 2.x ###

| **Component** | **Feature Description** | **Priority** | **Who**`*` | **Comment**  | **Status** |
|:--------------|:------------------------|:-------------|:-----------|:-------------|:-----------|
| reconstruction | Reconstruction of an Images set | high         |            |              | 2.0        | TODO       |
| optimization  | Nonlinear Optimization library  | high         |            | _see [BundleAdjustment](BundleAdjustment.md)_  | 2.0        | TODO       |
| reconstruction+multiview | 3D metric rectification (self-calibration)| medium       |            |              | 2.0        | TODO       |
| reconstruction+multiview | 3D metric rectification from a priori (distances, perpendicular lines, etc.) | low          |            |              | 2.0        | TODO       |
| multiview     | Camera optimization (projective)   | medium       |            | _see [BundleAdjustment](BundleAdjustment.md)_  | 2.0        | TODO       |
| multiview     | Point structure optimization (projective) | medium       |            | _see [BundleAdjustment](BundleAdjustment.md)_  | 2.0        | TODO       |
| multiview     | F/E (fundamental/essential matrices) optimization  | medium       |            | _see [BundleAdjustment](BundleAdjustment.md)_  | 2.0        | TODO       |
| ui/nview      | Read the focal length (in px!) from Exif data | medium       |            |              | 2.0        | TODO       |
| reconstruction | General uncalibrated reconstruction from video | medium       |            |              | 2.0        | TODO       |
| multiview     | Point/patch normal estimation | medium       |            |              | 2.0        | TODO       |
| reconstruction | 2D image rectification from a priori (distances, perpendicular lines, etc.) | low          |            |              | 2.0        | TODO       |

### Version 3.x ###

| **Component** | **Feature Description** | **Priority** | **Who**`*` | **Comment**  | **Status** |
|:--------------|:------------------------|:-------------|:-----------|:-------------|:-----------|
| libmv         | 3D dense reconstruction | high         |            | _plane sweep?_  | 3.0        | TODO       |
| tool          | Image super-resolution  | low          |            |              | 3.0        | IDEA       |
| tool          | Image Gigapixel         | low          |            |              | 3.0        | IDEA       |
| tool          | Image mosaicing         | low          |            | _mosaicing of video:draft_  | 1.2        | DRAFT      |

### When we have time ###

| **Component** | **Feature Description** | **Priority** | **Who**`*` | **Comment**  | **Status** |
|:--------------|:------------------------|:-------------|:-----------|:-------------|:-----------|
| third parties | Switch to Eigen 3       | high         | julien/pierre |              | **DONE**   |
| third parties | Use a serialization lib (libjson?) | high         |            |              | TODO       |
| general       | Online API documentation | medium       |            | _in doc/_    | TODO       |
| correspondence | Rewrite the BipartiteGraph (in bipartite\_graph\_new.h)| medium       |            |              | DRAFT      |
| multiview     | 3D linear Similarity, Affine, Homography transformations estimation from corresp. (+robust) | medium       |            | _robust:TODO + fix bug in affine 3D (see unit tests)_ | GOOD       |
| multiview     | 2D/3D E, S, A, H transformations optimization | medium       |            | _parameterizations:done, jacobians:todo, opt:todo_ | STARTED    |
| multiview     | 2D/3D E, S, A, H transformations estimation without corresp. (+robust) | low          |            | _need only ICP!_ | TODO       |
| detector      | Lines/edges detection   | medium       |            |              | TODO       |
| wiki          | Update the wiki!        | medium       |            | _update outdated pages_ | TODO       |
| third parties | Update third parties (glog, gflag, etc.) | low          | vess/julien | _in /branches/new\_gflags\_glog\_dasy, glog:todo_ | GOOD       |
| general       | Use Eigen 3 [new features](http://eigen.tuxfamily.org/dox/TutorialGeometry.html) such as Orientation2D, Affine3f, etc. | low          |            | _define in numeric and use in multiview_ | TODO       |
| correspondence | Plane tracker (for plane based augmented reality) | low          |            | _need tests+UT_ | GOOD       |
| robust\_estimation | Create a robust estimation folder (lib?) | low          |            |              | TODO       |
| robust\_estimation | Add PROSAC robust estimation | low          |            |              | TODO       |
| robust\_estimation | Add GroupSAC            | low          |            |              | IDEA       |
| tools         | Camera calibration tool | low          |            |              | TODO       |
| ui/nview      | A 3D view for nview     | low          |            |              | TODO       |
| general       | Udate all comments to doxygen style | medium       |            |              | TODO       |
| general       | Make libmv build with mingw  | low          |            | _problem with pthread_ | TODO       |
| multiview     | 3D/2D Translation, Rotation (only) estimation from corresp. (+robust, +opt) | low          |            |              | TODO       |
| wiki          | Merge [Roadmap](Roadmap.md) with [FeaturePlan](FeaturePlan.md) | low          |            |              | **DONE**   |
| wiki          | Merge [MajorComponents](MajorComponents.md) with [StartingGuide](StartingGuide.md) | low          |            | _everything is in [StartingGuide](StartingGuide.md)_ | **DONE**   |

### To be decided ###

| **Component** | **Feature Description** | **Priority** | **Who**`*` | **Comment**  | **Status** |
|:--------------|:------------------------|:-------------|:-----------|:-------------|:-----------|
| general       | [PCL](http://pointclouds.org/) integration | medium       |            | _for ICP + 3D registration without corresp., + dense 3D point set_ | IDEA       |
| third parties | Remove pthread?         | high         |            | _it was need by gflags or so_ | IDEA       |
| correspondence | KLT: make it use the new components? | low          |            |              | IDEA       |
| general       | Switch to mercurial/git? | low          |            |              | IDEA       |
| general       | Project management tool (Redmine?) | low          |            |              | IDEA       |
| general       | Python binding          | low          |            |              | IDEA       |

`*`_Feel free to add yourself!!_

**Status convention**
  * IDEA: not yet fully discussed
  * TODO: not yet implemented
  * STARTED: an initial implementation has been started (in the SVN or not)
  * DRAFT: a first version of the feature is in the SVN
  * GOOD: an advanced version of the feature is in the SVN (it works but may contains bugs)
  * **DONE**: the feature is done and has unit tests and documentation