#include "Circle.h"
#include "Reuleaux.h"
#include <gtest/gtest.h>

// Uncomment when you're ready

TEST(CircleReuleaux, Contained)
{
  Circle inner = Circle(Point(-2.0,2.0), 1.0);
  const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,3.5)};
  ReuleauxTriangle outer = ReuleauxTriangle(vertices);
  ASSERT_TRUE(inner.ContainedBy(outer));

}

TEST(CircleReuleaux, Touches_Inside)
{
  Circle inner = Circle(Point(-2.2,2.0), 1.0);
  const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,3.5)};
  ReuleauxTriangle outer = ReuleauxTriangle(vertices);
  ASSERT_TRUE(inner.ContainedBy(outer));
}
TEST(CircleReuleaux, Outside)
{
  Circle inner = Circle(Point(-5.0,0.0), 1.0);
  const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,3.5)};
  ReuleauxTriangle outer = ReuleauxTriangle(vertices);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
TEST(CircleReuleaux, Surrounds)
{
  Circle inner = Circle(Point(-2.0,1.2), 2.3);
  const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,3.5)};
  ReuleauxTriangle outer = ReuleauxTriangle(vertices);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
TEST(CircleReuleaux, Touches_Outside)
{
  Circle inner = Circle(Point(-4.19996,2.76212), 1.0);
  const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,3.5)};
  ReuleauxTriangle outer = ReuleauxTriangle(vertices);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
TEST(CircleReuleaux, Intersect)
{
  Circle inner = Circle(Point(-3.8,2.4), 1.0);
  const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,3.5)};
  ReuleauxTriangle outer = ReuleauxTriangle(vertices);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
TEST(CircleReuleaux, Coincident)
{
  Circle inner = Circle(Point(-2.0,1.2), 1.7);
  const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,3.5)};
  ReuleauxTriangle outer = ReuleauxTriangle(vertices);
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
