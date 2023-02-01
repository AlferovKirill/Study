<h1 align="center">BigInt</h1>
<h4>На других языках: <a href="https://github.com/AlferovKirill/Study/blob/main/№2%20BigInt/README.md">English</a></h4>

<p align="justify">BigInt - моя реализация класса больших чисел на базе const char* (C-style строк). То есть число хранится в виде строки и все операции над ним происходят в результате манипуляции с ней.</p>

<p align="justify">Для реализации арифметических операций («+», «-», «*», «/» и «%») использовались стандартные «школьные алгоритмы» в виде сложения, вычитания и т. д. в столбик. Так как использование более сложных и эффективных алгоритмов являлось нецелесообразным, ведь нужно было потратить гораздо больше времени на их изучение, чем само написание класса больших чисел.</p>

<p align="justify">Буду очень рад, если кто-то заинтересуется и поможет мне реализовать данные алгоритмы в условиях данного класса дельным советом по поиску подходящей литературы и обучающим материалам.</p>

<p align="justify">Всё декомпозировано. Файлы:</p>

<ul>
  <li>inc/BigInt.h - заголовочный файл с объявлением класса и всех необходимых функций.</li>
  <li>src/BigInt.cpp - файл реализации с определением всех функций класса.</li>
  <li>src/test.cpp - файл с тестами.</li>
  <li>CMakeLists.txt - файл сборки.</li>
</ul>

<h1 align="center">Test</h1>
<p align="justify">Консольный вывод (test.cpp):</p>

<p>
----------------------------------------<br>
BigInt #1 = 987654321987654321<br>
BigInt #2 = 111<br>
  
BigInt #1 + BigInt #2 = 987654321987654432<br>
BigInt #1 - BigInt #2 = 987654321987654210<br>
BigInt #1 * BigInt #2 = 109629629740629629631<br>
BigInt #1 / BigInt #2 = 8897786684573462<br>
BigInt #1 % BigInt #2 = 39<br>

BigInt #1 = 987654321987654321<br>
BigInt #2 = 111<br>

++BigInt #1 = 987654321987654322<br>
BigInt #1++ = 987654321987654322<br>
BigInt #1-- = 987654321987654323<br>
--BigInt #1 = 987654321987654321<br>

BigInt #1 = true<br>
BigInt #1.len() = 18<br>

BigInt #1 < BigInt #2 = 0<br>
BigInt #1 > BigInt #2 = 1<br>
BigInt #1 <= BigInt #2 = 0<br>
BigInt #1 >= BigInt #2 = 1<br>
BigInt #1 == BigInt #2 = 0<br>
BigInt #1 != BigInt #2 = 1<br>

----------------------------------------<br>
----------------------------------------<br>
BigInt #1 = 10<br>
BigInt #2 = 10<br>

BigInt #1 + BigInt #2 = 20<br>
BigInt #1 - BigInt #2 = 0<br>
BigInt #1 * BigInt #2 = 100<br>
BigInt #1 / BigInt #2 = 1<br>
BigInt #1 % BigInt #2 = 0<br>

BigInt #1 = 10<br>
BigInt #2 = 10<br>

++BigInt #1 = 11<br>
BigInt #1++ = 11<br>
BigInt #1-- = 12<br>
--BigInt #1 = 10<br>

BigInt #1 = true<br>
BigInt #1.len() = 2<br>

BigInt #1 < BigInt #2 = 0<br>
BigInt #1 > BigInt #2 = 0<br>
BigInt #1 <= BigInt #2 = 1<br>
BigInt #1 >= BigInt #2 = 1<br>
BigInt #1 == BigInt #2 = 1<br>
BigInt #1 != BigInt #2 = 0<br>

----------------------------------------<br>
----------------------------------------<br>
BigInt #1 = -12324<br>
BigInt #2 = 6<br>

BigInt #1 + BigInt #2 = -12318<br>
BigInt #1 - BigInt #2 = -12330<br>
BigInt #1 * BigInt #2 = -73944<br>
BigInt #1 / BigInt #2 = -2054<br>
BigInt #1 % BigInt #2 = 0<br>

BigInt #1 = -12324<br>
BigInt #2 = 6<br>

++BigInt #1 = -12323<br>
BigInt #1++ = -12323<br>
BigInt #1-- = -12322<br>
--BigInt #1 = -12324<br>

BigInt #1 = true<br>
BigInt #1.len() = 5<br>

BigInt #1 < BigInt #2 = 1<br>
BigInt #1 > BigInt #2 = 0<br>
BigInt #1 <= BigInt #2 = 1<br>
BigInt #1 >= BigInt #2 = 0<br>
BigInt #1 == BigInt #2 = 0<br>
BigInt #1 != BigInt #2 = 1<br>

----------------------------------------<br>
----------------------------------------<br>
Test all integers from -1000 to 1000.<br>
Number of tests = 3998000, total errors = 0<br>
Errors: sum = 0, difference = 0, multiplication = 0, division = 0, remainder = 0<br>
----------------------------------------<br>
</p>
