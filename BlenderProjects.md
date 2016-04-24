# Introduction #

One of toughest parts of reconstruction is that ground truth is rarely available for real scenes. Researchers are left with two choices for evaluation: laser range data or synthetic scenes.

Synthetic scenes are good for evaluation because they have perfect ground truth. The only problem is that the synthetic scenes that are used in evaluations are usually not convincing (i.e., if one were to look at example images from the sequence in a paper, one does not think 'oh, that's a photo', one instead thinks 'look at that 1980's computer generate image!).

By extending blender to accurately simulate real camera systems, we plan to produce high-quality ground truth data for evaluation.

If you want to work on any of these, please contact the mailing list with your plan, so we can avoid duplicating work. If you take on any of these projects, create a page describing your plan in the wiki, and to it from here.

# Projects #

## Add a physically-motivated CCD noise node to Blender ##

A valuable contribution to blender would be a node that takes the pixel-perfect
imagery created by rendering and dirties it with simulated CCD noise. This is
valuable to libmv, because it would allow synthetic sequences to be created
which more closely model the real world imagery the algorithms in libmv are
supposed to operate on.

## Add a physically-motivated chromatic aberration node to Blender ##

Another valuable addition is chromatic aberration. This is also known as
'purple fringing' in images where there is, for example, tree branches against
a cloudy sky. The edges of the branches have purple fringes due to the light
for different wavelengths of light bending slightly differently when it
encounters the camera lense.

## Make better data sets for evaluation ##

Artists! We need you to make compelling synthetic imagery. Already one member
of the community has created a blender scene which is far better than the silly
test scenes created by me (Keir). _(TODO(keir): Add link to ibkanat's work)._

Because the project is focusing on vision, we need the most realistic scenes
possible that simulate real cameras, and real camera **flaws**. There are two
parts to this.

  * Creating compelling scenes at the modelling, texturing, and lighting level.
  * Adding convincing elements of real cameras (CCD noise, chromatic abherration, radial distortion, etc).