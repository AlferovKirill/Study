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
  <li>src/test.cpp - файdл с тестами.</li>
  <li>CMakeLists.txt - файл сборки.</li>
</ul>

<h1 align="center">Test</h1>
<p align="justify">Консольный вывод (test.cpp):</p>

<p>

                ~~~ Square ~~~
-----------------------------------------------<br>
Points:(0, 0) (2, 0) (2, 2) (0, 2)<br>
Shape area #1 = 4, perimeter #1 = 8<br>

Points:(0, 0) (2, 0) (2, 2) (0, 2)<br>
Shape area #2 = 4, perimeter #2 = 8<br>

(shape_1 == shape_2) = 1<br>
congruence(shape_1, shape_2) = 1<br>
similarity(shape_1, shape_2) = 1<br>
-----------------------------------------------<br>
-----------------------------------------------<br>
Points:(0, 0) (2, 0) (2, 2) (0, 2)<br>
Shape area #1 = 4, perimeter #1 = 8<br>

Points:(2, 2) (4, 2) (4, 4) (2, 4)<br>
Shape area #2 = 4, perimeter #2 = 8<br>

(shape_1 == shape_2) = 0<br>
congruence(shape_1, shape_2) = 1<br>
similarity(shape_1, shape_2) = 1<br>
-----------------------------------------------<br>
-----------------------------------------------<br>
Points:(0, 0) (2, 0) (2, 2) (0, 2)<br>
Shape area #1 = 4, perimeter #1 = 8<br>

Points:(2, 2) (8, 2) (8, 8) (2, 8)<br>
Shape area #2 = 36, perimeter #2 = 24<br>

(shape_1 == shape_2) = 0<br>
congruence(shape_1, shape_2) = 0<br>
similarity(shape_1, shape_2) = 1<br>
-----------------------------------------------<br>

                ~~~ Rectangle ~~~
  
-----------------------------------------------<br>
Points:(0, 0) (2, 0) (2, 1) (0, 1)<br>
Shape area #1 = 2, perimeter #1 = 6<br>

Points:(0, 0) (2, 0) (2, 1) (0, 1)<br>
Shape area #2 = 2, perimeter #2 = 6<br>

(shape_1 == shape_2) = 1<br>
congruence(shape_1, shape_2) = 1<br>
similarity(shape_1, shape_2) = 1<br>
-----------------------------------------------<br>
-----------------------------------------------<br>
Points:(0, 0) (2, 0) (2, 1) (0, 1)<br>
Shape area #1 = 2, perimeter #1 = 6<br>

Points:(2, 2) (4, 2) (4, 3) (2, 3)<br>
Shape area #2 = 2, perimeter #2 = 6<br>

(shape_1 == shape_2) = 0<br>
congruence(shape_1, shape_2) = 1<br>
similarity(shape_1, shape_2) = 1<br>
-----------------------------------------------<br>
-----------------------------------------------<br>
Points:(0, 0) (2, 0) (2, 1) (0, 1)<br>
Shape area #1 = 2, perimeter #1 = 6<br>

Points:(2, 2) (6, 2) (6, 4) (2, 4)<br>
Shape area #2 = 8, perimeter #2 = 12<br>

(shape_1 == shape_2) = 0<br>
congruence(shape_1, shape_2) = 0<br>
similarity(shape_1, shape_2) = 1<br>
-----------------------------------------------<br>

                ~~~ Polygon ~~~
-----------------------------------------------<br>
Points:(0, 1) (1, 2) (2, 1) (2, 0) (0, 0)<br>
Shape area #1 = 3, perimeter #1 = 6.82843<br>

Points:(0, 1) (1, 2) (2, 1) (2, 0) (0, 0)<br>
Shape area #2 = 3, perimeter #2 = 6.82843<br>

(shape_1 == shape_2) = 1<br>
congruence(shape_1, shape_2) = 1<br>
similarity(shape_1, shape_2) = 1<br>
-----------------------------------------------<br>
-----------------------------------------------<br>
Points:(0, 1) (1, 2) (2, 1) (2, 0) (0, 0)<br>
Shape area #1 = 3, perimeter #1 = 6.82843<br>

Points:(2, 3) (3, 4) (4, 3) (4, 2) (2, 2)<br>
Shape area #2 = 3, perimeter #2 = 6.82843<br>

(shape_1 == shape_2) = 0<br>
congruence(shape_1, shape_2) = 1<br>
similarity(shape_1, shape_2) = 1<br>
-----------------------------------------------<br>
-----------------------------------------------<br>
Points:(0, 1) (1, 2) (2, 1) (2, 0) (0, 0)<br>
Shape area #1 = 3, perimeter #1 = 6.82843<br>

