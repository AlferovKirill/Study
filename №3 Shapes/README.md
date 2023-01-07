<h1 align="center">Shapes</h1>
<h4>Additional languages: <a href="https://github.com/AlferovKirill/Study/blob/main/№3%20Shapes/README.RU.md">Русский</a></h4>

<p align="justify">Shapes - project with a hierarchy of basic geometric 2D shapes. There are six types of shapes: square, rectangle, triangle, polygon, circle and ellipse. All shapes are based on the abstract class Shape, which has a default virtual destructor and five purely virtual methods: area, perimeter and operator==, congruence and similarity checks.</p>

<p align="justify">Because the realization of figures was based on Cartesian coordinates, for all figures other than the similarity and congruence functions (note, the equality concept for geometric figures) an equality operator was also realized which will return true value when the figures match in all their parameters (lengths of sides, angles and same location on coordinate axes, i.e. same coordinates).</p>

<p align="justify">For convenience, a Point structure with open fields was created to contain the coordinates of a point on the Cartesian plane. Also the output operator was overloaded.</p>

<p align="justify">Everything is decomposed. All files:</p>
<ul>
  <li>inc/Point.h - header file with the Point class declaration and overloading output stream.</li>
  <li>inc/Shapes.h - header file with declaration all the shape classes and necessary functions.</li>
  <li>src/Point.cpp - implementation file with the definition of all the Point class functions and overloaded output stream.</li>
  <li>src/Shapes.cpp - implementation file with the definition of all shape classes functions and all necessary functions.</li>
  <li>src/test.cpp - test file.</li>
  <li>CMakeLists.txt - build file.</li>
</ul>

<h1 align="center">Test</h1>
<p align="justify">Console output (test.cpp):</p>

