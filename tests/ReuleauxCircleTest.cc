// #include "Circle.h"
// #include "Reuleaux.h"
// #include <gtest/gtest.h>
// #include <cmath>

// // Uncomment when you're ready

// TEST(ReuleauxCircle, Contained)
// {
//   const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
//   ReuleauxTriangle inner = ReuleauxTriangle(vertices);
//   Circle outer = Circle(Point(-2.0,0.0), 8.0);
//   ASSERT_TRUE(inner.ContainedBy(outer));
// }

// TEST(ReuleauxCircle, Touches_Inside)
// {
//   const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
//   ReuleauxTriangle inner = ReuleauxTriangle(vertices);
//   Circle outer = Circle(Point(0.0,0.0), 4.0);
//   ASSERT_TRUE(inner.ContainedBy(outer));
// }

// TEST(ReuleauxCircle, Outside)
// {
//   const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
//   ReuleauxTriangle inner = ReuleauxTriangle(vertices);
//   Circle outer = Circle(Point(2.0,0.0), 1.0);
//   ASSERT_FALSE(inner.ContainedBy(outer));
// }

// TEST(ReuleauxCircle, Surrounds)
// {
//   const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
//   ReuleauxTriangle inner = ReuleauxTriangle(vertices);
//   Circle outer = Circle(Point(-2.0,1.0), 1.0);
//   ASSERT_FALSE(inner.ContainedBy(outer));
// }

// TEST(ReuleauxCircle, Touches_Outside)
// {
//   const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
//   ReuleauxTriangle inner = ReuleauxTriangle(vertices);
//   Circle outer = Circle(Point(2.0,0.0), 2.0);
//   ASSERT_FALSE(inner.ContainedBy(outer));
// }

// TEST(ReuleauxCircle, Intersect)
// {
//   const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
//   ReuleauxTriangle inner = ReuleauxTriangle(vertices);
//   Circle outer = Circle(Point(1.0,0.0), 2.0);
//   ASSERT_FALSE(inner.ContainedBy(outer));
// }
// TEST(ReuleauxCircle, Coincident)
// {
//   const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
//   ReuleauxTriangle inner = ReuleauxTriangle(vertices);
//   Circle outer = Circle(Point(0.0,0.0), 4.0);
//   ASSERT_TRUE(inner.ContainedBy(outer));
// }
// TEST(ReuleauxCircle, Edge)
// {
//   const Point vertices[3] = {Point(0.0,0.0),Point(-4.0,0.0),Point(-2.0,sqrt(3)*2)};
//   ReuleauxTriangle inner = ReuleauxTriangle(vertices);
//   Circle outer = Circle(Point(9.06589,-6.33757), 93.8);
//   ASSERT_TRUE(inner.ContainedBy(outer));
// }
// /* 
//    You'll need to extend this by adding additional tests for:
//     1. Inner and Outer intersect (not contained)
//     2. Inner is entirely outside Outer (not contained)
//     3. Inner surrounds Outer (not contained)
//     4. Inner perimeter touches Outer perimeter, Inner is inside Outer (contained)
//     5. Inner perimeter touches Outer perimeter, Inner is outside Outer (not contained)
// */


#include "Polygon.h"
#include "Reuleaux.h"
#include "Point.h"
#include "Circle.h"

#include <cmath>
#include <gtest/gtest.h>
using namespace std;

//Outline
// Uncomment when you're ready
// 1. Contained
// 2. outside
// 3. Surrounds 
// 4. Intersects 
// 5. Touches Inside 
// 6. Touches Outside 
// 7. Coincident

// 1. Polygon totally containi Reuleaux
TEST(______ReuleauxCircle______, Contained_1)
{
    const Point arr[3] = {Point(0, 0), Point(4, 0),  Point(2, 2*sqrt(3))};
    ReuleauxTriangle inner = ReuleauxTriangle(arr);

    Circle outer = Circle(Point(2, 1), 3);
        
    ASSERT_TRUE(inner.ContainedBy(outer));
}


// 2. outside
TEST(______ReuleauxCircle______, Contained_2)
{
    const Point arr[3] = {Point(0, 0), Point(4, 0),  Point(2, 2*sqrt(3))};
    ReuleauxTriangle inner = ReuleauxTriangle(arr);

    Circle outer = Circle(Point(6, 0), 1);
        
    ASSERT_FALSE(inner.ContainedBy(outer));
}

// 3. surrounds
TEST(______ReuleauxCircle______, Contained_3)
{
    const Point arr[3] = {Point(0, 0), Point(4, 0),  Point(2, 2*sqrt(3))};
    ReuleauxTriangle inner = ReuleauxTriangle(arr);

    Circle outer = Circle(Point(2, 1), .5);
        
    ASSERT_FALSE(inner.ContainedBy(outer));
}

// 4. intersect
TEST(______ReuleauxCircle______, Contained_4)
{
    const Point arr[3] = {Point(0, 0), Point(4, 0),  Point(2, 2*sqrt(3))};
    ReuleauxTriangle inner = ReuleauxTriangle(arr);

    Circle outer = Circle(Point(2, 1), 2);
        
    ASSERT_FALSE(inner.ContainedBy(outer));
}

// 5. touches inside
TEST(______ReuleauxCircle______, Contained_5)
{
    const Point arr[3] = {Point(0, 0), Point(4, 0),  Point(2, 2*sqrt(3))};
    ReuleauxTriangle inner = ReuleauxTriangle(arr);

    Circle outer = Circle(Point(4, 0), 4);
        
    ASSERT_TRUE(inner.ContainedBy(outer));
}

// 6. touches outside
TEST(______ReuleauxCircle______, Contained_6)
{
    const Point arr[3] = {Point(0, 0), Point(4, 0),  Point(2, 2*sqrt(3))};
    ReuleauxTriangle inner = ReuleauxTriangle(arr);

    Circle outer = Circle(Point(5, 0), 1);
        
    ASSERT_FALSE(inner.ContainedBy(outer));
}

// 7. Coincident
TEST(______ReuleauxCircle______, Contained_7)
{
    const Point arr[3] = {Point(0, 0), Point(4, 0),  Point(2, 2*sqrt(3))};
    ReuleauxTriangle inner = ReuleauxTriangle(arr);

    Circle outer1 = Circle(Point(4, 0), 4);
    Circle outer2 = Circle(Point(0, 0), 4);
    Circle outer3 = Circle(Point(2, 2*sqrt(3)), 4);    
    ASSERT_TRUE(inner.ContainedBy(outer1));
    ASSERT_TRUE(inner.ContainedBy(outer2));
    ASSERT_TRUE(inner.ContainedBy(outer3));
}