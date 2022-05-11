#include "Circle.h"
#include "Reuleaux.h"
#include <gtest/gtest.h>
#include <cmath>

// Uncomment when you're ready

TEST(ReuleauxCircle, Contained)
{
  const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
  ReuleauxTriangle inner = ReuleauxTriangle(vertices);
  Circle outer = Circle(Point(-2.0,0.0), 8.0);
  ASSERT_TRUE(inner.ContainedBy(outer));
}

TEST(ReuleauxCircle, Touches_Inside)
{
  const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
  ReuleauxTriangle inner = ReuleauxTriangle(vertices);
  Circle outer = Circle(Point(0.0,0.0), 4.0);
  ASSERT_TRUE(inner.ContainedBy(outer));
}

TEST(ReuleauxCircle, Outside)
{
  const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
  ReuleauxTriangle inner = ReuleauxTriangle(vertices);
  Circle outer = Circle(Point(2.0,0.0), 1.0);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(ReuleauxCircle, Surrounds)
{
  const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
  ReuleauxTriangle inner = ReuleauxTriangle(vertices);
  Circle outer = Circle(Point(-2.0,1.0), 1.0);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(ReuleauxCircle, Touches_Outside)
{
  const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
  ReuleauxTriangle inner = ReuleauxTriangle(vertices);
  Circle outer = Circle(Point(2.0,0.0), 2.0);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(ReuleauxCircle, Intersect)
{
  const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
  ReuleauxTriangle inner = ReuleauxTriangle(vertices);
  Circle outer = Circle(Point(1.0,0.0), 2.0);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
TEST(ReuleauxCircle, Coincident)
{
  const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
  ReuleauxTriangle inner = ReuleauxTriangle(vertices);
  Circle outer = Circle(Point(0.0,0.0), 4.0);
  ASSERT_TRUE(inner.ContainedBy(outer));
}
TEST(ReuleauxCircle, Edge)
{
  const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
  ReuleauxTriangle inner = ReuleauxTriangle(vertices);
  Circle outer = Circle(Point(9.06589,-6.33757), 93.8);
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