Libmv aims for two goals:

  * Be the best open source match moving and 3D reconstruction tool.
  * Be a useful tool for research in structure from motion and 3D reconstruction.

These goals align nicely. In order to be come a great research tool for reconstruction, the library must first be good at reconstruction and matchmoving. Then, for research, tools for analysis can be added.

# Use cases #

## Bob ##

Bob is a special effects artist. He has some HD footage where a camera moves around a cathedral, and he needs to insert a ghost character. Bob loads blender, clicks 'matchmover', and opens his video. He clicks 'automatic track', and waits for a minute while the video is processed.

The video didn't track perfectly, so he scrubs the video and finds a faulty track introduced by a cat running through the scene. He deletes these tracks, and hits 'resolve'.

The scene solves successfully. Upon returning to blender, the scene has a camera with appropriately set focal lengths and keyframes, as well as a 3D point cloud where the tracks were. Bob proceeds to insert rendered elements into the scene, and makes his deadline.

## Andrew ##

Andrew is a structure from motion researcher. He has an idea for a new method for autocalibration (converting from a projective to a metric reconstruction). He wants to evaluate it against the other state of the art algorithms.

Andrew builds libmv and reconstructs a simple scene to make sure it works. Then, Andrew writes his new method as a new strategy for autocalibration inside libmv, and plugs it into the solver as a new autocalibration method. Since there are lots of examples and the code is well written and documented, this is straightforward for Andrew to do. Andrew even adds a unit test, because it's very straightforward to test numeric code inside libmv.

Then, Andrew makes a new libmv evaluation script by copying one of the examples. He adds a section that causes reconstructions to be built with his new autocalibration method in addition to the other methods already in libmv. The script does many complete reconstructions (images to point clouds in this case). The reconstructed scenes are part of libmv, and include ground truth.

In the morning, Andrew looks at the figures and plots automatically generated from the reconstructions, and determines that his new method handily beats existing autocalibration methods both in computation speed and reconstruction quality, but only when the focal length is fixed for all images.

Andrew is pleased that he did not have to implement the many details required to do a complete reconstruction in order to evaluate his new autocalibration method. _Andrew is able to go from algorithm idea to functioning code and full evaluation in a production quality reconstruction system with convincing test scenes in days. His paper is ready the following week._