Points:(2, 4) (4, 6) (6, 4) (6, 2) (2, 2)<br>
Shape area #2 = 12, perimeter #2 = 13.6569<br>

(shape_1 == shape_2) = 0<br>
congruence(shape_1, shape_2) = 0<br>
similarity(shape_1, shape_2) = 1<br>
-----------------------------------------------<br>

                ~~~ Triangle ~~~
-----------------------------------------------<br>
Points:(2, 1) (1, 2) (0, 1)<br>
Shape area #1 = 1, perimeter #1 = 4.82843<br>

Points:(2, 1) (1, 2) (0, 1)<br>
Shape area #2 = 1, perimeter #2 = 4.82843<br>

(shape_1 == shape_2) = 1<br>
congruence(shape_1, shape_2) = 1<br>
similarity(shape_1, shape_2) = 1<br>
-----------------------------------------------<br>
-----------------------------------------------<br>
Points:(2, 1) (1, 2) (0, 1)<br>
Shape area #1 = 1, perimeter #1 = 4.82843<br>

Points:(4, 3) (3, 4) (2, 3)<br>
Shape area #2 = 1, perimeter #2 = 4.82843<br>

(shape_1 == shape_2) = 0<br>
congruence(shape_1, shape_2) = 1<br>
similarity(shape_1, shape_2) = 1<br>
-----------------------------------------------<br>
-----------------------------------------------<br>
Points:(2, 1) (1, 2) (0, 1)<br>
Shape area #1 = 1, perimeter #1 = 4.82843<br>

Points:(6, 4) (4, 6) (2, 4)<br>
Shape area #2 = 4, perimeter #2 = 9.65685<br>

(shape_1 == shape_2) = 0<br>
congruence(shape_1, shape_2) = 0<br>
similarity(shape_1, shape_2) = 1<br>
-----------------------------------------------<br>

                ~~~ Circle ~~~
-----------------------------------------------<br>
Points:(1, 1)<br>
Shape area #1 = 12.5664, perimeter #1 = 12.5664<br>

Points:(1, 1)<br>
Shape area #2 = 12.5664, perimeter #2 = 12.5664<br>

(shape_1 == shape_2) = 1<br>
congruence(shape_1, shape_2) = 1<br>
similarity(shape_1, shape_2) = 1<br>
-----------------------------------------------<br>
-----------------------------------------------<br>
Points:(1, 1)<br>
Shape area #1 = 12.5664, perimeter #1 = 12.5664<br>

Points:(1, 3)<br>
Shape area #2 = 12.5664, perimeter #2 = 12.5664<br>

(shape_1 == shape_2) = 0<br>
congruence(shape_1, shape_2) = 1<br>
similarity(shape_1, shape_2) = 1<br>
-----------------------------------------------<br>
-----------------------------------------------<br>
Points:(1, 1)<br>
Shape area #1 = 12.5664, perimeter #1 = 12.5664<br>

Points:(1, 0)<br>
Shape area #2 = 78.5398, perimeter #2 = 31.4159<br>

(shape_1 == shape_2) = 0<br>
congruence(shape_1, shape_2) = 0<br>
similarity(shape_1, shape_2) = 1<br>
-----------------------------------------------<br>

                ~~~ Ellipse ~~~
-----------------------------------------------<br>
Points:(1, 1)<br>
Shape area #1 = 25.1327, perimeter #1 = 18.8496<br>

Points:(1, 1)<br>
Shape area #2 = 25.1327, perimeter #2 = 18.8496<br>

(shape_1 == shape_2) = 1<br>
congruence(shape_1, shape_2) = 1<br>
similarity(shape_1, shape_2) = 1<br>
-----------------------------------------------<br>
-----------------------------------------------<br>
Points:(1, 1)<br>
Shape area #1 = 25.1327, perimeter #1 = 18.8496<br>

Points:(1, 3)<br>
Shape area #2 = 25.1327, perimeter #2 = 18.8496<br>

(shape_1 == shape_2) = 0<br>
congruence(shape_1, shape_2) = 1<br>
similarity(shape_1, shape_2) = 1<br>
-----------------------------------------------<br>
-----------------------------------------------<br>
Points:(1, 1)<br>
Shape area #1 = 25.1327, perimeter #1 = 18.8496<br>

Points:(1, 0)<br>
Shape area #2 = 226.195, perimeter #2 = 56.5487<br>

(shape_1 == shape_2) = 0<br>
congruence(shape_1, shape_2) = 0<br>
similarity(shape_1, shape_2) = 1<br>
</p>
