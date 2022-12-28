<h1 align="center">BigInt</h1>
<h4>Additional languages: <a href="https://github.com/AlferovKirill/Study/blob/main/BigInt/README.RU.md">Русский</a></h4>

<p align="justify">BigInt is my implementation of a class of big numbers based on const char* (C-style strings). That is, the number is stored as a string and all operations on it happen as a result of manipulation with it.</p>

<p align="justify">To implement arithmetic operations ("+", "-", "*", "/" and "%") standard "school algorithms" in the form of addition, subtraction, etc. in columns were used. Since the use of more complex and efficient algorithms was inexpedient, because it was necessary to spend much more time to learn them than to write a class of large numbers.</p>

<p align="justify">I would be very happy if someone would be interested and help me to implement these algorithms in the conditions of this class with practical advice on finding appropriate literature and tutorials.</p>

<p align="justify">Everything is decomposed. Files:</p>

<ul>
  <li>inc/BigInt.h - header file with the declaration of the class and all necessary functions.</li>
  <li>src/BigInt.cpp - implementation file with the definition of all class's functions.</li>
  <li>src/test.cpp - test file.</li>
  <li>CMakeLists.txt - build file.</li>
</ul>
