#include "Reuleaux.h"
#include "Geom.h"
#include "Circle.h"
#include "Polygon.h"
#include <iostream>
using namespace std;

ReuleauxTriangle::ReuleauxTriangle(const Point vertices[3])
{
    vertice1_ = vertices[0];
    vertice2_ = vertices[1];
    vertice3_ = vertices[2];
    radius_ = Geom::Point_to_Point_Distance(vertice1_,vertice2_);
}

bool inRT( Point &a, ReuleauxTriangle &rt){
    Circle circle1 = Circle(rt.Vertice1(), rt.Radius());
    Circle circle2 = Circle(rt.Vertice2(), rt.Radius());
    Circle circle3 = Circle(rt.Vertice3(), rt.Radius());
    return Geom::isInCircle(circle1, a) && Geom::isInCircle(circle2, a) && Geom::isInCircle(circle3, a);
}
bool crossRT(ReuleauxTriangle &rt, Point &a, Point &b){
    Circle circle1 = Circle(rt.Vertice1(), rt.Radius());
    Circle circle2 = Circle(rt.Vertice2(), rt.Radius());
    Circle circle3 = Circle(rt.Vertice3(), rt.Radius());
    return Geom::crossCircle(a,b,circle1) && Geom::crossCircle(a,b,circle2) && Geom::crossCircle(a,b,circle3);
}
bool ReuleauxTriangle::ContainedBy(Circle &circle)
{   
    if(Geom::isInCircle(circle, vertice1_) && Geom::isInCircle(circle, vertice2_) && Geom::isInCircle(circle, vertice3_)){
        Point center = circle.Center();
        if(inRT(center, *this)){
            return true;
        }
        else{
            double D_1 = Geom::Point_to_Point_Distance(center, vertice1_);
            double D_2 = Geom::Point_to_Point_Distance(center, vertice2_);
            double D_3 = Geom::Point_to_Point_Distance(center, vertice3_);
            double D = D_1 > D_2 ? D_2 : D_1;
            D = D > D_3 ? D_3 : D;
            if(D + Radius() > circle.Radius()){
                // return false;
            }
            else{
                return true;
            }
        };
    };
    return false;
}

bool ReuleauxTriangle::ContainedBy(Polygon &polygon)
{   
    std::vector<Point> vertices = polygon.Vertices();
    if(Geom::isInside(vertices,vertices.size(),vertice1_) && Geom::isInside(vertices,vertices.size(),vertice2_) && Geom::isInside(vertices,vertices.size(),vertice3_)){
        for(auto &side : polygon.Sides()){
            if(crossRT(*this, side.F, side.S)){
                int count = 0;
                if(Geom::onSegment(side.F, vertice1_,side.S)){
                    count += 1;
                }
                if(Geom::onSegment(side.F, vertice2_,side.S)){
                    count += 1;
                }
                if(Geom::onSegment(side.F, vertice3_,side.S)){
                    count += 1;
                }
                if(count > 1){
                    return false;
                }  
            }
        }
        return true;
    }
    return false;
}

bool ReuleauxTriangle::ContainedBy(ReuleauxTriangle &rt)
{
    Circle circle1 = Circle(rt.Vertice1(), rt.Radius());
    Circle circle2 = Circle(rt.Vertice2(), rt.Radius());
    Circle circle3 = Circle(rt.Vertice3(), rt.Radius());
    if(this->ReuleauxTriangle::ContainedBy(circle1) && this->ReuleauxTriangle::ContainedBy(circle2) && this->ReuleauxTriangle::ContainedBy(circle3)){
        return true;
    }
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
