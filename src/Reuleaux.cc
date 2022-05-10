#include "Reuleaux.h"
#include "Geom.h"

ReuleauxTriangle::ReuleauxTriangle(const Point vertices[3])
{
    vertice1_ = vertices[0];
    vertice2_ = vertices[1];
    vertice3_ = vertices[2];
    radius_ = Geom::Separation(vertice1_,vertice2_);
}


bool ReuleauxTriangle::ContainedBy(Circle &circle)
{
    return false;
}

bool ReuleauxTriangle::ContainedBy(Polygon &polygon)
{
    return false;
}

bool ReuleauxTriangle::ContainedBy(ReuleauxTriangle &rt)
{
    return false;
}


Point ReuleauxTriangle::Vertice1()
{
    return Point(vertice1_);
}
Point ReuleauxTriangle::Vertice2()
{
    return Point(vertice2_);
}
Point ReuleauxTriangle::Vertice3()
{
    return Point(vertice3_);
}

double ReuleauxTriangle::Radius()
{
    return radius_;
}
