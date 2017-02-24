#SFML-splitquad
--------------

Some way to split SFML quads (4 vertices array) into 2.
CODE IS MESSY AND BUGGY AS HELL -> THIS IS A PROTOTYPE

-------------------



**How to use it ?**
---------------





First include both `geometry.h` and `edgePoly.h` files (will be changed in future version)

Then create an array of 4 vertices (Quad)

    Vertex square[4] =
    {

        Vertex(Vector2f(0, 0), Color::Green),
        Vertex(Vector2f(100, 0), Color::Green),
        Vertex(Vector2f(100, 100), Color::Green),
        Vertex(Vector2f(0, 100), Color::Green)

    };

Then create an *edgePoly* object with your VertexArray as argument

    edgePoly poly(square);

Then you will need a *Line* object to cut the Quad, a line is defined using 2 Vector2f, ***MAKE SURE THE LINE IS NOT STOPPING IN THE QUAD OR BAD STUFF WILL HAPPEN.***

    Line cutLine(Vector2f(100, 0), Vector2f(0, 100));
    
Then you can create the polygons by doing 

`poly.split(cutLine);`

note that this is a **void** method.

Then you can take `poly.smallPoly` and `poly.bigPoly`

***THESE NAMES ARE HORRIBLE I KNOW, I DON'T KNOW HOW TO EXPORT THEM CORRECTLY FOR NOW, I'M THINKING OF IT. AND ALSO THE COLOR OF THEM WILL ALWAYS BE WHITE, FOR THE SAME REASON***

These polys are either (depends on how the line cuts the quad) :

 - 3 vertices array (*smallPoly*) and 5 vertices array (*bigPoly*)
 **or**
 - 4 vertices array for both *smallPoly* and *bigPoly*
 
This is very bad I know don't yell at me please.


----------



**Concerning the Line class**
---------------------------

The *Line* class is basically just two Vector2f, but you have some static methods to use, these are only in the `geometry.h` file. And the code is less messy.

**Know if two line intersect :**

Here's the definition: 

    static bool doIntersect(const Line& line1, const Line& line2);

Example:

`bool linesIntersect = Line::doIntersect(line1, line2);`



**Know the intersection point of two lines :**

Here's the definition :

    static Vector2f getIntersecPoint(const Line& line1, const Line& line2);
Example :

    Vector2f intersectionPoint = Line::getIntersecPoint(line1, line2);

Note : if there is none, the method will return "`null2f`", that is just a `Vector2f(NULL, NULL)`

**Know if a point is on a segment :**

Here's the definition : 
`static bool IsOnSegment(Line line, Vector2f k);`

Example :

    bool onSegment = Line::IsOnSegment(line, point);

**Know if two lines are connected :**

Here's the definition :

        static bool areConnected(Line* a, Line* b);

Please note there are ***pointers***.

Example :

    bool linesConnected = Line::areConnected(*line1, *line2);
