#include "../inc/Matrix.h"

int main() {
	Matrix<4, 4> matrix1 = { {1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {4, 4, 4, 4} };
	Matrix<4, 2> matrix2 = { {1, 1}, {1, 1}, {1, 1}, {1, 1} };

	std::cout << "Matrix #1" << std::endl;
	matrix1.printConsole();
	std::cout << std::endl;

	std::cout << "Matrix #2" << std::endl;
	matrix2.printConsole();
	std::cout << std::endl;

	std::cout << "Matrix #1 * Matrix #2 = " << std::endl;

	(matrix1 * matrix2).printConsole();

	std::cout << "------------------" << std::endl;

	Matrix<2, 2> matrix3 = { {2, 1}, {3, 4} };
	Matrix<2, 3> matrix4 = { {1, 0, 3}, {4, 2, 1} };

	std::cout << "Matrix #3" << std::endl;
	matrix3.printConsole();
	std::cout << std::endl;

	std::cout << "Matrix #4" << std::endl;
	matrix4.printConsole();
	std::cout << std::endl;

	std::cout << "Matrix #3 * Matrix #4 = " << std::endl;

	(matrix3 * matrix4).printConsole();

	std::cout << "------------------" << std::endl;

	Matrix<2, 2> matrix5 = { {1, 1}, {1, 1} };

	std::cout << "Matrix #5" << std::endl;
	matrix5.printConsole();
	std::cout << std::endl;

	std::cout << "Matrix #5 * 8 = " << std::endl;

	(matrix5 * 8).printConsole();

	std::cout << "------------------" << std::endl;
	Matrix<3, 3> matrix6 = { {3, 3, 3}, {9, 9, 9}, {6, 6, 6} };

	std::cout << "Matrix #6" << std::endl;
	matrix6.printConsole();
	std::cout << std::endl;

	std::cout << "Matrix #6 / 3 = " << std::endl;

	(matrix6 / 3).printConsole();

	std::cout << "------------------" << std::endl;

	Matrix<2, 2> matrix7 = { {4, 4}, {4, 4}, {4, 4}, {4, 4} };
	Matrix<2, 2> matrix8 = { {1, 1}, {1, 1}, {1, 1}, {1, 1} };

	std::cout << "Matrix #7" << std::endl;
	matrix7.printConsole();
	std::cout << std::endl;

	std::cout << "Matrix #8" << std::endl;
	matrix8.printConsole();
	std::cout << std::endl;

	std::cout << "Matrix #7 + Matrix #8 = " << std::endl;

	(matrix7 + matrix8).printConsole();

	std::cout << "------------------" << std::endl;

	Matrix<2, 2> matrix9 = { {7, 7}, {7, 7}, {7, 7}, {7, 7} };
	Matrix<2, 2> matrix10 = { {3, 3}, {3, 3}, {3, 3}, {2, 2} };

	std::cout << "Matrix #9" << std::endl;
	matrix9.printConsole();
	std::cout << std::endl;

	std::cout << "Matrix #10" << std::endl;
	matrix10.printConsole();
	std::cout << std::endl;

	std::cout << "Matrix #9 - Matrix #10 = " << std::endl;

	(matrix9 - matrix10).printConsole();
}