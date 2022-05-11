#include "Reuleaux.h"
#include "Polygon.h"
#include <gtest/gtest.h>

// Uncomment when you're ready

TEST(PolygonReuleaux, Contained)
{
  std::vector<Point> vertices1 = {Point(-3.0,1.0),Point(-1.0,1.0),Point(-1.0,2.0),Point(-3.0,2.0)};
  Polygon inner = Polygon(vertices1);
  const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,3.5)};
  ReuleauxTriangle outer = ReuleauxTriangle(vertices);
  ASSERT_TRUE(inner.ContainedBy(outer));

}
TEST(PolygonReuleaux, Touches_Inside)
{
  std::vector<Point> vertices1 = {Point(-4.0,0.0),Point(-1.0,1.0),Point(-1.0,2.0),Point(-3.0,2.0)};
  Polygon inner = Polygon(vertices1);
  const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,3.5)};
  ReuleauxTriangle outer = ReuleauxTriangle(vertices);
  ASSERT_TRUE(inner.ContainedBy(outer));
}
TEST(PolygonReuleaux, Outside)
{
  std::vector<Point> vertices1 = {Point(-5.0,0.0),Point(-5.0,1.0),Point(-6.0,1.0),Point(-6.0,0.0)};
  Polygon inner = Polygon(vertices1);
  const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,3.5)};
  ReuleauxTriangle outer = ReuleauxTriangle(vertices);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
TEST(PolygonReuleaux, Surrounds)
{
  std::vector<Point> vertices1 = {Point(1.0,4.0),Point(-5.0,4.0),Point(-5.0,-1.0),Point(1.0,-1.0)};
  Polygon inner = Polygon(vertices1);
  const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,3.5)};
  ReuleauxTriangle outer = ReuleauxTriangle(vertices);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
TEST(PolygonReuleaux, Touches_Outside)
{
  std::vector<Point> vertices1 = {Point(-4.0,0.0),Point(-4.0,1.0),Point(-5.0,1.0),Point(-5.0,0.0)};
  Polygon inner = Polygon(vertices1);
  const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,3.5)};
  ReuleauxTriangle outer = ReuleauxTriangle(vertices);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
TEST(PolygonReuleaux, Intersect)
{
  std::vector<Point> vertices1 = {Point(-4.0,0.0),Point(-1.0,1.0),Point(-1.0,2.0),Point(-4.0,2.0)};
  Polygon inner = Polygon(vertices1);
  const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,3.5)};
  ReuleauxTriangle outer = ReuleauxTriangle(vertices);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
TEST(PolygonReuleaux, Coincident)
{
  std::vector<Point> vertices1 = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,3.5)};
  Polygon inner = Polygon(vertices1);
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
