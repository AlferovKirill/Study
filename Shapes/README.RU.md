<h1 align="center">Shapes</h1>
<h4>На других языках: <a href="https://github.com/AlferovKirill/Study/blob/main/Shapes/README.md">English</a></h4>

<p align="justify">Shapes - мой проект с иерархией базовых геометрических плоских фигур. Всего шесть типов фигур: квадрат, прямоугольник, треугольник, многоугольник, окружность и эллипс. Все фигуры базируются на абстракном классе Shape, у которого есть виртуальный деструктор по умолчанию и пять чисто виртуальных методов: подсчеты площади, периметра и проверки на равенство, конгруэнтность и подобие.</p>

<p align="justify">Так как реализация фигур была основана на декартовых координатах, то для всех фигур помимо функций подобия и конгруэнтности (прим. понятие равенства для геометрических фигур)  был реализован и оператор равенства, который будет выдавать истинное значение в случае, когда фигуры совпадают по всем своим параметрам (длины сторон, углы и одинаковое расположение на осях координат, т. е. одинаковые координаты).</p>

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
