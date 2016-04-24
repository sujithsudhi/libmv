# A retrospective on libmv 1.0 #

I (Keir) learned a fair amount about developing semi-large programs (20,000
lines of code) while writing the first version of libmv. Some parts worked out
well, others did not.

## Things that worked in libmv 1.0 ##

  * JSON serialization format was quite handy for interoperation with Python.
  * Google gflags is a great system for handling command line flags for the utilities.
  * The flexible RANSAC framework was pretty neat.
  * The configuration system was clever and relatively clean.
  * The testing system, developed late in the process, which used Python to generate test data and then convert that into ublas arrays for testing against was really quite nice.

## Lessons learned from libmv 1.0 ##

  * The JSON format could have used a more thorough design rather than organic growth.
  * Flags are only good for utilities, because they are globals. This means that for a library something different needs to happen (where multiple invocations of a library function may use different config values).
  * The RANSAC system needs to be broken up into more collaborating classes rather than the single-inheritance model used currently. This would also allow easier testing via dependency injection.
  * Need to build a better experimentation platform to make reproducibility easier. This was working in 1.0, but was still too ad-hoc.
  * Don't violate the Liskov substitution principle.
  * Don't inherit from standard containers (see Liskov above).
  * For vision applications, an interactive GUI is important for exploring how reconstuction is working.
  * Not enough focus on testing. I did testing for many components, but not all of them. Also, I did not have any testing for the reporting code (which was in Python) or any tests for the whole pipeline.