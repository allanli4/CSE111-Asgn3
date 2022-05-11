#include "Reuleaux.h"
#include <gtest/gtest.h>
#include <cmath>

// Uncomment when you're ready

TEST(ReuleauxReuleaux, Contained)
{
  const Point vertices1[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
  ReuleauxTriangle inner = ReuleauxTriangle(vertices1);
  const Point vertices2[3] = {Point(-6.0,-2.0),Point(2.0,-2.0),Point(-2.0,sqrt(3)*4)};
  ReuleauxTriangle outer = ReuleauxTriangle(vertices2);
  ASSERT_TRUE(inner.ContainedBy(outer));
}

TEST(ReuleauxReuleaux, Touches_Inside)
{
  const Point vertices1[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
  ReuleauxTriangle inner = ReuleauxTriangle(vertices1);
  const Point vertices2[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
  ReuleauxTriangle outer = ReuleauxTriangle(vertices2);
  ASSERT_TRUE(inner.ContainedBy(outer));
}

TEST(ReuleauxReuleaux, Outside)
{
  const Point vertices1[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
  ReuleauxTriangle inner = ReuleauxTriangle(vertices1);
  const Point vertices2[3] = {Point(1.0,0.0),Point(5.0,0.0),Point(3.0,sqrt(3)*2)};
  ReuleauxTriangle outer = ReuleauxTriangle(vertices2);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(ReuleauxReuleaux, Surrounds)
{
  const Point vertices1[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
  ReuleauxTriangle inner = ReuleauxTriangle(vertices1);
  const Point vertices2[3] = {Point(-3.0,1.0),Point(-1.0,1.0),Point(-2.0,1+sqrt(3)*1)};
  ReuleauxTriangle outer = ReuleauxTriangle(vertices2);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(ReuleauxReuleaux, Touches_Outside)
{
  const Point vertices1[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
  ReuleauxTriangle inner = ReuleauxTriangle(vertices1);
  const Point vertices2[3] = {Point(0.0,0.0),Point(4.0,0.0),Point(2.0,sqrt(3)*2)};
  ReuleauxTriangle outer = ReuleauxTriangle(vertices2);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(ReuleauxReuleaux, Intersect)
{
  const Point vertices1[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
  ReuleauxTriangle inner = ReuleauxTriangle(vertices1);
  const Point vertices2[3] = {Point(-2.0,0.0),Point(2.0,0.0),Point(0.0,sqrt(3)*2)};
  ReuleauxTriangle outer = ReuleauxTriangle(vertices2);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
TEST(ReuleauxReuleaux, Coincident)
{
  const Point vertices1[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
  ReuleauxTriangle inner = ReuleauxTriangle(vertices1);
  const Point vertices2[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
  ReuleauxTriangle outer = ReuleauxTriangle(vertices2);
  ASSERT_TRUE(inner.ContainedBy(outer));
}
/* 
   You'll need to extend this by adding additional tests for:
    1. Inner and Outer intersect (not contained)
    2. Inner is entirely outside Outer (not contained)
    3. Inner surrounds Outer (not contained)
    4. Inner perimeter touches Outer perimeter, Inner is inside Outer (contained)
    5. Inner perimeter touches Outer perimeter, Inner is outside Outer (not contained)
*/






