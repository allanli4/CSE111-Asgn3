// #include "Polygon.h"
// #include <gtest/gtest.h>

// // Uncomment when you're ready

// TEST(PolygonPolygon, Contained)
// {
//   std::vector<Point> vertices1 = {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
//   Polygon inner = Polygon(vertices1);
//   std::vector<Point> vertices2 = {Point(-2.0,-2.0),Point(8.0,-2.0),Point(8.0,8.0),Point(-2.0,8.0)};
//   Polygon outer = Polygon(vertices2);
//   ASSERT_TRUE(inner.ContainedBy(outer));

// }
// TEST(PolygonPolygon, Touches_Inside)
// {
//   std::vector<Point> vertices1 = {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
//   Polygon inner = Polygon(vertices1);
//   std::vector<Point> vertices2 = {Point(-2.0,0.0),Point(8.0,0.0),Point(8.0,8.0),Point(-2.0,8.0)};
//   Polygon outer = Polygon(vertices2);
//   ASSERT_TRUE(inner.ContainedBy(outer));
// }
// TEST(PolygonPolygon, Outside)
// {
//   std::vector<Point> vertices1 = {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
//   Polygon inner = Polygon(vertices1);
//   std::vector<Point> vertices2 = {Point(10.0,0.0),Point(12.0,0.0),Point(12.0,2.0),Point(10.0,2.0)};
//   Polygon outer = Polygon(vertices2);
//   ASSERT_FALSE(inner.ContainedBy(outer));
// }
// TEST(PolygonPolygon, Surrounds)
// {
//   std::vector<Point> vertices1 = {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
//   Polygon inner = Polygon(vertices1);
//   std::vector<Point> vertices2 = {Point(2.0,2.0),Point(3.0,2.0),Point(3.0,3.0),Point(2.0,3.0)};
//   Polygon outer = Polygon(vertices2);
//   ASSERT_FALSE(inner.ContainedBy(outer));
// }
// TEST(PolygonPolygon, Touches_Outside)
// {
//   std::vector<Point> vertices1 = {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
//   Polygon inner = Polygon(vertices1);
//   std::vector<Point> vertices2 = {Point(-2.0,0.0),Point(0.0,0.0),Point(0.0,2.0),Point(-2.0,2.0)};
//   Polygon outer = Polygon(vertices2);
//   ASSERT_FALSE(inner.ContainedBy(outer));
// }
// TEST(PolygonPolygon, Intersect)
// {
//   std::vector<Point> vertices1 = {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
//   Polygon inner = Polygon(vertices1);
//   std::vector<Point> vertices2 = {Point(-2.0,0.0),Point(4.0,0.0),Point(4.0,3.0),Point(-2.0,3.0)};
//   Polygon outer = Polygon(vertices2);
//   ASSERT_FALSE(inner.ContainedBy(outer));
// }
// TEST(PolygonPolygon, Coincident)
// {
//   std::vector<Point> vertices1 = {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
//   Polygon inner = Polygon(vertices1);
//   std::vector<Point> vertices2 = {Point(0.0,0.0),Point(6.0,0.0),Point(6.0,6.0),Point(2.0,4.0),Point(0.0,6.0)};
//   Polygon outer = Polygon(vertices2);
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
#include "Point.h"
#include <gtest/gtest.h>
using namespace std;

//Outline
// 1. totally contained
TEST(______PolygonPolygon______, Contained_1)
{
    vector<Point> outer_vertices {
        Point(2, 2),
        Point(-2, 2),
        Point(-2, -2),
        Point(2, -2)
    };

    vector<Point> inner_vertices {
        Point(1, 1),
        Point(-1, 1),
        Point(-1, -1),
        Point(1, -1)
    };
    Polygon inner = Polygon(inner_vertices);
    Polygon outer = Polygon(outer_vertices);
        
    ASSERT_TRUE(inner.ContainedBy(outer));
}

// 2. outside

