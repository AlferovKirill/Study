<h1 align="center">BigInt</h1>
<h4>На других языках: <a href="https://github.com/AlferovKirill/Study/blob/main/BigInt/README.md">English</a></h4>

<p align="justify">BigInt - моя реализация класса больших чисел на базе const char* (C-style строк). То есть число хранится в виде строки и все операции над ним происходят в результате манипуляции с ней.</p>

<p align="justify">Для реализации арифметических операций («+», «-», «*», «/» и «%») использовались стандартные «школьные алгоритмы» в виде сложения, вычитания и т. д. в столбик. Так как использование более сложных и эффективных алгоритмов являлось нецелесообразным, ведь нужно было потратить гораздо больше времени на их изучение, чем само написание класса больших чисел.</p>

<p align="justify">Буду очень рад, если кто-то заинтересуется и поможет мне реализовать данные алгоритмы в условиях данного класса дельным советом по поиску подходящей литературы и обучающим материалам.</p>

<p align="justify">Всё декомпозировано. Файлы:</p>

<ul>
  <li>inc/BigInt.h - заголовочный файл с объявлением класса и всех необходимых функций.</li>
  <li>src/BigInt.cpp - файл реализации с определением всех функций класса.</li>
  <li>src/test.cpp - файлик с тестами.</li>
  <li>CMakeLists.txt - файл сборки.</li>
</ul>

<h1 align="center">Test</h1>