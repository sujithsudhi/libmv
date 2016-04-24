# Introduction #

In the world of numeric processing, there are (unfortunately) many choices for matrix and vector classes. For libmv, there are two choices: use an existing matrix/vector library, or invent our own.

**Update November 2008: We switched to Eigen2; no more LAPACK or ATLAS dependencies; more readable code; better performance; and most importantly no custom libmv changes necessary!**

## Core functionality requirements ##

The library must:

  * have a concise, readable API.
  * be efficient for small, fixed size vectors and matrices (2-5D).
    * Fixed size vectors/matrices should have zero storage overhead.
  * support runtime-sized vectors and matrices.
  * be understandable to mere mortals.
    * This means use template metaprogramming only when really necessary.
  * be commercial friendly (BSD, Apache, or otherwise).
  * it must have automated tests.

## Linear algebra ##

There must support:

  * Matrix-vector product, inner product, outer product.
  * Matrix inversion.
  * SVD.
  * Others as needs arise.

## Existing candidates ##

### TooN ###
Looks quite good. TooN was built to support vision-type applications, so it is already implements most of the functionality we need. The code is also mostly straightforward and understandable.

Unfortunately, the license is currently incompatible (effectively GPL). We are in discussions with the authors about possible license modifications.

### LTL ###
[Little Template Library](http://www.mpe.mpg.de/~drory/ltl/index.html) looks excellent, if a bit heavyweight. However, it is GPL and the authors have no intent to change it, so it is excluded.

### tvmet ###

[http://tvmet.sourceforge.net/](tvmet.md) does not support dynamically sized arrays or vectors, so it is excluded, though forking it is not impossible. Also, it is unmaintained.

As an interesting note, tvmet [had adoption problems related to its LGPL license](http://tvmet.sourceforge.net/license.html). Templates and LGPL do not play well together.

### Eigen 2 ###

[Eigen2](http://websvn.kde.org/branches/work/eigen2/) is part of the KDE project. However, it has unacceptable compile speed problems because of it's extreme use of template metaprogramming. Furthermore, eigen2 has a 'pure' mathematics bent, which results in an awkward API that doesn't offer all the functionality required for practical numeric applications.

**Update: Eigen2 has come a long way. In particular, there are now more array-type functionality and (most importantly) allows us to drop dependence on LAPACK, BLAS, and ATLAS. This is libmv's new library.**

### ublas ###

ublas is the matrix and vector class offered by boost. ublas was used in libmv1. From an API perspective, ublas is not so bad after a bit of wrapping and typedeffing. However, the code could be conservatively described as outrageously over complicated.

Also, ublas has the problem that it is impossible to make ublas vectors and matricies that do not own the underlying data (for obscure reasons I can't recall anymore).

A hackable library is important; ublas is pretty opaque and hard to hack.

### VXL matrix libraries ###

Extracting the vxl numeric code would require about the same amount of work as writing new libraries from scratch. Furthermore, with modern C++ techniques it is possible to mix fixed size and dynamically sized vectors/matrices.

### Imath libraries from OpenEXR ###

There is a nice matrix / vector implementation in OpenEXR 1.2.x, which was removed in later releases. It has a clean design, though it is not designed for small fixed size matrices.

The separation of vector operations from storage makes the code both understandable and flexible. See [TMatrixBase](http://google.com/codesearch?hl=en&q=show:hRmRQbamX2M:cE-9HYhgC4U:K7_MOf0VtIM&sa=N&ct=rd&cs_p=http://www.angstrom-distribution.org/unstable/sources/cinelerra-2.1-src.tar.bz2&cs_f=cinelerra-2.1/OpenEXR-1.2.1/Imath/ImathTMatrixBase.h&start=1).

### FLENS ###

[FLENS](http://flens.sf.net) is a numeric toolkit which aims to offer intuitive syntax, while still calling the underlying BLAS routines.

FLENS has very readable code, and already links to the LAPACK routines needed for libmv.

## Conclusion ##

~~We build our own, heavily borrowing from the techniques in TooN to support fixed~~

~~We use FLENS. It's really great. It's hackable. It's fast. It has sparse matrix support too, and block-sparse support soon. It's license is compatible with the MIT license (it's BSD-style).~~

FLENS required too many local changes, and had an API that is too low level. Eigen2 is our new library.