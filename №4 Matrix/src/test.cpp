#include "../inc/Matrix.h"

int main() {
	Matrix<2, 1> matrix1;

	matrix1.printConsole();
	std::cout << std::endl;

	Matrix<3, 3> matrix2;

	matrix2[0][0] = 1; matrix2[0][1] = 2; matrix2[0][2] = 3;
	matrix2[1][0] = 4; matrix2[1][1] = 5; matrix2[1][2] = 6;
	matrix2[2][0] = 7; matrix2[2][1] = 8; matrix2[2][2] = 9;

	matrix2.printConsole();
}