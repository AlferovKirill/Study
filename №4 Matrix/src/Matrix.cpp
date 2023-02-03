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
Matrix<M, N, Field>& Matrix<M, N, Field>::operator+(const Matrix<M, N, Field>& matrix) {
	*this += matrix;

	return *this;
}

template <size_t M, size_t N, typename Field>
Matrix<M, N, Field>& Matrix<M, N, Field>::operator-(const Matrix<M, N, Field>& matrix) {
	*this -= matrix;

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
void Matrix<M, N, Field>::printConsole() {
	for (size_t m = 0; m < M; ++m) {
		for (size_t n = 0; n < N; ++n) {
			std::cout << matrix[m][n] << " ";
		}

		std::cout << std::endl;
	}
}