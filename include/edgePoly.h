#ifndef EDGEPOLY_H
#define EDGEPOLY_H

#include "geometry.h"
#include <SFML/Graphics/VertexArray.hpp>

class edgePoly
{

public:

    sf::VertexArray smallPoly, bigPoly;

    Line* edges[4];

    edgePoly(sf::Vertex square[4]);

    void split(Line const& splitLine);
};

#endif // EDGEPOLY_H
