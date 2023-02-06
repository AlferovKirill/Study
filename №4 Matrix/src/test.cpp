#include "../inc/Matrix.h"

int main() {
	Matrix<4, 4> matrix1 = { {1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {4, 4, 4, 4} };
	Matrix<4, 2> matrix2 = { {1, 1}, {1, 1}, {1, 1}, {1, 1} };

	std::cout << "Matrix #1" << std::endl;
	printConsole(matrix1);
	std::cout << std::endl;

	std::cout << "Matrix #2" << std::endl;
	printConsole(matrix2);
	std::cout << std::endl;

	std::cout << "Matrix #1 * Matrix #2 = " << std::endl;

	printConsole(matrix1 * matrix2);

	std::cout << "------------------" << std::endl;

	Matrix<2, 2> matrix3 = { {2, 1}, {3, 4} };
	Matrix<2, 3> matrix4 = { {1, 0, 3}, {4, 2, 1} };

	std::cout << "Matrix #3" << std::endl;
	printConsole(matrix3);
	std::cout << std::endl;

	std::cout << "Matrix #4" << std::endl;
	printConsole(matrix4);
	std::cout << std::endl;

	std::cout << "Matrix #3 * Matrix #4 = " << std::endl;

	printConsole(matrix3 * matrix4);

	std::cout << "------------------" << std::endl;

	Matrix<2, 2> matrix5 = { {1, 1}, {1, 1} };

	std::cout << "Matrix #5" << std::endl;
	printConsole(matrix5);
	std::cout << std::endl;

	std::cout << "Matrix #5 * 8 = " << std::endl;

	printConsole(matrix5 * 8);

	std::cout << "------------------" << std::endl;
	Matrix<3, 3> matrix6 = { {3, 3, 3}, {9, 9, 9}, {6, 6, 6} };

	std::cout << "Matrix #6" << std::endl;
	printConsole(matrix6);
	std::cout << std::endl;

	std::cout << "Matrix #6 / 3 = " << std::endl;

	printConsole(matrix6 / 3);

	std::cout << "------------------" << std::endl;

	Matrix<2, 2> matrix7 = { {4, 4}, {4, 4}, {4, 4}, {4, 4} };
	Matrix<2, 2> matrix8 = { {1, 1}, {1, 1}, {1, 1}, {1, 1} };

	std::cout << "Matrix #7" << std::endl;
	printConsole(matrix7);
	std::cout << std::endl;

	std::cout << "Matrix #8" << std::endl;
	printConsole(matrix8);
	std::cout << std::endl;

	std::cout << "Matrix #7 + Matrix #8 = " << std::endl;

	printConsole(matrix7 + matrix8);

	std::cout << "------------------" << std::endl;

	Matrix<2, 2> matrix9 = { {7, 7}, {7, 7}, {7, 7}, {7, 7} };
	Matrix<2, 2> matrix10 = { {3, 3}, {3, 3}, {3, 3}, {2, 2} };

	std::cout << "Matrix #9" << std::endl;
	printConsole(matrix9);
	std::cout << std::endl;

	std::cout << "Matrix #10" << std::endl;
	printConsole(matrix10);
	std::cout << std::endl;

	std::cout << "Matrix #9 - Matrix #10 = " << std::endl;

	printConsole(matrix9 - matrix10);

	std::cout << "------------------" << std::endl;

	Matrix<3, 2> matrix11 = { {2, 1}, {5, 3}, {4, 7} };

	printConsole(matrix11);
	std::cout << std::endl;

	printConsole(transpose(matrix11));
	std::cout << std::endl;

	std::cout << "------------------" << std::endl;

	Matrix<3, 3> matrix12 = { {1, 3, 2}, {0, -2, 1}, {4, 1, 2} };

	printConsole(matrix12);
	std::cout << std::endl;

	std::cout << "det = " << det(matrix12) << std::endl;

	std::cout << "------------------" << std::endl;

	Matrix<3, 3> matrix13 = { {4, 5, 6}, {3, -2, 10}, {3, 2, 1} };

	printConsole(matrix13);
	std::cout << std::endl;

	std::cout << "det = " << det(matrix13) << std::endl;

	std::cout << "------------------" << std::endl;

	Matrix<2, 2> matrix14 = { {1, 2}, {3, 2} };

	printConsole(matrix14);
	std::cout << std::endl;

	std::cout << "det = " << det(matrix14) << std::endl;

	std::cout << "------------------" << std::endl;

	Matrix<1, 1> matrix15 = { 2 };

	printConsole(matrix15);
	std::cout << std::endl;

	std::cout << "det = " << det(matrix15) << std::endl;

	std::cout << "------------------" << std::endl;

	Matrix<4, 4> matrix16 = { {1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {4, 4, 4, 4} };

	printConsole(matrix16);
	std::cout << std::endl;

	std::cout << "det = " << det(matrix16) << std::endl;

	return 0;
}