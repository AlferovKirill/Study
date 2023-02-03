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

	Matrix(std::initializer_list<Field> list);
	Matrix(std::initializer_list<std::array<Field, N>> list);

	Matrix<M, N, Field>& operator+=(const Matrix<M, N, Field>& matrix);
	Matrix<M, N, Field>& operator-=(const Matrix<M, N, Field>& matrix);

	Matrix<M, N, Field>& operator+(const Matrix<M, N, Field>& matrix);
	Matrix<M, N, Field>& operator-(const Matrix<M, N, Field>& matrix);

	std::array<Field, N>& operator[](size_t m);
	const std::array<Field, N>& operator[](size_t m) const;

	void printConsole();
private:
	std::array<std::array<Field, N>, M> matrix;
};

#include "../src/Matrix.cpp"

#endif