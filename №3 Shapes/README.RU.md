<h1 align="center">Shapes</h1>
<h4>На других языках: <a href="https://github.com/AlferovKirill/Study/blob/main/№3%20Shapes/README.md">English</a></h4>

<p align="justify">Shapes - мой проект с иерархией базовых геометрических плоских фигур. Всего шесть типов фигур: квадрат, прямоугольник, треугольник, многоугольник, окружность и эллипс. Все фигуры базируются на абстракном классе Shape, у которого есть виртуальный деструктор по умолчанию и пять чисто виртуальных методов: подсчеты площади, периметра и проверки на равенство, конгруэнтность и подобие.</p>

<p align="justify">Так как реализация фигур была основана на декартовых координатах, то для всех фигур помимо функций подобия и конгруэнтности (прим. понятие равенства для геометрических фигур)  был реализован и оператор равенства, который будет выдавать истинное значение в случае, когда фигуры совпадают по всем своим параметрам (длины сторон, углы и одинаковое расположение на осях координат, т. е. одинаковые координаты).</p>

<p align="justify">Для удобства реализации была создана структура Point с открытыми полями для хранения координат точки на декартовой плоскости. Также для нее был перегружен оператор вывода.</p>

<p align="justify">Всё декомпозировано. Файлы:</p>
<ul>
  <li>inc/Point.h - заголовочный файл с объявлением класса Point и перегрузкой для его объектов потока вывода.</li>
  <li>inc/Shapes.h - заголовочный файл с объявлением всех классов фигур и необходимых функций.</li>
  <li>src/Point.cpp - файл реализации с определением всех функций класса Point и перегрузкой потока вывода.</li>
  <li>src/Shapes.cpp - файл реализации с определением всех функций классов фигур и других необходимых функций.</li>
  <li>src/test.cpp - файлик с тестами.</li>
  <li>CMakeLists.txt - файл сборки.</li>
</ul>

<h1 align="center">Test</h1>
<p align="justify">Консольный вывод (test.cpp):</p>

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
