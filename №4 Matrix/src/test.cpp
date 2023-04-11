#include "../inc/Matrix.hpp"

int main() {
	Matrix<4, 4> matrix1 = { {1, 1, 1, 1}, 
							 {2, 2, 2, 2},
							 {3, 3, 3, 3},
							 {4, 4, 4, 4} };

	Matrix<4, 2> matrix2 = { {1, 1}, 
							 {1, 1}, 
							 {1, 1},
							 {1, 1} };

	std::cout << "Matrix #1" << std::endl;
	printConsole(matrix1);
	std::cout << std::endl;

	std::cout << "Matrix #2" << std::endl;
	printConsole(matrix2);
	std::cout << std::endl;

	std::cout << "Matrix #1 * Matrix #2 = " << std::endl;

	printConsole(matrix1 * matrix2);
	std::cout << std::endl;

	std::cout << "Transpose Matrix #1" << std::endl;
	printConsole(transpose(matrix1));
	std::cout << std::endl;

	std::cout << "Transpose Matrix #2" << std::endl;
	printConsole(transpose(matrix2));
	std::cout << std::endl;

	std::cout << "------------------" << std::endl;

	Matrix<2, 2> matrix3 = { {2, 1},
							 {3, 4} };

	Matrix<2, 3> matrix4 = { {1, 0, 3},
							 {4, 2, 1} };

	std::cout << "Matrix #3" << std::endl;
	printConsole(matrix3);
	std::cout << std::endl;

	std::cout << "Matrix #4" << std::endl;
	printConsole(matrix4);
	std::cout << std::endl;

	std::cout << "Matrix #3 * Matrix #4 = " << std::endl;

	printConsole(matrix3 * matrix4);
	std::cout << std::endl;

	std::cout << "Transpose Matrix #3" << std::endl;
	printConsole(transpose(matrix3));
	std::cout << std::endl;

	std::cout << "Transpose Matrix #4" << std::endl;
	printConsole(transpose(matrix4));
	std::cout << std::endl;

	std::cout << "------------------" << std::endl;

	Matrix<2, 2> matrix5 = { {1, 1},
							 {1, 1} };

	std::cout << "Matrix #5" << std::endl;
	printConsole(matrix5);
	std::cout << std::endl;

	std::cout << "Matrix #5 * 8 = " << std::endl;

	printConsole(matrix5 * 8);
	std::cout << std::endl;

	std::cout << "------------------" << std::endl;
	Matrix<3, 3> matrix6 = { {3, 3, 3},
							 {9, 9, 9},
							 {6, 6, 6} };

	std::cout << "Matrix #6" << std::endl;
	printConsole(matrix6);
	std::cout << std::endl;

	std::cout << "Matrix #6 / 3 = " << std::endl;

	printConsole(matrix6 / 3);
	std::cout << std::endl;
	
	std::cout << "------------------" << std::endl;

	Matrix<2, 2> matrix7 = { {4, 4},
							 {4, 4},
							 {4, 4},
							 {4, 4} };

	Matrix<2, 2> matrix8 = { {1, 1},
							 {1, 1},
							 {1, 1},
							 {1, 1} };

	std::cout << "Matrix #7" << std::endl;
	printConsole(matrix7);
	std::cout << std::endl;

	std::cout << "Matrix #8" << std::endl;
	printConsole(matrix8);
	std::cout << std::endl;

	std::cout << "Matrix #7 + Matrix #8 = " << std::endl;

	printConsole(matrix7 + matrix8);
	std::cout << std::endl;

	std::cout << "------------------" << std::endl;

	Matrix<2, 2> matrix9 = { {7, 7},
							 {7, 7},
							 {7, 7},
							 {7, 7} };

	Matrix<2, 2> matrix10 = { {1, 1},
							  {1, 1},
							  {1, 1},
							  {1, 1} };

	std::cout << "Matrix #9" << std::endl;
	printConsole(matrix9);
	std::cout << std::endl;

	std::cout << "Matrix #10" << std::endl;
	printConsole(matrix10);
	std::cout << std::endl;

	std::cout << "Matrix #9 - Matrix #10 = " << std::endl;

	printConsole(matrix9 - matrix10);
	std::cout << std::endl;
	
	std::cout << "------------------" << std::endl;

	Matrix<4, 4, double> matrix11 = { {5, 1, 5, 1},
									  {1, 1, 5, 5},
									  {1, 5, 1, 5},
									  {1, 5, 5, 1} };

	std::cout << "Matrix #11" << std::endl;
	printConsole(matrix11);
	std::cout << std::endl;

	std::cout << "Matrix #11 det = " << det(matrix11) << std::endl << std::endl;

	std::cout << "Inverse Matrix #11 = " << std::endl;
	printConsole(inverse(matrix11));
	std::cout << std::endl;
	
	std::cout << "------------------" << std::endl;

	Matrix<3, 3, double> matrix12 = { {3, 1, 2},
									  {4, 6, 4},
									  {8, 7, 9} };

	std::cout << "Matrix #12" << std::endl;
	printConsole(matrix12);
	std::cout << std::endl;

	std::cout << "Matrix #12 det = " << det(matrix12) << std::endl << std::endl;

	std::cout << "Inverse Matrix #12 = " << std::endl;
	printConsole(inverse(matrix12));
	std::cout << std::endl;

	std::cout << "------------------" << std::endl;

	Matrix<2, 2, double> matrix13 = { {1, 2},
									  {3, 2} };

	std::cout << "Matrix #13" << std::endl;
	printConsole(matrix13);
	std::cout << std::endl;

	std::cout << "Matrix #13 det = " << det(matrix13) << std::endl << std::endl;

	std::cout << "Inverse Matrix #13 = " << std::endl;
	printConsole(inverse(matrix13));
	std::cout << std::endl;

	std::cout << "------------------" << std::endl;

	Matrix<1, 1, double> matrix14 = { 2 };

	std::cout << "Matrix #14" << std::endl;
	printConsole(matrix14);
	std::cout << std::endl;

	std::cout << "Matrix #14 det = " << det(matrix14) << std::endl << std::endl;

	std::cout << "Inverse Matrix #14 = " << std::endl;
	printConsole(inverse(matrix14));
	std::cout << std::endl;

	return 0;
}