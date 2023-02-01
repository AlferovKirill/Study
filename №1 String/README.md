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

<p>
s1 =<br>
s2 = 123<br>
s3 = 111<br>
s4 = 111<br>
s5 = abcd<br>
--------------------------<br>
s2 = s4;<br>
s2 = 111<br>
s4 = 111<br>
--------------------------<br>
s4.len() = 3<br>
s4[1] = '5';<br>
s4 = 151<br>
s5[3] = d<br>
--------------------------<br>
s1 = 12345<br>
s2 = 54321<br>
--------------------------<br>
s1 == s2: 0<br>
s1 != s2: 1<br>
--------------------------<br>
s1 < s2: 1<br>
s2 < s1: 0<br>
s1 <= s2: 1<br>
s2 <= s1: 0<br>
--------------------------<br>
s1 > s2: 0<br>
s2 > s1: 1<br>
s1 >= s2: 0<br>
s2 >= s1: 1<br>
--------------------------<br>
s1 = abcd<br>
s2 = 123456<br>
--------------------------<br>
s1 == s2: 0<br>
s1 != s2: 1<br>
--------------------------<br>
s1 < s2: 1<br>
s2 < s1: 0<br>
s1 <= s2: 1<br>
s2 <= s1: 0<br>
--------------------------<br>
s1 > s2: 0<br>
s2 > s1: 1<br>
s1 >= s2: 0<br>
s2 >= s1: 1<br>
--------------------------<br>
s1 = ba10<br>
s2 = ba10<br>
--------------------------<br>
s1 == s2: 1<br>
s1 != s2: 0<br>
--------------------------<br>
s1 < s2: 0<br>
s2 < s1: 0<br>
s1 <= s2: 1<br>
s2 <= s1: 1<br>
--------------------------<br>
s1 > s2: 0<br>
s2 > s1: 0<br>
s1 >= s2: 1<br>
s2 >= s1: 1<br>
--------------------------<br>
s1 = vfrert<br>
s2 = 111<br>
--------------------------<br>
s1 == s2: 0<br>
s1 != s2: 1<br>
--------------------------<br>
s1 < s2: 0<br>
s2 < s1: 1<br>
s1 <= s2: 0<br>
s2 <= s1: 1<br>
--------------------------<br>
s1 > s2: 1<br>
s2 > s1: 0<br>
s1 >= s2: 1<br>
s2 >= s1: 0<br>
--------------------------<br>
</p>
