#include <iostream>
#include "../inc/BigInt.h"

int main() {
	BigInt t1 = 1495;
	BigInt t2 = 12;

	std::cout << "t1 = " << t1 << std::endl;
	std::cout << "t2 = " << t2 << std::endl;
	std::cout << "t1 / t2 = " << t1 / t2 << std::endl << std::endl;

	t1 = 1495;
	t2 = 1495;

	std::cout << "t1 = " << t1 << std::endl;
	std::cout << "t2 = " << t2 << std::endl;
	std::cout << "t1 / t2 = " << t1 / t2 << std::endl << std::endl;

	t1 = 12;
	t2 = 1495;

	std::cout << "t1 = " << t1 << std::endl;
	std::cout << "t2 = " << t2 << std::endl;
	std::cout << "t1 / t2 = " << t1 / t2 << std::endl << std::endl;

	t1 = 8;
	t2 = 2;

	std::cout << "t1 = " << t1 << std::endl;
	std::cout << "t2 = " << t2 << std::endl;
	std::cout << "t1 / t2 = " << t1 / t2 << std::endl << std::endl;

	t1 = 8;
	t2 = 8;

	std::cout << "t1 = " << t1 << std::endl;
	std::cout << "t2 = " << t2 << std::endl;
	std::cout << "t1 / t2 = " << t1 / t2 << std::endl << std::endl;

	t1 = 2;
	t2 = 8;

	std::cout << "t1 = " << t1 << std::endl;
	std::cout << "t2 = " << t2 << std::endl;
	std::cout << "t1 / t2 = " << t1 / t2 << std::endl << std::endl;

	t1 = 10000;
	t2 = 235;

	std::cout << "t1 = " << t1 << std::endl;
	std::cout << "t2 = " << t2 << std::endl;
	std::cout << "t1 / t2 = " << t1 / t2 << std::endl << std::endl;

	t1 = 235;
	t2 = 10000;

	std::cout << "t1 = " << t1 << std::endl;
	std::cout << "t2 = " << t2 << std::endl;
	std::cout << "t1 / t2 = " << t1 / t2 << std::endl << std::endl;

	t1 = 10000;
	t2 = 10000;

	std::cout << "t1 = " << t1 << std::endl;
	std::cout << "t2 = " << t2 << std::endl;
	std::cout << "t1 / t2 = " << t1 / t2 << std::endl << std::endl;

	t1 = "123456789123456789123456789";
	t2 = 125;

	std::cout << "t1 = " << t1 << std::endl;
	std::cout << "t2 = " << t2 << std::endl;
	std::cout << "t1 + t2 = " << t1 + t2 << std::endl << std::endl;

	t1 = "123456789123456789123456789";
	t2 = 125;

	std::cout << "t1 = " << t1 << std::endl;
	std::cout << "t2 = " << t2 << std::endl;
	std::cout << "t1 - t2 = " << t1 - t2 << std::endl << std::endl;

	t1 = "123456789123456789123456789";
	t2 = 125;

	std::cout << "t1 = " << t1 << std::endl;
	std::cout << "t2 = " << t2 << std::endl;
	std::cout << "t1 * t2 = " << t1 * t2 << std::endl << std::endl;

	t1 = "123456789123456789123456789";
	t2 = 125;

	std::cout << "t1 = " << t1 << std::endl;
	std::cout << "t2 = " << t2 << std::endl;
	std::cout << "t1 / t2 = " << t1 / t2 << std::endl << std::endl;

	std::cout << "t1 = " << ++t1 << std::endl << std::endl;

	t1 = "-123456789123456789123456789";
	t2 = 125;

	std::cout << "t1 = " << t1 << std::endl;
	std::cout << "t2 = " << t2 << std::endl;
	std::cout << "t1 + t2 = " << t1 + t2 << std::endl << std::endl;

	t1 = "-123456789123456789123456789";
	t2 = 125;

	std::cout << "t1 = " << t1 << std::endl;
	std::cout << "t2 = " << t2 << std::endl;
	std::cout << "t1 - t2 = " << t1 - t2 << std::endl << std::endl;

	t1 = "-123456789123456789123456789";
	t2 = 125;

	std::cout << "t1 = " << t1 << std::endl;
	std::cout << "t2 = " << t2 << std::endl;
	std::cout << "t1 * t2 = " << t1 * t2 << std::endl << std::endl;

	t1 = "-123456789123456789123456789";
	t2 = 125;

	std::cout << "t1 = " << t1 << std::endl;
	std::cout << "t2 = " << t2 << std::endl;
	std::cout << "t1 / t2 = " << t1 / t2 << std::endl << std::endl;

	std::cout << "t1 = " << ++t1 << std::endl << std::endl;
}