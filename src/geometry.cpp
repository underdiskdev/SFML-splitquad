#include "geometry.h"

using namespace sf;

bool Line::IsOnSegment(Line line, Vector2f k)
{
    Vector2f i, j;

    i.x = line.p1.x;
    i.y = line.p1.y;
    j.x = line.p2.x;
    j.y = line.p2.y;

    return (i.x <= k.x || j.x <= k.x) && (k.x <= i.x || k.x <= j.x) &&
           (i.y <= k.y || j.y <= k.y) && (k.y <= i.y || k.y <= j.y);
}

/** Do line segments (x1, y1)--(x2, y2) and (x3, y3)--(x4, y4) intersect? */


Line::Line(Vector2f vec1, Vector2f vec2)
{
    p1 = vec1;
    p2 = vec2;
}

Line::Line()
{
    p1 = Vector2f(0,0);
    p2 = Vector2f(0,0);
}

Vector2f Line::getIntersecPoint(const Line& line1, const Line& line2)
{

    float x1 = line1.p1.x, x2 = line1.p2.x, x3 = line2.p1.x, x4 = line2.p2.x;
    float y1 = line1.p1.y, y2 = line1.p2.y, y3 = line2.p1.y, y4 = line2.p2.y;

    float d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    // If d is zero, there is no intersection
    if (d == 0) return Vector2f(NULL, NULL);

    // Get the x and y
    float pre = (x1*y2 - y1*x2), post = (x3*y4 - y3*x4);
    float x = ( pre * (x3 - x4) - (x1 - x2) * post ) / d;
    float y = ( pre * (y3 - y4) - (y1 - y2) * post ) / d;

    // Check if the x and y coordinates are within both lines
    if ( x < std::min(x1, x2) || x > std::max(x1, x2) || x < std::min(x3, x4) || x > std::max(x3, x4) ) return Vector2f(NULL, NULL);
    if ( y < std::min(y1, y2) || y > std::max(y1, y2) || y < std::min(y3, y4) || y > std::max(y3, y4) ) return Vector2f(NULL, NULL);

    //Return the point of intersection

    return Vector2f(x, y);

}

bool Line::areConnected(Line* a, Line* b)
{
    if(a->p1 == b->p2 || a->p2 == b->p1)
    {
        return true;
    }

    return false;
}

bool Line::doIntersect(Line const& a, Line const& b)
{


    return !(Line::getIntersecPoint(a, b) == null2f);

}

