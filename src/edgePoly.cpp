#include "edgePoly.h"


using namespace sf;

    edgePoly::edgePoly(Vertex square[4])
    {
        edges[0] = new Line(square[0].position, square[1].position);
        edges[1] = new Line(square[1].position, square[2].position);
        edges[2] = new Line(square[2].position, square[3].position);
        edges[3] = new Line(square[3].position, square[0].position);
    }

    void edgePoly::split(Line const& splitLine)
    {
        Vector2f p[2];
        int i;
        unsigned int side[2];
        int o;
        for(o=0; o<=1; o++)
        {
            for(i=0; i<=3; i++)
            {

                if(Line::doIntersect(splitLine, *edges[i]))
                {
                    p[o] = Line::getIntersecPoint(splitLine, *edges[i]);
                    side[o] = i;
                    if(p[0] != p[1]) break;
                }

            }
        }




        if(Line::areConnected(edges[side[0]], edges[side[1]]))
        {
            //EDGES ARE ADJACENT!!!

            Vector2f iPoint = edges[side[1]]->p1;

            smallPoly.resize(3);
            bigPoly.resize(5);

            smallPoly[0] = Vertex(p[0], Color::White);
            smallPoly[1] = Vertex(p[1], Color::White);
            smallPoly[2] = Vertex(iPoint, Color::White);
            smallPoly.setPrimitiveType(Triangles);


            unsigned int sideBuffer[2];

            o = 0;

            for(i=0; i<=3; i++)
            {

                if(edges[side[0]]->p1 != edges[i]->p1 && edges[side[1]]->p1 != edges[i]->p1)
                {
                    sideBuffer[o] = i;
                    o++;
                }

            }

            Vector2f _temp = Line::getIntersecPoint(*edges[sideBuffer[0]], *edges[sideBuffer[1]]);

            bigPoly[0] = Vertex(p[0], Color::White);
            bigPoly[1] = Vertex(p[1], Color::White);
            bigPoly[2] = Vertex(edges[side[1]]->p2, Color::White);
            bigPoly[3] = Vertex(_temp, Color::White);
            bigPoly[4] = Vertex(edges[side[0]]->p1, Color::White);
            bigPoly.setPrimitiveType(TrianglesFan);



        }
        else
        {
            //EDGES ARE OPPOSITE!!
            smallPoly.resize(4);
            bigPoly.resize(4);

            smallPoly[0] = Vertex(p[0], Color::White);
            smallPoly[1] = Vertex(edges[side[0]]->p1, Color::White);
            smallPoly[2] = Vertex(edges[side[1]]->p2, Color::White);
            smallPoly[3] = Vertex(p[1], Color::White);

            bigPoly[0] = Vertex(p[0], Color::White);
            bigPoly[1] = Vertex(edges[side[0]]->p2, Color::White);
            bigPoly[2] = Vertex(edges[side[1]]->p1, Color::White);
            bigPoly[3] = Vertex(p[1], Color::White);


            smallPoly.setPrimitiveType(Quads);
            bigPoly.setPrimitiveType(Quads);

        }


    }




