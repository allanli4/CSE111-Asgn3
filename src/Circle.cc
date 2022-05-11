#include "Circle.h"
#include "Geom.h"
#include "Reuleaux.h"
#include "Polygon.h"
#include <cmath>
#define F first
#define S second

Circle::Circle(const Point &center, double radius)
{
    center_ = Point(center);
    radius_ = radius;
}

bool Circle::ContainedBy(ReuleauxTriangle &rt)
{
    Circle circle1 = Circle(rt.Vertice1(), rt.Radius());
    Circle circle2 = Circle(rt.Vertice2(), rt.Radius());
    Circle circle3 = Circle(rt.Vertice3(), rt.Radius());
    return this->ContainedBy(circle1)&&this->ContainedBy(circle2)&&this->ContainedBy(circle3);
}


bool Circle::ContainedBy(Polygon &polygon)
{
    //center in polygon
    std::vector vertices = polygon.Vertices();
    std::vector sides = polygon.Sides();
    if(Geom::isInside(vertices,vertices.size(),Center())){
        for(auto &x : sides){
            if(Radius() > Geom::Point_to_Segment_Distance(x.F, x.S, Center())){
                return false;
            };
        }
        return true;
    };
    return false;
}

bool Circle::ContainedBy(Circle &circle)
{
    double sep = Geom::Point_to_Point_Distance(Center(), circle.Center());
    double diff = circle.Radius() - Radius();
    return sep <= diff;
}

Point Circle::Center()
{
    return Point(center_);
}

double Circle::Radius()
{
    return radius_;
}
