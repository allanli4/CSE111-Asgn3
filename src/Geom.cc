#include "Geom.h"
#include <cmath>
#include <iostream>
using namespace std;
#define min(x,y) (x < y ? x : y)
#define max(x,y) (x > y ? x : y)
#define F first
#define S second
#define INF 10000


double Geom::Point_to_Point_Distance(const Point &a, const Point &b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
};


//https://www.geeksforgeeks.org/how-to-check-if-a-given-point-lies-inside-a-polygon/#:~:text=1)%20Draw%20a%20horizontal%20line,on%20an%20edge%20of%20polygon.

bool Geom::onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
            (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0; // collinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

bool Geom::segmentIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
 
    // General case
    if (o1 == 0 || o2 == 0 || o3 == 0 || o4 == 0){
        return false;
    }
    if (o1 != o2 && o3 != o4)
        return true;
 
    // Special Cases
    // p1, q1 and p2 are collinear and p2 lies on segment p1q1
    // if (o1 == 0 && onSegment(p1, p2, q1)) return true;
 
    // // p1, q1 and p2 are collinear and q2 lies on segment p1q1
    // if (o2 == 0 && onSegment(p1, q2, q1)) return true;
 
    // // p2, q2 and p1 are collinear and p1 lies on segment p2q2
    // if (o3 == 0 && onSegment(p2, p1, q2)) return true;
 
    // // p2, q2 and q1 are collinear and q1 lies on segment p2q2
    // if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false; // Doesn't fall in any of the above cases
}

bool Geom::isInside(std::vector<Point> polygon, int n, Point p)
{
    // There must be at least 3 vertices in polygon[]
    if (n < 3) return false;
 
    // Create a point for line segment from p to infinite
    Point extreme = {INF, p.y};
 
    // Count intersections of the above line with sides of polygon
    int count = 0, i = 0;
    do
    {
        int next = (i+1)%n;
 
        // Check if the line segment from 'p' to 'extreme' intersects
        // with the line segment from 'polygon[i]' to 'polygon[next]'
        if (segmentIntersect(polygon[i], polygon[next], p, extreme))
        {
            count++;
        }
        // If the point 'p' is collinear with line segment 'i-next',
        // then check if it lies on segment. If it lies, return true,
        // otherwise false
        else if (orientation(polygon[i], p, polygon[next]) == 0){
            return onSegment(polygon[i], p, polygon[next]);
        }
        i = next;
    } while (i != 0);
 
    // Return true if count is odd, false otherwise
    return count&1; // Same as (count%2 == 1)
}


// Function to return the minimum distance
// between a line segment AB and a point E
// https://www.geeksforgeeks.org/minimum-distance-from-a-point-to-the-line-segment-using-vectors/
double Geom::Point_to_Segment_Distance(const Point &A, const Point &B, const Point &E)
{

	// vector AB
	pair<double, double> AB;
	AB.F = B.x - A.x;
	AB.S = B.y - A.y;

	// vector BP
	pair<double, double> BE;
	BE.F = E.x - B.x;
	BE.S = E.y - B.y;

	// vector AP
	pair<double, double> AE;
	AE.F = E.x - A.x,
	AE.S = E.y - A.y;

	// Variables to store dot product
	// double AB_BE, AB_AE;

	// Calculating the dot product
	// AB_BE = (AB.F * BE.F + AB.S * BE.S);
	// AB_AE = (AB.F * AE.F + AB.S * AE.S);

	// Minimum distance from
	// point E to the line segment
	double reqAns = 0;

	// // Case 1
	// if (AB_BE > 0) {

	// 	// Finding the magnitude
	// 	double y = E.y - B.y;
	// 	double x = E.x - B.x;
	// 	reqAns = sqrt(x * x + y * y);
	// }

	// // Case 2
	// else if (AB_AE < 0) {
	// 	double y = E.y - A.y;
	// 	double x = E.x - A.x;
	// 	reqAns = sqrt(x * x + y * y);
	// }

	// // Case 3
	// else {

		// Finding the perpendicular distance
		double x1 = AB.F;
		double y1 = AB.S;
		double x2 = AE.F;
		double y2 = AE.S;
		double mod = sqrt(x1 * x1 + y1 * y1);
		reqAns = abs(x1 * y2 - y1 * x2) / mod;
	// }
	return reqAns;
}


bool Geom::isInCircle(Circle &c, Point &A)
{
    return pow((A.x - c.Center().x),2) + pow((A.y - c.Center().y),2) <= pow(c.Radius(),2);
}

//https://www.geeksforgeeks.org/check-line-touches-intersects-circle/
bool Geom::crossCircle(Point &p1, Point &p2, Circle &circle)
{
    double a = p1.y - p2.y; 
    double b = p2.x - p1.x;
    double c = -1.0 * (a * p1.x + b * p1.y);
    Point center = circle.Center();
    double dist = (abs(a*center.x + b*center.y + c))/sqrt(a*a + b*b);
    return circle.Radius() > dist;
}