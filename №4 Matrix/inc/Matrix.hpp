#ifndef Matrix_h
#define Matrix_h

#include <iostream>
#include <array>
#include <exception>
#include <initializer_list>

template <size_t M, size_t N, typename Field = int>
class Matrix {
public:
	Matrix();
	Matrix(const Matrix<M, N, Field>& matrix);
	Matrix<M, N, Field>& operator=(const Matrix<M, N, Field>& matrix);
	~Matrix() = default;

	Matrix(std::initializer_list<Field> list);
	Matrix(std::initializer_list<std::array<Field, N>> list);

	Matrix<M, N, Field>& operator+=(const Matrix<M, N, Field>& matrix);
	Matrix<M, N, Field>& operator-=(const Matrix<M, N, Field>& matrix);

	template <typename Num>
	Matrix<M, N, Field>& operator*=(const Num& num);

	template <typename Num>
	Matrix<M, N, Field>& operator/=(const Num& num);

	template <size_t P, size_t K, typename SecondField>
	Matrix<M, N, Field>& operator*=(const Matrix<P, K, SecondField>& matrix) = delete;

	template <size_t P, size_t K, typename SecondField>
	Matrix<M, N, Field>& operator/=(const Matrix<P, K, SecondField>& matrix) = delete;

	std::array<Field, N>& operator[](size_t m);
	const std::array<Field, N>& operator[](size_t m) const;
private:
	std::array<std::array<Field, N>, M> matrix;
};

// operators
template <size_t M, size_t N, typename Field>
Matrix<M, N, Field> operator+(const Matrix<M, N, Field>& matrix_1, const Matrix<M, N, Field>& matrix_2);

template <size_t M, size_t N, typename Field>
Matrix<M, N, Field> operator-(const Matrix<M, N, Field>& matrix_1, const Matrix<M, N, Field>& matrix_2);

template <size_t M, size_t N, typename Field, typename Num>
Matrix<M, N, Field> operator*(Matrix<M, N, Field> matrix, const Num& num);

template <size_t M, size_t N, typename Field, typename Num>
Matrix<M, N, Field> operator*(const Num& num, Matrix<M, N, Field> matrix);

template <size_t M, size_t N, size_t P, typename Field>
Matrix<M, P, Field> operator*(const Matrix<M, N, Field>& matrix_1, const Matrix<N, P, Field>& matrix_2);

template <size_t M, size_t N, typename Field, typename Num>
Matrix<M, N, Field> operator/(Matrix<M, N, Field> matrix, const Num& num);

// functions
template <size_t M, size_t N, typename Field>
void printConsole(const Matrix<M, N, Field>& matrix);

template <size_t M, size_t N, typename Field>
Matrix<N, M, Field> transpose(const Matrix<M, N, Field>& matrix);

template <size_t M, size_t N, typename Field>
Matrix<M - 1, M - 1, Field> cut(const Matrix<M, N, Field>& matrix, size_t r, size_t c);

template <size_t M, size_t N, typename Field>
Field det(const Matrix<M, N, Field>& matrix) = delete;

template <size_t M, typename Field>
Field det(const Matrix<M, M, Field>& matrix);

template <typename Field>
Field det(const Matrix<2, 2, Field>& matrix);

template <typename Field>
Field det(const Matrix<1, 1, Field>& matrix);

template <size_t M, size_t N, typename Field>
Matrix<M, N, Field> inverse(const Matrix<M, N, Field>& matrix) = delete;

template <size_t M, typename Field>
Matrix<M, M, Field> inverse(const Matrix<M, M, Field>& matrix);

template <typename Field>
Matrix<1, 1, Field> inverse(const Matrix<1, 1, Field>& matrix);

//------------------------------------------------------------------------------------
//------------------------------     Definition     ----------------------------------
//------------------------------------------------------------------------------------

template <size_t M, size_t N, typename Field>
Matrix<M, N, Field>::Matrix() : matrix({ 0 }) {}

template <size_t M, size_t N, typename Field>
Matrix<M, N, Field>::Matrix(const Matrix<M, N, Field>& matrix) : matrix(matrix.matrix) {}

template <size_t M, size_t N, typename Field>
Matrix<M, N, Field>& Matrix<M, N, Field>::operator=(const Matrix<M, N, Field>& matrix) {
	this->matrix = matrix.matrix;

	return *this;
}

template <size_t M, size_t N, typename Field>
Matrix<M, N, Field>::Matrix(std::initializer_list<Field> list) {
	for (size_t m = 0, k = 0; m < M; ++m) {
		for (size_t n = 0; n < N; ++n, ++k) {
			matrix[m][n] = *(list.begin() + k);
		}
	}
}

template <size_t M, size_t N, typename Field>
Matrix<M, N, Field>::Matrix(std::initializer_list<std::array<Field, N>> list) {
	for (size_t m = 0; m < M; ++m) {
		for (size_t n = 0; n < N; ++n) {
			matrix[m][n] = (*(list.begin() + m))[n];
		}
	}
}

template <size_t M, size_t N, typename Field>
Matrix<M, N, Field>& Matrix<M, N, Field>::operator+=(const Matrix<M, N, Field>& matrix) {
	for (size_t m = 0; m < M; ++m) {
		for (size_t n = 0; n < N; ++n) {
			this->matrix[m][n] += matrix.matrix[m][n];
		}
	}

	return *this;
}

template <size_t M, size_t N, typename Field>
Matrix<M, N, Field>& Matrix<M, N, Field>::operator-=(const Matrix<M, N, Field>& matrix) {
	for (size_t m = 0; m < M; ++m) {
		for (size_t n = 0; n < N; ++n) {
			this->matrix[m][n] -= matrix.matrix[m][n];
		}
	}

	return *this;
}

