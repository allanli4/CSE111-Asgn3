#include "Circle.h"
#include "Polygon.h"
#include <gtest/gtest.h>
#include <cmath>

// Uncomment when you're ready

TEST(PolygonCircle, Contained)
{
  std::vector<Point> vertices= {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
  Polygon inner = Polygon(vertices);
  Circle outer = Circle(Point(0.0,0.0), 10.0);
  ASSERT_TRUE(inner.ContainedBy(outer));

}
TEST(PolygonCircle, Touches_Inside)
{
  std::vector<Point> vertices= {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
  Polygon inner = Polygon(vertices);
  Circle outer = Circle(Point(3.0,3.0), 3*sqrt(2));
  ASSERT_TRUE(inner.ContainedBy(outer));
}
TEST(PolygonCircle, Outside)
{
  std::vector<Point> vertices= {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
  Polygon inner = Polygon(vertices);
  Circle outer = Circle(Point(0.0,-2.0), 1.0);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
TEST(PolygonCircle, Surrounds)
{
  std::vector<Point> vertices= {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
  Polygon inner = Polygon(vertices);
  Circle outer = Circle(Point(3.0,3.0), 1.0);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
TEST(PolygonCircle, Touches_Outside)
{
  std::vector<Point> vertices= {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
  Polygon inner = Polygon(vertices);
  Circle outer = Circle(Point(-2.0,0.0), 2.0);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
TEST(PolygonCircle, Intersect)
{
  std::vector<Point> vertices= {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
  Polygon inner = Polygon(vertices);
  Circle outer = Circle(Point(0.0,0.0), 4.0);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
TEST(PolygonCircle, Coincident)
{
  std::vector<Point> vertices= {Point(0.0,0.0),Point(4.0,0.0),Point(4.0,4.0),Point(0.0,4.0)};
  Polygon inner = Polygon(vertices);
  Circle outer = Circle(Point(2.0,2.0), 2.0);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
/* 
   You'll need to extend this by adding additional tests for:
    1. Inner and Outer intersect (not contained)
    2. Inner is entirely outside Outer (not contained)
    3. Inner surrounds Outer (not contained)
    4. Inner perimeter touches Outer perimeter, Inner is inside Outer (contained)
    5. Inner perimeter touches Outer perimeter, Inner is outside Outer (not contained)
*/
