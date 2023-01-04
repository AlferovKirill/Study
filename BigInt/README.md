<h1 align="center">BigInt</h1>
<h4>Additional languages: <a href="https://github.com/AlferovKirill/Study/blob/main/BigInt/README.RU.md">Русский</a></h4>

<p align="justify">BigInt - my implementation of a class big integers based on const char* (C-style strings). This means that the number is stored as a C-string, and all operations on it are done by manipulating it.</p>

<p align="justify">For implementetion arithmetic operations ("+", "-", "*", "/" and "%") were used standard "school algorithms" in the form of addition, subtraction and etc in columns. Because it was unreasonable to use more difficult and efficient algorithms, because it would take much more time to learn them than writing a class of large integers.</p>

<p align="justify">I would be very happy if someone would be interested and help me to implement these algorithms in this class with practical advice on searching for relevant literature and textbooks.</p>

<p align="justify">Everything is decomposed. Files:</p>

<ul>
  <li>inc/BigInt.h - header file with the declaration of the class and all necessary functions.</li>
  <li>src/BigInt.cpp - implementation file with the definition of all class's functions.</li>
  <li>src/test.cpp - test file.</li>
  <li>CMakeLists.txt - build file.</li>
</ul>
