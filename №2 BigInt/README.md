<h1 align="center">BigInt</h1>
<h4>Additional languages: <a href="https://github.com/AlferovKirill/Study/blob/main/№2%20BigInt/README.RU.md">Русский</a></h4>

<p align="justify">BigInt - my implementation of a class big integers based on const char* (C-style strings). This means that the number is stored as a C-string, and all operations on it are done by manipulating it.</p>

<p align="justify">For implementetion arithmetic operations ("+", "-", "*", "/" and "%") were used standard "school algorithms" in the form of addition, subtraction and etc in column. Because it was unreasonable to use more difficult and efficient algorithms, because it would take much more time to learn them than writing a class of big integers.</p>

<p align="justify">I would be very happy if someone would be interested and help me to implement these algorithms in this class with practical advice on searching for relevant literature and textbooks.</p>

<p align="justify">Everything is decomposed. Files:</p>

<ul>
  <li>inc/BigInt.h - header file with the declaration of the class and all necessary functions.</li>
  <li>src/BigInt.cpp - implementation file with the definition of all class's functions.</li>
  <li>src/test.cpp - test file.</li>
  <li>CMakeLists.txt - build file.</li>
</ul>

<h1 align="center">Test</h1>
<p align="justify">Console output (test.cpp):</p>

<p align="center">
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
