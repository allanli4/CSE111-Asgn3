#include "Circle.h"
#include <gtest/gtest.h>

// Uncomment when you're ready

TEST(CircleCircle, Contained)
{
  Circle inner = Circle(Point(0.0,0.0), 2.0);
  Circle outer = Circle(Point(0.0,0.0), 4.0);
  ASSERT_TRUE(inner.ContainedBy(outer));

}
TEST(CircleCircle, Touches_Inside)
{
  Circle inner = Circle(Point(-2.0,0.0), 2.0);
  Circle outer = Circle(Point(0.0,0.0), 4.0);
  ASSERT_TRUE(inner.ContainedBy(outer));
}
TEST(CircleCircle, Outside)
{
  Circle inner = Circle(Point(-5.0,0.0), 2.0);
  Circle outer = Circle(Point(0.0,0.0), 4.0);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
TEST(CircleCircle, Surrounds)
{
  Circle inner = Circle(Point(0.0,0.0), 4.0);
  Circle outer = Circle(Point(0.0,0.0), 2.0);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
TEST(CircleCircle, Touches_Outside)
{
  Circle inner = Circle(Point(6.0,0.0), 2.0);
  Circle outer = Circle(Point(0.0,0.0), 4.0);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
TEST(CircleCircle, Intersect)
{
  Circle inner = Circle(Point(3.0,0.0), 2.0);
  Circle outer = Circle(Point(0.0,0.0), 4.0);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
TEST(CircleCircle, Coincident)
{
  Circle inner = Circle(Point(0.0,0.0), 4.0);
  Circle outer = Circle(Point(0.0,0.0), 4.0);
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
