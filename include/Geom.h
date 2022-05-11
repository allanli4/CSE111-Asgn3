#include "Point.h"
#include <vector>
#include "Circle.h"
#include "Reuleaux.h"

class Geom{
    public:
        static double Point_to_Point_Distance(const Point &a, const Point &b);
        static double Point_to_Segment_Distance(const Point &A, const Point &B, const Point &E);
        static bool isInside(std::vector<Point> polygon, int n, Point p);
        static bool isInCircle(Circle &c, Point &A);
        static bool segmentIntersect(Point p1, Point q1, Point p2, Point q2);
        static bool crossCircle(Point &p1, Point &p2, Circle &circle);
        static bool onSegment(Point p, Point q, Point r);
};

