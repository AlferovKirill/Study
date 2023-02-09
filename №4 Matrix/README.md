<h1 align="center">Matrix</h1>
<h4>Additional languages: <a href="https://github.com/AlferovKirill/Study/blob/main/№4%20Matrix/README.RU.md">Русский</a></h4>

<p align="justify">Matrix - my implementation of a class of matrices. The task was to implement a template class of matrices and all the basic linear-algebraic operations on them: matrix multiplication/division by a number, sum and difference of matrices, transposition, finding the determinant and inverse matrix.</p>

<p align="justify">All operations must check the validity of their use over operands at the compilation time ( For example, multiplying matrices by each other is possible only if the first one has the same number of columns as the number of rows of the second one).</p>

<p align="justify">In the process of decomposing the project and decomposing class and function declarations with their definitions, I had a problem with the linker, when during preprocessing and compilation we get two object files: one with declaration and implementation of template class and functions, and another (main) with declaration and use of their specific version.</p>

<p align="justify">The problem is that at the time of linking the compiler did not find in the implementation file specific implementations of template functions and classes to use them in main, because at the time of compilation he did not know what happens in the branch main and what specific versions of template classes and functions he needs.</p>

<p align="justify">I solved this problem by combining class and function declarations and definitions in one .hpp file. Files:</p>
<ul>
  <li>inc/Matrix.hpp - header file with the declaration and definition of the class and all necessary functions.</li>
  <li>src/test.cpp - test file.</li>
  <li>CMakeLists.txt - build file.</li>
</ul>

<h1 align="center">Test</h1>
<p align="justify">Console output (test.cpp):</p>

<p>Matrix #1<br>
1 1 1 1<br>
2 2 2 2<br>
3 3 3 3<br>
4 4 4 4<br>

Matrix #2<br>
1 1<br>
1 1<br>
1 1<br>
1 1<br>

Matrix #1 * Matrix #2 =<br>
4 4<br>
8 8<br>
12 12<br>
16 16<br>

Transpose Matrix #1<br>
1 2 3 4<br>
1 2 3 4<br>
1 2 3 4<br>
1 2 3 4<br>

Transpose Matrix #2<br>
1 1 1 1<br>
1 1 1 1<br>

------------------<br>
Matrix #3<br>
2 1<br>
3 4<br>

Matrix #4<br>
1 0 3<br>
4 2 1<br>

Matrix #3 * Matrix #4 =<br>
6 2 7<br>
19 8 13<br>

Transpose Matrix #3<br>
2 3<br>
1 4<br>

Transpose Matrix #4<br>
1 4<br>
0 2<br>
3 1<br>

------------------<br>
Matrix #5<br>
1 1<br>
1 1<br>

Matrix #5 * 8 =<br>
8 8<br>
8 8<br>

------------------<br>
Matrix #6<br>
3 3 3<br>
9 9 9<br>
6 6 6<br>

Matrix #6 / 3 =<br>
1 1 1<br>
3 3 3<br>
2 2 2<br>

------------------<br>
Matrix #7<br>
4 4<br>
4 4<br>

Matrix #8<br>
1 1<br>
1 1<br>

Matrix #7 + Matrix #8 =<br>
5 5<br>
5 5<br>

------------------<br>
Matrix #9<br>
7 7<br>
7 7<br>

Matrix #10<br>
1 1<br>
1 1<br>

Matrix #9 - Matrix #10 =<br>
6 6<br>
6 6<br>

------------------<br>
Matrix #11<br>
5 1 5 1<br>
1 1 5 5<br>
1 5 1 5<br>
1 5 5 1<br>

Matrix #11 det = 768<br>

Inverse Matrix #11 =<br>
0.229167 -0.125 0.104167 -0.125<br>
-0.0208333 -0.125 0.104167 0.125<br>
-0.0208333 0.125 -0.145833 0.125<br>
-0.0208333 0.125 0.104167 -0.125<br>

------------------<br>
Matrix #12<br>
3 1 2<br>
4 6 4<br>
8 7 9<br>

Matrix #12 det = 34<br>

Inverse Matrix #12 =<br>
0.764706 0.147059 -0.235294<br>
-0.117647 0.323529 -0.117647<br>
-0.588235 -0.382353 0.411765<br>

------------------<br>
Matrix #13<br>
1 2<br>
3 2<br>

Matrix #13 det = -4<br>

Inverse Matrix #13 =<br>
-0.5 0.5<br>
0.75 -0.25<br>

------------------<br>
Matrix #14<br>
2<br>

Matrix #14 det = 2<br>

Inverse Matrix #14 =<br>
0.5</p>

