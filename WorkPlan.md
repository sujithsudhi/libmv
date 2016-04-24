# Introduction #

There is an almost infinite amount of work that _could_ be on libmv. To keep focused on producing something useful, here is a plan to get to something that is _useful_, though perhaps not feature-complete, in the shortest time possible.

In rough order of dependence:

# Work plan #

## Basic matrix and vector functionality ##

  * ~~Fixed size arrays. 0.5 day.~~
  * ~~Variable sized arrays. 1 day.~~
  * ~~Dot product, outer product. 1 hour, without BLAS. 1 day using BLAS (not necessary at first).~~
  * ~~SVD - Use LAPACK. Not trivial. 1 day.~~

_We are going to use FLENS_.

  * ~~Check current CVS into libmv third\_party/~~
  * ~~Make super-simple wrapper for common operations inside libmv (i.e. typedefs for `DenseVector<FullStorage<double> >` as 'Vector', etc).~~
  * ~~Polish FLENS's existing support for tiny vectors.~~

See MatrixLibrary for other details.

## Image class and loading ##

  * ~~Simple image class built on a matrix. Supports images that own and don't own the underlying data. 1 day.~~ Finally 2 days; Pau codes like a turtle.
  * Load PNG images. 3 hours.
  * Load JPG images. 2 hours.

## Image processing and caching ##

  * Simple LRU cache for holding images. **DONE**.

## Correspondence Library ##

(not finished yet)