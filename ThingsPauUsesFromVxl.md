# Introduction #

VXL is huge.  It has a lot of useful functionalities, and a lot of useless too.  Here is a list of the functionalities that are currently used in Pau's code, or that could be useful in the future.


# VIL #

  * reading and writing multiple image file formats.
  * interpolation
  * convolution

**Alternatives:**
  * Image class template, interpolation and convolution can be reimplemented without much effort, but reimplementing reading and writing is more tedious.
  * Maybe OpenCV's IplImage could be used, but it looks far less usable.
  * CImg is a nice image library but loading and writing are done through imagemagic's `convert` command and is terribly slow.
  * GIL could also be considered.


# VNL #

  * Fixed size matrices and vectors.
  * General size matrices and vectors.
  * A lot of linear algebra stuff using linpack, which seems to be slower than Lapack.  Migration to Lapack is on VXL's TODO list.

**Alternatives:**
  * uBlas has nice general size matrices and Lapack based linear algebra.
  * Fixed size matrices could be reimplemented, but it will take time.


# VCL #
  * Aparently STL is not working on all of the existing compilers.  VCL is a wraper around STL that ensures that it works.

**Alternatives:**
  * On linux STL works, so it can be used directly.  This is actually what happens when you use VCL on linux, STL is used instead.


# OXL/MVL #
  * The Oxford's Multi-View Library has code for estimating fundamental matrices with RANSAC and MLESAC, and some other stuff.

**Alternatives:**
  * This should definitely be reimplemented since OXL/MVL is old, unfinished, undocumented and no longer developed.