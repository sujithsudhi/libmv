libmv needs a serialization library of some sort.

### Constraints ###

  * Python and C++ compatible.
  * Fast.
  * Can link with blender.

### Possibilities ###
  * JSON
    * I (keir) already have a nice implementation.
    * It's clean, and has unit tests.
    * But is slow.
  * Protocol Buffers
    * Great to work with
    * Blazing fast
    * Python bindings.
    * Apache Licensed - Blender incompatible (grr).
  * Yaml?