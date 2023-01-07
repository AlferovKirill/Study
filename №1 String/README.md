<h1 align="center">String</h1>
<h4>Additional languages: <a href="https://github.com/AlferovKirill/Study/blob/main/№1%20String/README.RU.md">Русский</a></h4>

<p align="justify">String - my implementation of a string class based on const char*. The standard C-operators were used to work with C-strings. Also added constructor from initialization list to make it possible to set string via curly braces.</p>

<p align="justify">Everything is decomposed. Files:</p>
<ul>
  <li>inc/String.h - header file with the declaration of the class and all necessary functions.</li>
  <li>src/String.cpp - implementation file with the definition of all class's functions.</li>
  <li>src/test.cpp - test file.</li>
  <li>CMakeLists.txt - build file.</li>
</ul>

<h1 align="center">Test</h1>
<p align="justify">Console output (test.cpp):</p>

```
s1 =
s2 = 123
s3 = 111
s4 = 111
s5 = abcd
--------------------------
s2 = s4;
s2 = 111
s4 = 111
--------------------------
s4.len() = 3
s4[1] = '5';
s4 = 151
s5[3] = d
--------------------------
s1 = 12345
s2 = 54321
--------------------------
s1 == s2: 0
s1 != s2: 1
--------------------------
s1 < s2: 1
s2 < s1: 0
s1 <= s2: 1
s2 <= s1: 0
--------------------------
s1 > s2: 0
s2 > s1: 1
s1 >= s2: 0
s2 >= s1: 1
--------------------------
s1 = abcd
s2 = 123456
--------------------------
s1 == s2: 0
s1 != s2: 1
--------------------------
s1 < s2: 1
s2 < s1: 0
s1 <= s2: 1
s2 <= s1: 0
--------------------------
s1 > s2: 0
s2 > s1: 1
s1 >= s2: 0
s2 >= s1: 1
--------------------------
s1 = ba10
s2 = ba10
--------------------------
s1 == s2: 1
s1 != s2: 0
--------------------------
s1 < s2: 0
s2 < s1: 0
s1 <= s2: 1
s2 <= s1: 1
--------------------------
s1 > s2: 0
s2 > s1: 0
s1 >= s2: 1
s2 >= s1: 1
--------------------------
s1 = vfrert
s2 = 111
--------------------------
s1 == s2: 0
s1 != s2: 1
--------------------------
s1 < s2: 0
s2 < s1: 1
s1 <= s2: 0
s2 <= s1: 1
--------------------------
s1 > s2: 1
s2 > s1: 0
s1 >= s2: 1
s2 >= s1: 0
--------------------------
```
