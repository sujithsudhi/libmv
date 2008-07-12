// Copyright (c) 2007, 2008 libmv authors.
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

#include <iostream>

#include "libmv/image/image.h"
#include "testing/testing.h"

using libmv::Image;

namespace {

TEST(Image, Sizes) {
  Image<int> image;
  EXPECT_EQ(image.Height(), 0);
  EXPECT_EQ(image.Width(), 0);
  EXPECT_EQ(image.Depth(), 0);
  EXPECT_EQ(image.Shape(0), 0);
}

TEST(Image, CopyConstructor) {
  Image<int> image(10,10);
  image(0,0) = 1;
  image(0,1) = 1;
  Image<int> copy(image);
  EXPECT_EQ(copy.Height(), 10);
  EXPECT_EQ(copy.Width(), 10);
  EXPECT_EQ(copy.Depth(), 1);
  EXPECT_EQ(copy(0,0), 1);
  copy(0,1) = 2;
  EXPECT_EQ(image(0,1), 1);
}

TEST(Image, Assignation) {
  Image<int> image(10,10);
  image(0,0) = 1;
  image(0,1) = 1;
  Image<int> copy;
  copy = image;
  EXPECT_EQ(copy.Height(), 10);
  EXPECT_EQ(copy.Width(), 10);
  EXPECT_EQ(copy.Depth(), 1);
  EXPECT_EQ(copy(0,0), 1);
  copy(0,1) = 2;
  EXPECT_EQ(image(0,1), 1);
}

TEST(Image, Parenthesis) {
  Image<int> image(1,2,3);
  image(0,1,0) = 3;
  EXPECT_EQ(image(0,1), 3);
}

}  // namespace
