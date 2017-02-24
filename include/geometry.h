#ifndef GEOMETRY_H
#define GEOMETRY_H

#define null2f Vector2f(NULL, NULL)

#include <SFML/System/Vector2.hpp>
#include <algorithm>



class Line
{
public:

    sf::Vector2f p1, p2;

    static bool doIntersect(const Line& line1, const Line& line2);
    static sf::Vector2f getIntersecPoint(const Line& line1, const Line& line2);
    static bool IsOnSegment(Line line, sf::Vector2f k);
    static bool areConnected(Line* a, Line* b);

    Line(sf::Vector2f vec1, sf::Vector2f vec2);
    Line();


};

#endif // GEOMETRY_H