```
                ~~~ Square ~~~
-----------------------------------------------
Points:(0, 0) (2, 0) (2, 2) (0, 2)
Shape area #1 = 4, perimeter #1 = 8

Points:(0, 0) (2, 0) (2, 2) (0, 2)
Shape area #2 = 4, perimeter #2 = 8

(shape_1 == shape_2) = 1
congruence(shape_1, shape_2) = 1
similarity(shape_1, shape_2) = 1
-----------------------------------------------
-----------------------------------------------
Points:(0, 0) (2, 0) (2, 2) (0, 2)
Shape area #1 = 4, perimeter #1 = 8

Points:(2, 2) (4, 2) (4, 4) (2, 4)
Shape area #2 = 4, perimeter #2 = 8

(shape_1 == shape_2) = 0
congruence(shape_1, shape_2) = 1
similarity(shape_1, shape_2) = 1
-----------------------------------------------
-----------------------------------------------
Points:(0, 0) (2, 0) (2, 2) (0, 2)
Shape area #1 = 4, perimeter #1 = 8

Points:(2, 2) (8, 2) (8, 8) (2, 8)
Shape area #2 = 36, perimeter #2 = 24

(shape_1 == shape_2) = 0
congruence(shape_1, shape_2) = 0
similarity(shape_1, shape_2) = 1
-----------------------------------------------

                ~~~ Rectangle ~~~
-----------------------------------------------
Points:(0, 0) (2, 0) (2, 1) (0, 1)
Shape area #1 = 2, perimeter #1 = 6

Points:(0, 0) (2, 0) (2, 1) (0, 1)
Shape area #2 = 2, perimeter #2 = 6

(shape_1 == shape_2) = 1
congruence(shape_1, shape_2) = 1
similarity(shape_1, shape_2) = 1
-----------------------------------------------
-----------------------------------------------
Points:(0, 0) (2, 0) (2, 1) (0, 1)
Shape area #1 = 2, perimeter #1 = 6

Points:(2, 2) (4, 2) (4, 3) (2, 3)
Shape area #2 = 2, perimeter #2 = 6

(shape_1 == shape_2) = 0
congruence(shape_1, shape_2) = 1
similarity(shape_1, shape_2) = 1
-----------------------------------------------
-----------------------------------------------
Points:(0, 0) (2, 0) (2, 1) (0, 1)
Shape area #1 = 2, perimeter #1 = 6

Points:(2, 2) (6, 2) (6, 4) (2, 4)
Shape area #2 = 8, perimeter #2 = 12

(shape_1 == shape_2) = 0
congruence(shape_1, shape_2) = 0
similarity(shape_1, shape_2) = 1
-----------------------------------------------

                ~~~ Polygon ~~~
-----------------------------------------------
Points:(0, 1) (1, 2) (2, 1) (2, 0) (0, 0)
Shape area #1 = 3, perimeter #1 = 6.82843

Points:(0, 1) (1, 2) (2, 1) (2, 0) (0, 0)
Shape area #2 = 3, perimeter #2 = 6.82843

(shape_1 == shape_2) = 1
congruence(shape_1, shape_2) = 1
similarity(shape_1, shape_2) = 1
-----------------------------------------------
-----------------------------------------------
Points:(0, 1) (1, 2) (2, 1) (2, 0) (0, 0)
Shape area #1 = 3, perimeter #1 = 6.82843

Points:(2, 3) (3, 4) (4, 3) (4, 2) (2, 2)
Shape area #2 = 3, perimeter #2 = 6.82843

(shape_1 == shape_2) = 0
congruence(shape_1, shape_2) = 1
similarity(shape_1, shape_2) = 1
-----------------------------------------------
-----------------------------------------------
Points:(0, 1) (1, 2) (2, 1) (2, 0) (0, 0)
Shape area #1 = 3, perimeter #1 = 6.82843

Points:(2, 4) (4, 6) (6, 4) (6, 2) (2, 2)
Shape area #2 = 12, perimeter #2 = 13.6569

(shape_1 == shape_2) = 0
congruence(shape_1, shape_2) = 0
similarity(shape_1, shape_2) = 1
-----------------------------------------------

                ~~~ Triangle ~~~
-----------------------------------------------
Points:(2, 1) (1, 2) (0, 1)
Shape area #1 = 1, perimeter #1 = 4.82843

Points:(2, 1) (1, 2) (0, 1)
Shape area #2 = 1, perimeter #2 = 4.82843

(shape_1 == shape_2) = 1
congruence(shape_1, shape_2) = 1
similarity(shape_1, shape_2) = 1
-----------------------------------------------
-----------------------------------------------
Points:(2, 1) (1, 2) (0, 1)
Shape area #1 = 1, perimeter #1 = 4.82843

Points:(4, 3) (3, 4) (2, 3)
Shape area #2 = 1, perimeter #2 = 4.82843

(shape_1 == shape_2) = 0
congruence(shape_1, shape_2) = 1
similarity(shape_1, shape_2) = 1
-----------------------------------------------
-----------------------------------------------
Points:(2, 1) (1, 2) (0, 1)
Shape area #1 = 1, perimeter #1 = 4.82843

Points:(6, 4) (4, 6) (2, 4)
Shape area #2 = 4, perimeter #2 = 9.65685

(shape_1 == shape_2) = 0
congruence(shape_1, shape_2) = 0
similarity(shape_1, shape_2) = 1
-----------------------------------------------

                ~~~ Circle ~~~
-----------------------------------------------
Points:(1, 1)
Shape area #1 = 12.5664, perimeter #1 = 12.5664

Points:(1, 1)
Shape area #2 = 12.5664, perimeter #2 = 12.5664

(shape_1 == shape_2) = 1
congruence(shape_1, shape_2) = 1
similarity(shape_1, shape_2) = 1
-----------------------------------------------
-----------------------------------------------
Points:(1, 1)
Shape area #1 = 12.5664, perimeter #1 = 12.5664

Points:(1, 3)
Shape area #2 = 12.5664, perimeter #2 = 12.5664

(shape_1 == shape_2) = 0
congruence(shape_1, shape_2) = 1
similarity(shape_1, shape_2) = 1
-----------------------------------------------
-----------------------------------------------
Points:(1, 1)
Shape area #1 = 12.5664, perimeter #1 = 12.5664

Points:(1, 0)
Shape area #2 = 78.5398, perimeter #2 = 31.4159

(shape_1 == shape_2) = 0
congruence(shape_1, shape_2) = 0
similarity(shape_1, shape_2) = 1
-----------------------------------------------

                ~~~ Ellipse ~~~
-----------------------------------------------
Points:(1, 1)
Shape area #1 = 25.1327, perimeter #1 = 18.8496

Points:(1, 1)
Shape area #2 = 25.1327, perimeter #2 = 18.8496

(shape_1 == shape_2) = 1
congruence(shape_1, shape_2) = 1
similarity(shape_1, shape_2) = 1
-----------------------------------------------
-----------------------------------------------
Points:(1, 1)
Shape area #1 = 25.1327, perimeter #1 = 18.8496

Points:(1, 3)
Shape area #2 = 25.1327, perimeter #2 = 18.8496

(shape_1 == shape_2) = 0
congruence(shape_1, shape_2) = 1
similarity(shape_1, shape_2) = 1
-----------------------------------------------
-----------------------------------------------
Points:(1, 1)
Shape area #1 = 25.1327, perimeter #1 = 18.8496

Points:(1, 0)
Shape area #2 = 226.195, perimeter #2 = 56.5487

(shape_1 == shape_2) = 0
congruence(shape_1, shape_2) = 0
similarity(shape_1, shape_2) = 1
```
