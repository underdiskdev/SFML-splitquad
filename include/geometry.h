#ifndef GEOMETRY_H
#define GEOMETRY_H

#define null2f Vector2f(NULL, NULL)

#include <SFML/System/Vector2.hpp>
#include <algorithm>

namespace sf
{


class Line
{
public:

    Vector2f p1, p2;

    static bool doIntersect(const Line& line1, const Line& line2);
    static Vector2f getIntersecPoint(const Line& line1, const Line& line2);
    static bool IsOnSegment(Line line, Vector2f k);
    static char ComputeDirection(Vector2f const& i, Vector2f const& j, Vector2f const& k);
    static bool areConnected(Line* a, Line* b);

    Line(Vector2f vec1, Vector2f vec2);
    Line();


};


}

#endif // GEOMETRY_H
