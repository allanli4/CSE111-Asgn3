// #include "Circle.h"
// #include "Polygon.h"
// #include <gtest/gtest.h>

// // Uncomment when you're ready

// TEST(CirclePolygon, Touches_Inside)
// {
//   Circle inner = Circle(Point(4.0,2.0), 2.0);
//   std::vector<Point> vertices= {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(0.0,6.0)};
//   Polygon outer = Polygon(vertices);
//   ASSERT_TRUE(inner.ContainedBy(outer));

// }

// TEST(CirclePolygon, Contained)
// {
//   Circle inner = Circle(Point(4.0,2.0), 2.0);
//   std::vector<Point> vertices= {Point(0.0,-1.0),Point(8.0,-1.0),Point(6.0,6.0),Point(0.0,6.0)};
//   Polygon outer = Polygon(vertices);
//   ASSERT_TRUE(inner.ContainedBy(outer));
// }
// TEST(CirclePolygon, Outside)
// {
//   Circle inner = Circle(Point(8.0,2.0), 1.0);
//   std::vector<Point> vertices= {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
//   Polygon outer = Polygon(vertices);
//   ASSERT_FALSE(inner.ContainedBy(outer));
// }
// TEST(CirclePolygon, Surrounds)
// {
//   Circle inner = Circle(Point(8.0,2.0), 10.0);
//   std::vector<Point> vertices= {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
//   Polygon outer = Polygon(vertices);
//   ASSERT_FALSE(inner.ContainedBy(outer));
// }
// TEST(CirclePolygon, Touches_Outside)
// {
//   Circle inner = Circle(Point(8.0,2.0), 2.0);
//   std::vector<Point> vertices= {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
//   Polygon outer = Polygon(vertices);
//   ASSERT_FALSE(inner.ContainedBy(outer));
// }
// TEST(CirclePolygon, Intersect)
// {
//   Circle inner = Circle(Point(6.0,2.0), 2.0);
//   std::vector<Point> vertices= {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
//   Polygon outer = Polygon(vertices);
//   ASSERT_FALSE(inner.ContainedBy(outer));
// }
// TEST(CirclePolygon, Coincident)
// {
//   Circle inner = Circle(Point(4.0,2.0), 2);
//   std::vector<Point> vertices= {Point(2.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0)};
//   Polygon outer = Polygon(vertices);
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


#include "Point.h"
#include "Geom.h"
#include "Circle.h"
#include "Polygon.h"
#include "Reuleaux.h"
#include <gtest/gtest.h>
#include <cmath>
using namespace std;

// Uncomment when you're ready
// 1. Contained
// 2. outside
// 3. Surrounds 
// 4. Intersects 
// 5. Touches Inside 
// 6. Touches Outside 
// 7. Coincident

// the inner circle is totally contained inside the outer polygon
TEST(____CirclePolygon____, test1) {
    
    Circle inner = Circle(Point(0, 0), 2);
    
    vector<Point> vertices {
        Point(3, -3),
        Point(3, 3),
        Point(-3, 3),
        Point(-3, -3)
    };
    Polygon outer = Polygon(vertices);
    
    ASSERT_TRUE(inner.ContainedBy(outer));
}

// the inner circle is outside the outer polygon (not contained)
TEST(____CirclePolygon____, test2) {
    
    Circle inner = Circle(Point(6, 6), 2);
    
    vector<Point> vertices {
        Point(3, -3),
        Point(3, 3),
        Point(-3, 3),
        Point(-3, -3)
    };
    Polygon outer = Polygon(vertices);
    
    ASSERT_FALSE(inner.ContainedBy(outer));
}

// the inner circle is outside the outer polygon (not contained)
TEST(____CirclePolygon____, test3) {
    
    Circle inner = Circle(Point(0, 0), 3*sqrt(2));
    
    vector<Point> vertices {
        Point(3, -3),
        Point(3, 3),
        Point(-3, 3),
        Point(-3, -3)
    };
    Polygon outer = Polygon(vertices);
    
    ASSERT_FALSE(inner.ContainedBy(outer));
}

// the inner circle intersetc with polygon
TEST(____CirclePolygon____, test4) {
    
    Circle inner = Circle(Point(2, 2), 1);
    
    vector<Point> vertices {
        Point(3, -3),
        Point(3, 3),
        Point(-3, 3),
        Point(-3, -3)
    };
    Polygon outer = Polygon(vertices);
    
    ASSERT_TRUE(inner.ContainedBy(outer));
}

// touches inside
TEST(____CirclePolygon____, test5) {
    
    Circle inner = Circle(Point(0, 0), 3);
    
    vector<Point> vertices {
        Point(3, -3),
        Point(3, 3),
        Point(-3, 3),
        Point(-3, -3)
    };
    Polygon outer = Polygon(vertices);
    
    ASSERT_TRUE(inner.ContainedBy(outer));
}

// touches outside
TEST(____CirclePolygon____, test6) {
    
    Circle inner = Circle(Point(-6, 0), 3);
    
    vector<Point> vertices {
        Point(3, -3),
        Point(3, 3),
        Point(-3, 3),
        Point(-3, -3)
    };
    Polygon outer = Polygon(vertices);
    
    ASSERT_FALSE(inner.ContainedBy(outer));
}


// strange case
TEST(____CirclePolygon____, test7) {
    
    Circle inner = Circle(Point(0, 0), 2);
    
    vector<Point> vertices {
        Point(-4, -4),
        Point(-2, -2),
        Point(4, -2),
        Point(4, 4),
        Point(-4, 4)
    };
    Polygon outer = Polygon(vertices);
    
    ASSERT_TRUE(inner.ContainedBy(outer));
}

// strange case 2
TEST(____CirclePolygon____, test8) {
    
    Circle inner = Circle(Point(0, 0), 3*sqrt(2));
    
    vector<Point> vertices {
        Point(3, -3),
        Point(3, 3),
        Point(-3, 3),
        Point(-3, -3)
    };
    Polygon outer = Polygon(vertices);
    
    ASSERT_FALSE(inner.ContainedBy(outer));
}