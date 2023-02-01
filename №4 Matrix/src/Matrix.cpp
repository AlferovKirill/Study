#include "../inc/Matrix.h"

template <size_t M, size_t N, typename T>
Matrix<M, N, T>::Matrix() : matrix({ 0 }) {}

template <size_t M, size_t N, typename T>
std::array<T, N>& Matrix<M, N, T>::operator[](size_t m) {
	return matrix[m];
}

template <size_t M, size_t N, typename T>
const std::array<T, N>& Matrix<M, N, T>::operator[](size_t m) const {
	return matrix[m];
}

template <size_t M, size_t N, typename T>
void Matrix<M, N, T>::printConsole() {
	for (size_t m = 0; m < M; ++m) {
		for (size_t n = 0; n < N; ++n) {
			std::cout << matrix[m][n] << " ";
		}

		std::cout << std::endl;
	}
}