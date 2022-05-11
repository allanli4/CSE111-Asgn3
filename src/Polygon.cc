#include "Polygon.h"
#include "Geom.h"
#include "Circle.h"
#include "Reuleaux.h"
#include <iostream>
using namespace std;

Polygon::Polygon(std::vector<Point> vertices)
{
    vertices_ = vertices;
    pair<Point,Point> side;
    Point last_point = vertices.back();
    for(auto &x : vertices){
        side.F = last_point;
        side.S = x;
        last_point = x;
        sides_.push_back(side);
    };
}

bool Polygon::ContainedBy(Circle &circle)
{
    double radius = circle.Radius();
    Point center = circle.Center();
    for(auto &x : Vertices()){
        if(Geom::Point_to_Point_Distance(x,center) > radius && abs(Geom::Point_to_Point_Distance(x,center) - radius) > 0.1){
            return false;
        }
    }
    return true;
}

bool Polygon::ContainedBy(Polygon &polygon)
{   
    for(auto &x : vertices_){
        if(!Geom::isInside(polygon.Vertices(),polygon.Vertices().size(),x)){
            return false;
        }
    }
    for(auto &side : sides_){
        for(auto &outer_side : polygon.Sides()){
            if(Geom::segmentIntersect(side.F,side.S,outer_side.F,outer_side.S)){
                return false;
            }
        }
    }
    return true;
}

bool Polygon::ContainedBy(ReuleauxTriangle &rt)
{
    Circle circle1 = Circle(rt.Vertice1(), rt.Radius());
    Circle circle2 = Circle(rt.Vertice2(), rt.Radius());
    Circle circle3 = Circle(rt.Vertice3(), rt.Radius());
    return this->ContainedBy(circle1)&&this->ContainedBy(circle2)&&this->ContainedBy(circle3);
}   

std::vector<Point> Polygon::Vertices()
{
    return vertices_;
}

std::vector<Side> Polygon::Sides()
{
    return sides_;
}

