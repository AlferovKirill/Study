#include "../inc/Matrix.h"

int main() {
	Matrix<3, 3> matrix1;

	matrix1[0][0] = 1; matrix1[0][1] = 0; matrix1[0][2] = -1;
	matrix1[1][0] = 1; matrix1[1][1] = 0; matrix1[1][2] = -1;
	matrix1[2][0] = 1; matrix1[2][1] = 0; matrix1[2][2] = -1;

	matrix1.printConsole();
	std::cout << "------------------" << std::endl;

	Matrix<3, 3> matrix2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Matrix<3, 3> matrix3 = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

	matrix2.printConsole();
	std::cout << std::endl;

	matrix3.printConsole();
	std::cout << "------------------" << std::endl;

	Matrix<1, 3> matrix4 = { 1, 2, 3 };
	Matrix<1, 3> matrix5 = { {1, 2, 3} };

	matrix4.printConsole();
	std::cout << std::endl;

	matrix5.printConsole();
	std::cout << "------------------" << std::endl;

	Matrix<3, 1> matrix6 = { 1, 2, 3 };
	Matrix<3, 1> matrix7 = { {1, 2, 3} };

	matrix6.printConsole();
	std::cout << std::endl;

	matrix7.printConsole();
	std::cout << "------------------" << std::endl;
}