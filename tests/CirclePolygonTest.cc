#include "Circle.h"
#include "Polygon.h"
#include <gtest/gtest.h>

// Uncomment when you're ready

TEST(CirclePolygon, Touches_Inside)
{
  Circle inner = Circle(Point(4.0,2.0), 2.0);
  std::vector<Point> vertices= {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(0.0,6.0)};
  Polygon outer = Polygon(vertices);
  ASSERT_TRUE(inner.ContainedBy(outer));

}

TEST(CirclePolygon, Contained)
{
  Circle inner = Circle(Point(4.0,2.0), 2.0);
  std::vector<Point> vertices= {Point(0.0,-1.0),Point(8.0,-1.0),Point(6.0,6.0),Point(0.0,6.0)};
  Polygon outer = Polygon(vertices);
  ASSERT_TRUE(inner.ContainedBy(outer));
}
TEST(CirclePolygon, Outside)
{
  Circle inner = Circle(Point(8.0,2.0), 1.0);
  std::vector<Point> vertices= {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
  Polygon outer = Polygon(vertices);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
TEST(CirclePolygon, Surrounds)
{
  Circle inner = Circle(Point(8.0,2.0), 10.0);
  std::vector<Point> vertices= {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
  Polygon outer = Polygon(vertices);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
TEST(CirclePolygon, Touches_Outside)
{
  Circle inner = Circle(Point(8.0,2.0), 2.0);
  std::vector<Point> vertices= {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
  Polygon outer = Polygon(vertices);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
TEST(CirclePolygon, Intersect)
{
  Circle inner = Circle(Point(6.0,2.0), 2.0);
  std::vector<Point> vertices= {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
  Polygon outer = Polygon(vertices);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
TEST(CirclePolygon, Coincident)
{
  Circle inner = Circle(Point(4.0,2.0), 2);
  std::vector<Point> vertices= {Point(2.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0)};
  Polygon outer = Polygon(vertices);
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
