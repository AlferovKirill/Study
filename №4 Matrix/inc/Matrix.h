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

	Matrix<N, M, Field> transpose() const;
	void printConsole() const;
private:
	std::array<std::array<Field, N>, M> matrix;
};

template <size_t M, size_t N, typename Field>
Matrix<N, M, Field> transpose(const Matrix<M, N, Field>& matrix);

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

#include "../src/Matrix.cpp"

#endif