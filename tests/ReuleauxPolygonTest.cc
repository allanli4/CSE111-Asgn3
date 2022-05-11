#include "Polygon.h"
#include "Reuleaux.h"
#include <gtest/gtest.h>
#include <cmath>

// Uncomment when you're ready

// TEST(ReuleauxPolygon, Contained)
// {
//   const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
//   ReuleauxTriangle inner = ReuleauxTriangle(vertices);
//   std::vector<Point> vertices1 = {Point(-6.0,-2.0),Point(2.0,-2.0),Point(2.0,6.0),Point(-6.0,6.0)};
//   Polygon outer = Polygon(vertices1);
//   ASSERT_TRUE(inner.ContainedBy(outer));
// }

TEST(ReuleauxPolygon, Touches_Inside)
{
  const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
  ReuleauxTriangle inner = ReuleauxTriangle(vertices);
  std::vector<Point> vertices1 = {Point(-6.0,2.0),Point(-2.0,-2.0),Point(4.0,2.0),Point(-2.0,6.0)};
  Polygon outer = Polygon(vertices1);
  ASSERT_TRUE(inner.ContainedBy(outer));
}

// TEST(ReuleauxPolygon, Outside)
// {
//   const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
//   ReuleauxTriangle inner = ReuleauxTriangle(vertices);
//   std::vector<Point> vertices1 = {Point(2.0,0.0),Point(4.0,0.0),Point(4.0,1.0),Point(2.0,1.0)};
//   Polygon outer = Polygon(vertices1);
//   ASSERT_FALSE(inner.ContainedBy(outer));
// }

// TEST(ReuleauxPolygon, Surrounds)
// {
//   const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
//   ReuleauxTriangle inner = ReuleauxTriangle(vertices);
//   std::vector<Point> vertices1 = {Point(-2.0,0.0),Point(-1.0,0.0),Point(-1.0,1.0),Point(-2.0,1.0)};
//   Polygon outer = Polygon(vertices1);
//   ASSERT_FALSE(inner.ContainedBy(outer));
// }

// TEST(ReuleauxPolygon, Touches_Outside)
// {
//   const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
//   ReuleauxTriangle inner = ReuleauxTriangle(vertices);
//   std::vector<Point> vertices1 = {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
//   Polygon outer = Polygon(vertices1);
//   ASSERT_FALSE(inner.ContainedBy(outer));
// }

// TEST(ReuleauxPolygon, Intersect)
// {
//   const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
//   ReuleauxTriangle inner = ReuleauxTriangle(vertices);
//   std::vector<Point> vertices1 = {Point(-2.0,0.0),Point(1.0,0.0),Point(1.0,1.0),Point(-2.0,1.0)};
//   Polygon outer = Polygon(vertices1);
//   ASSERT_FALSE(inner.ContainedBy(outer));
// }
// TEST(ReuleauxPolygon, Coincident)
// {
//   const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
//   ReuleauxTriangle inner = ReuleauxTriangle(vertices);
//   std::vector<Point> vertices1 = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
//   Polygon outer = Polygon(vertices1);
//   ASSERT_FALSE(inner.ContainedBy(outer));
// }
/* 
   You'll need to extend this by adding additional tests for:
    1. Inner and Outer intersect (not contained)
    2. Inner is entirely outside Outer (not contained)
    3. Inner surrounds Outer (not contained)
    4. Inner perimeter touches Outer perimeter, Inner is inside Outer (contained)
    5. Inner perimeter touches Outer perimeter, Inner is outside Outer (not contained)
*/






