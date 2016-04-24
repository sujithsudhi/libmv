For now, this is brainstorming about the requirements.

# Tracking video #

## Requirements ##

The tracker library in libmv must be flexible and easy to extend. It must
support more than point trackers (though maybe not at first). The problem
breaks down into three parts: Finding distinctive points, tracking them, and
representing correspondences.

### Finding distinctive points ###

When there are no trackers in the first frame, it is necessary to search for
distinctive points. This is usually done with the harris corner detector or
similar techniques. When too many trackers drop out, more points to track need
to be found.

It must be possible to use different initialization strategies. It must be
possible to feed in current trackers to the initialization, so that areas with
many trackers are skipped (saving time). Another strategy would be to feed
masks to the feature finder. The feature finder would ignore areas under the
mask. This will be necessary anyway for garbage masking in scenes with actors.

### Tracking correspondences ###

There are many techniques for finding correspondences across video frames. The
simplest approach is to take an image patch from the first frame and search for
it in the second, by minimizing some error function (usually sum of squared or
absolute errors).

The different techniques have different performance profiles in terms of
computation cost and tracking accuracy. libmv must support multiple trackers
(though not at first).

The following trackers should be implementable with the eventual design:

  * KLT - Standard SSD KLT tracker, with translation, rotation, or affine.
    * I (Keir) have some ideas of how to make this wicked fast by using an integer only approximation.
  * [Joint KLT](http://www.ces.clemson.edu/~stb/research/jointtracking/) - KLT + global movement smoothness constraint.
  * UKLT - Uses 5 other trackers underneath.
  * NCC - Standard translational tracker, using super fast FFTW.
  * GRIC - A new idea I (Keir) have: use model selection to compares translation, translation+rotation, and general affine warp trackers (3 of them) to find the best model. Could be composed into UKLT!
  * [Interactive tracking with kd-trees](http://www.robots.ox.ac.uk/~amb/docs/buchanan06interactive.pdf).
  * [This paper due to Fitzgibbon & Buchanan](http://www.robots.ox.ac.uk/~amb/docs/buchanan07combining.pdf), which applies a global smoothness constraint on the motion of trackers, resulting in stable tracks.
    * This will be challenging, because it involves trackers that are not independent.

All of these are 2D point trackers.

##### Design constraints #####

There are several constraints for the design of the tracking system:

  * It must be possible to draw each of the different trackers, in a way that their internal state is visible. For example, for the UKLT the uncertainty bubble must be drawn.
    * A reasonable solution would be to have a virtual method that takes a cairo context, and allows the tracker to draw itself. That would work with OpenGL and support writing images out to disk.
    * Though it is ugly to mix drawing code with tracking algorithms!
  * The details of each track and the interal state for the particular algorithm must be exportable to a file for later analysis (i.e for making plots for publication).
  * It must be possible to have different kinds of trackers at the same time.

One thing that I (Keir) want to experiment with is 'composable' trackers, where
trackers are made out of other trackers (for example a square or rectangle
tracker made out of four corner trackers and four line trackers). The design
should not make that impossible. At the least I would like to eventually
support:
  * Point tracker
  * Edge tracker
  * Line segment tracker - Combination of point and edge trackers.
  * Quadralateral - composite of segment trackers.

##### Image processing #####
For interactive tracking, there needs to be a cache system which lazily loads
and (for KLT) makes image pyramids. The trackers can be tied to it.

There is already a cache in the codebase, but a filtering framework is not
present.

## Overall strategy ##
For an overall tracking strategy, something like the following might work.
  * Make a PointFeatureFinder instance.
  * Pass a factory function for whatever tracker you want to use to the PointFeatureFinder. This way it can directly construct trackers.  The factory function can use config info to chose a particular tracking strategy.
  * When too many trackers drop out, run another PointFeatureFinder and pass it either a mask for areas not to look at, or the current trackers.

It would be good to have a separate class to handle tracking over many frames. It will
compose a feature finder with other trackers. It can take pairs of feature
finder and tracker factory function, so that it can blindly track lines, points,
and others without knowing about the particular tracker representation.


# Photos #

Tracking features in unordered sets of images can not be done with the previous approach because of the following reasons:
  1. There is no inherent order in the image set.  Thus, every image should be potentially matched with any other image.
  1. The feature positions can be very different in different images.  Thus, searching a feature in one image requires exploring very large regions.
  1. The feature appearance can be very different in different images.  Thus, comparing image patches is not robust enough.

The solution to these problems are the following:
  1. Try to find correspondences between every pair of images and then link the pair-wise matches into tracks.
  1. Instead of detecting features in one images and doing a local search in the other, a more global search approach is used:  detect features in both images, then find correspondences between the two sets of features.
  1. Use robust and discriminative descriptors.  For points these can be SIFT, SURF, or others.

Although it may look more complicated that tracking in a video sequence, once you have a feature detector and descriptor, it is actually very simple since matching reduces to descriptor vector comparison.  There is no image to image comparison.

## Uses of the unordered approach for video tracking ##

Since the approach is generic, it also works for video sequences.  Of course, it is much slower than standard tracking, and it can not be used blindly to track long video sequences.  Nevertheless, there are some ideas of this methodology that can be useful for motion tracking video sequences:
  * When camera shake is important, extracting features in both images can improve the matching since we no longer rely on the hypothesis of small motions.
  * For long video sequences, where the same parts of the scenes appear multiple times, matching every pair of images can improve the quality of the reconstruction and avoid multiple tracks of the same real point (it closes the loop).
  * Multiple video sequences can be tracked at once improving the overall quality and yielding coherent relative camera poses.
  * Still images can be combined with the video to help the structure from motion algorithms in the case of degenerate camera motions.  These will be useful in cinema where the director will be free to choose the camera motion independently of the motion track requirements (right now, camera movements are chosen such that camera tracking works).



# GUI interaction #

Since GUI interaction is important for reconstruction, whatever data structures we pick must be amenable to visualization and interactive manipulation (i.e. what happens if a user clicks a track and moves it half way through? Should the sequence after the user adjusted the tracker position be re-tracked?)