TEST(______PolygonPolygon______, Contained_2)
{
    vector<Point> inner_vertices {
        Point(2, 2),
        Point(-2, 2),
        Point(-2, -2),
        Point(2, -2)
    };

    vector<Point> outer_vertices {
        Point(-2, 0), 
        Point(2, 0),
        Point(0, 2)
    };
    Polygon inner = Polygon(inner_vertices);
    Polygon outer = Polygon(outer_vertices);
        
    ASSERT_FALSE(inner.ContainedBy(outer));
}

// 3. surrounds
TEST(______PolygonPolygon______, Contained_3)
{
    vector<Point> outer_vertices {
        Point(6, 2),
        Point(2, 2),
        Point(2, -2),
        Point(6, -2)
    };

    vector<Point> inner_vertices {
        Point(1, 1),
        Point(-1, 1),
        Point(-1, -1),
        Point(1, -1)
    };
    Polygon inner = Polygon(inner_vertices);
    Polygon outer = Polygon(outer_vertices);
        
    ASSERT_FALSE(inner.ContainedBy(outer));
}

/* 4. Intersetct */
TEST(______PolygonPolygon______, Contained_4)
{
    vector<Point> outer_vertices {
        Point(2, 2),
        Point(-2, 2),
        Point(-2, -2),
        Point(2, -2)
    };

    vector<Point> inner_vertices {
        Point(0, 0),
        Point(0, 4),
        Point(-4, 0)
    };
    Polygon inner = Polygon(inner_vertices);
    Polygon outer = Polygon(outer_vertices);
        
    ASSERT_FALSE(inner.ContainedBy(outer));
}

// 5. touches insde
TEST(______PolygonPolygon______, Contained_5)
{
    vector<Point> outer_vertices {
        Point(2, 2),
        Point(-2, 2),
        Point(-2, -2),
        Point(2, -2)
    };

    vector<Point> inner_vertices {
        Point(0, -2),
        Point(2, 2),
        Point(-2, 2)
    };
    Polygon inner = Polygon(inner_vertices);
    Polygon outer = Polygon(outer_vertices);
        
    ASSERT_TRUE(inner.ContainedBy(outer));
}

// 6. touches outder
TEST(______PolygonPolygon______, Contained_6)
{
    vector<Point> inner_vertices {
        Point(2, 0),
        Point(0, 2),
        Point(-2, 0)
    };

    vector<Point> outer_vertices {
        Point(0, 0),
        Point(1, 1),
        Point(-1, 1)
    };
    Polygon inner = Polygon(inner_vertices);
    Polygon outer = Polygon(outer_vertices);
        
    ASSERT_FALSE(inner.ContainedBy(outer));
}


// 7. Coincident
TEST(______PolygonPolygon______, Contained_7)
{
    vector<Point> outer_vertices {
        Point(2, 0),
        Point(0, 2),
        Point(-2, 0)
    };

    vector<Point> inner_vertices {
        Point(2, 0),
        Point(0, 2),
        Point(-2, 0)
    };
    Polygon inner = Polygon(inner_vertices);
    Polygon outer = Polygon(outer_vertices);
        
    ASSERT_TRUE(inner.ContainedBy(outer));
}

// 8. strange test
TEST(______PolygonPolygon______, Contained_8)
{
    vector<Point> outer_vertices {
        Point(0, 1),
        Point(3, 3),
        Point(3, 0),
        Point(-3, 0),
        Point(-3, 3),
    };

    vector<Point> inner_vertices {
        Point(2, .5),
        Point(2, 2),
        Point(-2, 2),
        Point(-2, -.5)
    };
    Polygon inner = Polygon(inner_vertices);
    Polygon outer = Polygon(outer_vertices);
        
    ASSERT_FALSE(inner.ContainedBy(outer));
}

// 9. edge case
TEST(______PolygonPolygon______, Contained_9)
{
    vector<Point> outer_vertices {
        Point(2, -2),
        Point(.5, -.5),
        Point(2, 2),
        Point(-2, 2),
        Point(-2, -2)
    };

    vector<Point> inner_vertices {
        Point(0, 0),
        Point(0, 1),
        Point(-1, 1),
        Point(-1, -0)
    };
    Polygon inner = Polygon(inner_vertices);
    Polygon outer = Polygon(outer_vertices);
        
    ASSERT_TRUE(inner.ContainedBy(outer));
}