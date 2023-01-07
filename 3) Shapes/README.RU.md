<h1 align="center">Shapes</h1>
<h4>На других языках: <a href="https://github.com/AlferovKirill/Study/blob/main/Shapes/README.md">English</a></h4>

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