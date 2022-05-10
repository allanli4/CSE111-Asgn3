#include "Circle.h"
#include "Geom.h"
#include "Reuleaux.h"
#include "Polygon.h"
#include <cmath>

#define MIN(x,y) (x < y ? x : y)
#define MAX(x,y) (x > y ? x : y)

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
    int counter = 0;
    int i;
    Point center = Center();
    double xinters;
    Point p1,p2;
    std::vector vertices = polygon.Vertices();
    p1 = vertices[0];
    int N = vertices.size();
    for (i=1;i<=N;i++) {
        p2 = vertices[i % N];
        if (center.y > MIN(p1.y,p2.y)) {
            if (center.y <= MAX(p1.y,p2.y)) {
                if (center.x <= MAX(p1.x,p2.x)) {
                    if (center.y != p2.y) {
                        xinters = (center.y-p1.y)*(p2.x-p1.x)/(p2.y-p1.y)+p1.x;
                        if (p1.x == p2.x || center.x <= xinters)
                        counter++;
                    }
                }
            }
        }
        p1 = p2;
    }
    if (counter % 2 == 0)
        return false;
    for (auto &x : vertices){
        if(Radius() > Geom::Separation(Center(), x)){
            return false;
        };
    };
    return true;
}

bool Circle::ContainedBy(Circle &circle)
{
    double sep = Geom::Separation(Center(), circle.Center());
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
