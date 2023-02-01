#ifndef Matrix_h
#define Matrix_h

#include <iostream>
#include <array>
#include <initializer_list>

template <size_t M, size_t N, typename T = int>
class Matrix {
public:
	Matrix();

	// Надо реализовать конструкторы от фигурных в соответствии с лекциями по итераторам
	Matrix(std::initializer_list<T> list) {}
	Matrix(std::initializer_list<std::initializer_list<T>> list) {}

	std::array<T, N>& operator[](size_t m);
	const std::array<T, N>& operator[](size_t m) const;

	void printConsole();
private:
	std::array<std::array<T, N>, M> matrix;
};

#include "../src/Matrix.cpp"

#endif