#ifndef Matrix_h
#define Matrix_h

#include <iostream>
#include <array>
#include <vector>
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

	Matrix<M, N, Field>& operator*=(const double& num);
	Matrix<M, N, Field>& operator/=(const double& num);

	std::array<Field, N>& operator[](size_t m);
	const std::array<Field, N>& operator[](size_t m) const;

	void printConsole();
private:
	std::array<std::array<Field, N>, M> matrix;
};

template <size_t M, size_t N, typename Field>
Matrix<M, N, Field> operator+(const Matrix<M, N, Field>& matrix_1, const Matrix<M, N, Field>& matrix_2);

template <size_t M, size_t N, typename Field>
Matrix<M, N, Field> operator-(const Matrix<M, N, Field>& matrix_1, const Matrix<M, N, Field>& matrix_2);

template <size_t M, size_t N, typename Field>
Matrix<M, N, Field> operator*(Matrix<M, N, Field> matrix, const double& num);

template <size_t M, size_t N, typename Field>
Matrix<M, N, Field> operator/(Matrix<M, N, Field> matrix, const double& num);

template <size_t M, size_t N, typename Field>
Matrix<M, N, Field> operator*(const double& num, Matrix<M, N, Field> matrix);

template <size_t M, size_t N, size_t P, typename Field>
Matrix<M, P, Field> operator*(const Matrix<M, N, Field>& matrix_1, const Matrix<N, P, Field>& matrix_2);

#include "../src/Matrix.cpp"

#endif