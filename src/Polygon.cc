#include "Polygon.h"


Polygon::Polygon(std::vector<Point> vertices)
{
    vertices_ = vertices;
}

bool Polygon::ContainedBy(Circle &circle)
{
    return false;
}

bool Polygon::ContainedBy(Polygon &polygon)
{
    return false;
}

bool Polygon::ContainedBy(ReuleauxTriangle &rt)
{
    return false;
}   

std::vector<Point> Polygon::Vertices()
{
    return vertices_;
}
