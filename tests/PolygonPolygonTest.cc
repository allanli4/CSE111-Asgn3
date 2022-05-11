#include "Polygon.h"
#include <gtest/gtest.h>

// Uncomment when you're ready

TEST(PolygonPolygon, Contained)
{
  std::vector<Point> vertices1 = {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
  Polygon inner = Polygon(vertices1);
  std::vector<Point> vertices2 = {Point(-2.0,-2.0),Point(8.0,-2.0),Point(8.0,8.0),Point(-2.0,8.0)};
  Polygon outer = Polygon(vertices2);
  ASSERT_TRUE(inner.ContainedBy(outer));

}
TEST(PolygonPolygon, Touches_Inside)
{
  std::vector<Point> vertices1 = {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
  Polygon inner = Polygon(vertices1);
  std::vector<Point> vertices2 = {Point(-2.0,0.0),Point(8.0,0.0),Point(8.0,8.0),Point(-2.0,8.0)};
  Polygon outer = Polygon(vertices2);
  ASSERT_TRUE(inner.ContainedBy(outer));
}
TEST(PolygonPolygon, Outside)
{
  std::vector<Point> vertices1 = {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
  Polygon inner = Polygon(vertices1);
  std::vector<Point> vertices2 = {Point(10.0,0.0),Point(12.0,0.0),Point(12.0,2.0),Point(10.0,2.0)};
  Polygon outer = Polygon(vertices2);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
TEST(PolygonPolygon, Surrounds)
{
  std::vector<Point> vertices1 = {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
  Polygon inner = Polygon(vertices1);
  std::vector<Point> vertices2 = {Point(2.0,2.0),Point(3.0,2.0),Point(3.0,3.0),Point(2.0,3.0)};
  Polygon outer = Polygon(vertices2);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
TEST(PolygonPolygon, Touches_Outside)
{
  std::vector<Point> vertices1 = {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
  Polygon inner = Polygon(vertices1);
  std::vector<Point> vertices2 = {Point(-2.0,0.0),Point(0.0,0.0),Point(0.0,2.0),Point(-2.0,2.0)};
  Polygon outer = Polygon(vertices2);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
TEST(PolygonPolygon, Intersect)
{
  std::vector<Point> vertices1 = {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
  Polygon inner = Polygon(vertices1);
  std::vector<Point> vertices2 = {Point(-2.0,0.0),Point(4.0,0.0),Point(4.0,3.0),Point(-2.0,3.0)};
  Polygon outer = Polygon(vertices2);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
TEST(PolygonPolygon, Coincident)
{
  std::vector<Point> vertices1 = {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
  Polygon inner = Polygon(vertices1);
  std::vector<Point> vertices2 = {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
  Polygon outer = Polygon(vertices2);
  ASSERT_TRUE(inner.ContainedBy(outer));
}
// /* 
//    You'll need to extend this by adding additional tests for:
//     1. Inner and Outer intersect (not contained)
//     2. Inner is entirely outside Outer (not contained)
//     3. Inner surrounds Outer (not contained)
//     4. Inner perimeter touches Outer perimeter, Inner is inside Outer (contained)
//     5. Inner perimeter touches Outer perimeter, Inner is outside Outer (not contained)
// */

TEST(PolygonPolygon, Edge)
{
    std::vector<Point> vertices2 = {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
    Polygon inner = Polygon(vertices2);
    std::vector<Point> vertices1 = {Point(1.0,1.0),Point(5.0,1.0),Point(5.0,5.0),Point(1.0,5.0)};
    Polygon outer = Polygon(vertices1);
    ASSERT_FALSE(inner.ContainedBy(outer));
}
