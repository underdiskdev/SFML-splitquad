#include <SFML/Graphics.hpp>
#include <iostream>

#include "roundline.h"
#include "geometry.h"
#include "edgePoly.h"

using namespace sf;


int main()
{

    Vertex square[4] =
    {

        Vertex(Vector2f(0, 0), Color::Green),
        Vertex(Vector2f(100, 0), Color::Green),
        Vertex(Vector2f(100, 100), Color::Green),
        Vertex(Vector2f(0, 100), Color::Green)

    };


    RenderWindow window(VideoMode(800, 600, 32), "Algooooo");

    Vector2f mousePos;

    edgePoly poly(square);

    Line cutLine(Vector2f(100, 0), Vector2f(0, 100));

    poly.split(cutLine);

    VertexArray cut = poly.bigPoly;







    while(window.isOpen())
    {

        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
            {
                window.close();
            }
        }

        window.clear();

        //DRAW



        window.draw(square, 4, Quads);
        window.draw(cut);


        //END DRAW

        window.display();

    }

    return EXIT_SUCCESS;
}
