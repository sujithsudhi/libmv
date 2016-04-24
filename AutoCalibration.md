# Introduction #

We discuss here about auto-calibration algorithms, and list the ones that are or will be implemented.


# Two-View Methods #
All two-view methods assume that the principal point, aspect ration and skew are known, at least approximately.  The main differences between the methods are whether they assume constant focal length or not, and the size of their critical configuration space.

The problem is unsolvable, by any technique, when the optical rays of the cameras are parallel or if they intersect at a finite point equidistant from both optical centers [2004](Sturm.md), and can be expected to be very unstable in configuration close to these ones.  These are very common situations.


## Constant Focal Length ##
  * Sturm 2004, probably the one with the smaller critical configuration space.  Should be implemented and tested soon.

## Variable Focal Length ##
  * Hartley 1992.  Its critical configuration are the pairs of cameras with crossing viewing rays, regardless of where the intersection happens.  It is implemented in `focal_from_fundamental.h`.
  * Pollefeys 1999, linear to find a 2d solution space + quadratic to find the correct solution in this space.
  * Pollefeys 2004, the same as above but with soft constraints on the principal point, aspect ration and skew parameters.



# N-view Methods #

## Constant Camera Parameters ##
  * Triggs 1999

## Varying Camera Parameters ##
  * Pollefeys 2004 linear, implemented in `autocalibration.h`, but not working yet.
  * Pollefeys 2004 non-linear.


# References #