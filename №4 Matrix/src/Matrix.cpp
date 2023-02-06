#include "../inc/Matrix.h"

template <size_t M, size_t N, typename Field>
Matrix<M, N, Field>::Matrix() : matrix({0}) {}

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
Matrix<M - 1, M - 1> cut(const Matrix<M, N, Field>& matrix, size_t column) {
	Matrix<M - 1, M - 1> result;

	for (size_t m = 1; m < M; ++m) {
		for (size_t n = 0; n < M; ++n) {
			if (n < column) {
				result[m - 1][n] = matrix[m][n];
			}
			if (n == column) {
				continue;
			}
			else if (n > column) {
				result[m - 1][n - 1] = matrix[m][n];
			}
		}
	}

	return result;
}

template <size_t M, typename Field>
Field det(const Matrix<M, M, Field>& matrix) {
	Field result = 0;

	for (size_t m = 0; m < M; ++m) {
		result += std::pow((-1), m + 2) * (matrix[0][m]) * det(cut(matrix, m));
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