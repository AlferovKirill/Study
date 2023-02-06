#ifndef Matrix_h
#define Matrix_h

#include <iostream>
#include <array>
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
Matrix<M - 1, M - 1> cut(const Matrix<M, N, Field>& matrix, size_t column);

template <size_t M, size_t N, typename Field>
Field det(const Matrix<M, N, Field>& matrix) = delete;

template <size_t M, typename Field>
Field det(const Matrix<M, M, Field>& matrix);

template <typename Field>
Field det(const Matrix<2, 2, Field>& matrix);

template <typename Field>
Field det(const Matrix<1, 1, Field>& matrix);

#include "../src/Matrix.cpp"

#endif