# Introduction #

This page describes our needs for the nonlinear least square (SfM dedicated) library.

We need to have our own sparse BA and even more: we need a custom optimization lib, including a BA.
We can build it on the top of Eigen3'snonlinear and sparse modules (not yet stables, but working?)!

# Functionalities needed #
  * optimize the cameras parameters only (pose optimization: one camera or several, intrinsics and/or extrinsics with/without distortions, maybe using different parametrization of angles etc.)
  * optimize structure parameters: we currently use 3D points but one day we will handle lines for instance
  * a BA with numerical and analytical derivatives
  * a sparse BA since we need to be able to optimize thousand of cameras!
  * a BA that can easily accept constraints for stereo vision, partly fixed scene, etc.
  * we can even think about an extension to generic camera too (catadioptric, fisheye, etc.). Instead of minimizing the reprojection error we may support rays.
  * ...

# Implementation details #

## How to do ##
  * Where: in _src/libmv/mutliview_
  * Dependencies: no. (maybe camera)
  * Parameters: vector only? matrices?

## Possibles signatures ##
  * Camera(s) only
    * `OptimizeCamera(Vec12 *cam)`?
    * `OptimizeCamera(Mat43 *cam)`?
    * ...
  * Structure(s) only
    * `OptimizeStructure(Vec *structure)`
    * ..
  * Cameras and Structures (Bundle Adjustment)
    * `BundleAdjust(...)`
    * ...

## Internal classes ##
Re-use the same structure than for 2D/3D homography optimization (parameterization, errors, jacobian)

  * Camera parameterizations
```
// Pinhole camera
class PerspectiveCameraParameterization;
class AffineCameraParameterization;
class ProjectiveCameraParameterization;
// Others -> rays
...
```
  * Structure parameterizations
```
class EuclideanPointParameterization;
class HomogeneousPointParameterization;
class LineParameterization;
...
```
  * Projection errors
```
// Pinhole camera
class GeometricError;
  static double Error(const Mat34 &P, const Vec &X, const Vec &x) 
  static void Residuals(const Mat34 &P, const Mat &X, 
                        const Mat &x, Mat2X *dx)
class AlgebraicError;
  static double Error(const Mat34 &P, const Vec &X, const Vec &x) 
  static void Residuals(const Mat34 &P, const Mat &X, 
                        const Mat &x, Mat3X *dx)
// Others -> rays
```
  * Jacobians (== pair parametrization, error)
```
struct ProjectionJacobian <PerspectiveCameraParameterization,
 GeometricError>{
  Jacobian(Vec &x, Vec &Q, Vec2 &q,
                   Vec *jac_x, Vec *jac_y) {
    ...
  }
}
```