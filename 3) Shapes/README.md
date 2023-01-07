<h1 align="center">Shapes</h1>
<h4>Additional languages: <a href="https://github.com/AlferovKirill/Study/blob/main/Shapes/README.RU.md">Русский</a></h4>

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

```
code
```
