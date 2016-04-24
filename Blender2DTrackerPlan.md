**Note: The content of this page has moved to [the Blender wiki](http://wiki.blender.org/index.php/Dev:Source/Blender/Projects/MotionTracker2D). However, please make comments here because the Blender wiki doesn't have a comment system (and the comments don't get mirrored to the libmv list).**

# Objective #

Bring simple 2D tracking capabilities to Blender.

# Goals #

  * Support semi-automatic tracking of video in blender, such that rendered items can match the movement of moving elements in a video.

### Non-goals ###
  * Automatic selection of track points.
  * Any kind of 3D support (that's for later). The tracking will only be useful for things moving in the video plane.
  * Tracking anything other than points (for example, no line tracking).

# Only 2d? #

The primary goal of libmv is to create a full matchmoving component for Blender. However, a matchmover is a large project. Creating a full matchmover and integrating it with a single massive merge is likely to cause headaches for all involved. A better approach is to build the functionality incrementally.

While there are many parts in a matchmoving program, most of them naturally fall into two categories: 2D and 3D. Before moving to a 3D reconstruction, first 2D tracks must be made of the video to be reconstructed. There are a variety of ways of tracking in 2D. The most basic method is manual tracking, where in each frame the tracked point is moved by the user into the right position. This method works, but is laborious. At the more advanced level, there are automatic methods that use image information (such as a distinct marking on a car) to track something on the screen. In between, there are semi-automatic methods where the user guides the automatic tracking process.

Some example uses of 2D tracking without 3D:

  * [2D tracking with after effects](http://www.youtube.com/watch?v=tHkWOFqFpZo&feature=related)
  * [More 2D tracking with After Effects](http://www.youtube.com/watch?v=ckbJ_FPBQBQ&feature=related)
  * [Commercial using both 2D and 3D tracking to insert text](http://www.youtube.com/watch?v=zTC0aVT2Ogc&NR=1)

To see a possible 2D tracking interface, check out these tutorials from syntheyes.

  * http://www.ssontech.com/content/trkintro.htm
  * http://www.ssontech.com/content/lookdark.htm

# Proposed usage #

Here's what I suggest for workflow. I'd like for experts in blender or in tracking to comment on this.

  * Open blender.
  * Open the video to track and select it.
  * Open the tracking dialog
    * Select the 'add tracker' button.
    * Click on something to track (e.g., a person's nose)
    * A small box is placed around the track point, indicating that the tracker is placed.
    * Click the 'track across frames' button and watch the tracker move with the object in the video.
    * Scrub through the video; note that on frame 25 the tracker gets lost
    * Drag the tracker to the correct position in frame 25
    * Advance to frame 26, and correct the position again.
    * With the tracker selected, press 're-track selected' in the tracker dialog. Watch as the tracker tracks correctly through the remainder of the sequence.
  * Click the 'export tracks to empties and make camera' button, which recreates the scene in blender. The track becomes an empty with IPO curves to make its movement match the scene movement. The camera is static, but positioned so that it the empty projects to the same position it is in the video.
  * Switch to 3D view, make a monkey.
  * Parent the monkey to the empty that was created by the tracker.
  * Compose the render with the video; render; watch the monkey move around with the video (in 2D!)

There are a number of open question.

  * Where do the data structures for the tracker live? On one hand, they can probably be normal blender objects if tracking is a one-shot process where the movie is tracked, and the results baked out to empties, with no support for saving the intermediate tracks. Alternately, it would be nice to support editing the tracks after they are put into 3D. I am not sure what the right approach is here; comments from blender coders welcome.
  * Should the compositing steps be done automatically to make it easier for new users?
  * Where should the tracker dialog go? Should it be a dialog or a new button panel?
  * Should there be a separate tracking window which shows the video, the trackers, and the scrubber?
  * Syntheyes shows a closeup of the selected tracker to make it easier to manually adjust a tracker. This is a great idea, we should do the same. But where should this go? In the button panel?
  * Is this the most useful functional subset of 2D tracking?
