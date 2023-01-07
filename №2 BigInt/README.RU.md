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

```
----------------------------------------
BigInt #1 = 987654321987654321
BigInt #2 = 111

BigInt #1 + BigInt #2 = 987654321987654432
BigInt #1 - BigInt #2 = 987654321987654210
BigInt #1 * BigInt #2 = 109629629740629629631
BigInt #1 / BigInt #2 = 8897786684573462
BigInt #1 % BigInt #2 = 39

BigInt #1 = 987654321987654321
BigInt #2 = 111

++BigInt #1 = 987654321987654322
BigInt #1++ = 987654321987654322
BigInt #1-- = 987654321987654323
--BigInt #1 = 987654321987654321

BigInt #1 = true
BigInt #1.len() = 18

BigInt #1 < BigInt #2 = 0
BigInt #1 > BigInt #2 = 1
BigInt #1 <= BigInt #2 = 0
BigInt #1 >= BigInt #2 = 1
BigInt #1 == BigInt #2 = 0
BigInt #1 != BigInt #2 = 1

----------------------------------------
----------------------------------------
BigInt #1 = 10
BigInt #2 = 10

BigInt #1 + BigInt #2 = 20
BigInt #1 - BigInt #2 = 0
BigInt #1 * BigInt #2 = 100
BigInt #1 / BigInt #2 = 1
BigInt #1 % BigInt #2 = 0

BigInt #1 = 10
BigInt #2 = 10

++BigInt #1 = 11
BigInt #1++ = 11
BigInt #1-- = 12
--BigInt #1 = 10

BigInt #1 = true
BigInt #1.len() = 2

BigInt #1 < BigInt #2 = 0
BigInt #1 > BigInt #2 = 0
BigInt #1 <= BigInt #2 = 1
BigInt #1 >= BigInt #2 = 1
BigInt #1 == BigInt #2 = 1
BigInt #1 != BigInt #2 = 0

----------------------------------------
----------------------------------------
BigInt #1 = -12324
BigInt #2 = 6

BigInt #1 + BigInt #2 = -12318
BigInt #1 - BigInt #2 = -12330
BigInt #1 * BigInt #2 = -73944
BigInt #1 / BigInt #2 = -2054
BigInt #1 % BigInt #2 = 0

BigInt #1 = -12324
BigInt #2 = 6

++BigInt #1 = -12323
BigInt #1++ = -12323
BigInt #1-- = -12322
--BigInt #1 = -12324

BigInt #1 = true
BigInt #1.len() = 5

BigInt #1 < BigInt #2 = 1
BigInt #1 > BigInt #2 = 0
BigInt #1 <= BigInt #2 = 1
BigInt #1 >= BigInt #2 = 0
BigInt #1 == BigInt #2 = 0
BigInt #1 != BigInt #2 = 1

----------------------------------------
----------------------------------------
Test all integers from -1000 to 1000.
Number of tests = 3998000, total errors = 0
Errors: sum = 0, difference = 0, multiplication = 0, division = 0, remainder = 0
----------------------------------------
```