template <size_t M, size_t N, typename Field>
template <typename Num>
Matrix<M, N, Field>& Matrix<M, N, Field>::operator*=(const Num& num) {
	for (size_t m = 0; m < M; ++m) {
		for (size_t n = 0; n < N; ++n) {
			matrix[m][n] *= num;
		}
	}

	return *this;
}

template <size_t M, size_t N, typename Field>
template <typename Num>
Matrix<M, N, Field>& Matrix<M, N, Field>::operator/=(const Num& num) {
	for (size_t m = 0; m < M; ++m) {
		for (size_t n = 0; n < N; ++n) {
			matrix[m][n] /= num;
		}
	}

	return *this;
}

template <size_t M, size_t N, typename Field>
std::array<Field, N>& Matrix<M, N, Field>::operator[](size_t m) {
	return matrix[m];
}

template <size_t M, size_t N, typename Field>
const std::array<Field, N>& Matrix<M, N, Field>::operator[](size_t m) const {
	return matrix[m];
}

template <size_t M, size_t N, typename Field>
Matrix<M, N, Field> operator+(const Matrix<M, N, Field>& matrix_1, const Matrix<M, N, Field>& matrix_2) {
	Matrix<M, N, Field> result = matrix_1;
	result += matrix_2;

	return result;
}

template <size_t M, size_t N, typename Field>
Matrix<M, N, Field> operator-(const Matrix<M, N, Field>& matrix_1, const Matrix<M, N, Field>& matrix_2) {
	Matrix<M, N, Field> result = matrix_1;
	result -= matrix_2;

	return result;
}

template <size_t M, size_t N, typename Field, typename Num>
Matrix<M, N, Field> operator*(Matrix<M, N, Field> matrix, const Num& num) {
	matrix *= num;

	return matrix;
}

template <size_t M, size_t N, typename Field, typename Num>
Matrix<M, N, Field> operator*(const Num& num, Matrix<M, N, Field> matrix) {
	return matrix * num;
}

template <size_t M, size_t N, size_t P, typename Field>
Matrix<M, P, Field> operator*(const Matrix<M, N, Field>& matrix_1, const Matrix<N, P, Field>& matrix_2) {
	Matrix<M, P, Field> result;

	for (size_t m = 0; m < M; ++m) {
		for (size_t p = 0; p < P; ++p) {
			for (size_t n = 0; n < N; ++n) {
				result[m][p] += matrix_1[m][n] * matrix_2[n][p];
			}
		}
	}

	return result;
}

template <size_t M, size_t N, typename Field, typename Num>
Matrix<M, N, Field> operator/(Matrix<M, N, Field> matrix, const Num& num) {
	matrix /= num;

	return matrix;
}

template <size_t M, size_t N, typename Field>
void printConsole(const Matrix<M, N, Field>& matrix) {
	for (size_t m = 0; m < M; ++m) {
		for (size_t n = 0; n < N; ++n) {
			std::cout << matrix[m][n] << " ";
		}

		std::cout << std::endl;
	}
}

template <size_t M, size_t N, typename Field>
Matrix<N, M, Field> transpose(const Matrix<M, N, Field>& matrix) {
	Matrix<N, M, Field> result;

	for (size_t m = 0; m < M; ++m) {
		for (size_t n = 0; n < N; ++n) {
			result[n][m] = matrix[m][n];
		}
	}

	return result;
}

template <size_t M, size_t N, typename Field>
Matrix<M - 1, M - 1, Field> cut(const Matrix<M, N, Field>& matrix, size_t r, size_t c) {
	Matrix<M - 1, M - 1, Field> result;

	for (size_t row = 0; row < M; ++row) {
		if (row == r) {
			continue;
		}
		else if (row < r) {
			for (size_t column = 0; column < M; ++column) {
				if (column < c) {
					result[row][column] = matrix[row][column];
				}
				else if (column == c) {
					continue;
				}
				else if (column > c) {
					result[row][column - 1] = matrix[row][column];
				}
			}
		}
		else if (row > r) {
			for (size_t column = 0; column < M; ++column) {
				if (column < c) {
					result[row - 1][column] = matrix[row][column];
				}
				if (column == c) {
					continue;
				}
				else if (column > c) {
					result[row - 1][column - 1] = matrix[row][column];
				}
			}
		}
	}

	return result;
}

template <size_t M, typename Field>
Field det(const Matrix<M, M, Field>& matrix) {
	Field result = 0;

	for (size_t column = 0; column < M; ++column) {
		result += std::pow((-1), column + 2) * (matrix[0][column]) * det(cut(matrix, 0, column));
	}

	return result;
}

template <typename Field>
Field det(const Matrix<2, 2, Field>& matrix) {
	return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
}

template <typename Field>
Field det(const Matrix<1, 1, Field>& matrix) {
	return matrix[0][0];
}

template <size_t M, typename Field>
Matrix<M, M, Field> inverse(const Matrix<M, M, Field>& matrix) {
	Field determinant = det(matrix);

	if (determinant == 0) {
		throw std::exception("Matrix determenant is equal 0.");
	}

	Matrix<M, M, Field> algComplementsMatrix;

	for (size_t row = 0; row < M; ++row) {
		for (size_t column = 0; column < M; ++column) {
			algComplementsMatrix[row][column] = std::pow((-1), column + row + 2) * det(cut(matrix, row, column));
		}
	}

	algComplementsMatrix = transpose(algComplementsMatrix);
	algComplementsMatrix /= determinant;

	return algComplementsMatrix;
}

template <typename Field>
Matrix<1, 1, Field> inverse(const Matrix<1, 1, Field>& matrix) {
	Matrix<1, 1, Field> result = { 1 / matrix[0][0] };

	return result;
}

#endif