#include <iostream>
#include "../inc/BigInt.h"

int main() {
	/*
	BigInt a1 = "123456789012345";
	std::cout << a1 << ", size = " << a1.len() << std::endl;

	BigInt ll = 9'223'372'036'854'775'804;
	std::cout << ll << ", size = " << ll.len() << std::endl;

	BigInt a2 = a1;
	std::cout << a2 << ", size = " << a2.len() << std::endl;

	a2 = ll;
	std::cout << a2 << ", size = " << a2.len() << std::endl;
	*/

	/*
	BigInt b1 = "11";
	BigInt b2 = 10;

	std::cout << "b1 = " << b1 << std::endl;
	std::cout << "b2 = " << b2 << std::endl;

	b2 += b1;

	std::cout << std::endl << "b1 = " << b1 << std::endl;
	std::cout << "b2 = " << b2 << std::endl;

	const BigInt b3 = 0;
	std::cout << std::endl << "b3 + 2 = " << b3 + 2 << std::endl;

	std::cout << "b1 < b2 = " << (b1 < b2) << std::endl; 
	std::cout << "b1 > b2 = " << (b1 > b2) << std::endl;
	std::cout << "b1 <= b2 = " << (b1 <= b2) << std::endl;
	std::cout << "b1 >= b2 = " << (b1 >= b2) << std::endl;
	std::cout << "b1 == b2 = " << (b1 == b2) << std::endl;
	std::cout << "b1 != b2 = " << (b1 != b2) << std::endl;
	*/

	BigInt c1 = "23";
	BigInt c2 = 1204;

	std::cout << "c1 = " << c1 << std::endl;
	std::cout << "c2 = " << c2 << std::endl << std::endl;

	std::cout << std::endl << "c1 + c2 = " << c1 + c2 << std::endl;
	std::cout << std::endl << "c2 + c1 = " << c2 + c1 << std::endl;
	std::cout << std::endl << "c1 - c2 = " << c1 - c2 << std::endl;
	std::cout << std::endl << "c2 - c1 = " << c2 - c1 << std::endl << std::endl;

	c1 = "-23";
	c2 = -1204;

	std::cout << "c1 = " << c1 << std::endl;
	std::cout << "c2 = " << c2 << std::endl << std::endl;

	std::cout << std::endl << "c1 + c2 = " << c1 + c2 << std::endl;
	std::cout << std::endl << "c2 + c1 = " << c2 + c1 << std::endl;
	std::cout << std::endl << "c1 - c2 = " << c1 - c2 << std::endl;
	std::cout << std::endl << "c2 - c1 = " << c2 - c1 << std::endl << std::endl;

	c1 = "1204";
	c2 = 23;

	std::cout << "c1 = " << c1 << std::endl;
	std::cout << "c2 = " << c2 << std::endl << std::endl;

	std::cout << std::endl << "c1 + c2 = " << c1 + c2 << std::endl;
	std::cout << std::endl << "c2 + c1 = " << c2 + c1 << std::endl;
	std::cout << std::endl << "c1 - c2 = " << c1 - c2 << std::endl;
	std::cout << std::endl << "c2 - c1 = " << c2 - c1 << std::endl << std::endl;

	c1 = "-1204";
	c2 = -23;

	std::cout << "c1 = " << c1 << std::endl;
	std::cout << "c2 = " << c2 << std::endl << std::endl;

	std::cout << std::endl << "c1 + c2 = " << c1 + c2 << std::endl;
	std::cout << std::endl << "c2 + c1 = " << c2 + c1 << std::endl;
	std::cout << std::endl << "c1 - c2 = " << c1 - c2 << std::endl;
	std::cout << std::endl << "c2 - c1 = " << c2 - c1 << std::endl << std::endl;

	c1 = "-1204";
	c2 = 23;

	std::cout << "c1 = " << c1 << std::endl;
	std::cout << "c2 = " << c2 << std::endl << std::endl;

	std::cout << std::endl << "c1 + c2 = " << c1 + c2 << std::endl;
	std::cout << std::endl << "c2 + c1 = " << c2 + c1 << std::endl;
	std::cout << std::endl << "c1 - c2 = " << c1 - c2 << std::endl;
	std::cout << std::endl << "c2 - c1 = " << c2 - c1 << std::endl << std::endl;

	c1 = "1204";
	c2 = -23;

	std::cout << "c1 = " << c1 << std::endl;
	std::cout << "c2 = " << c2 << std::endl << std::endl;

	std::cout << std::endl << "c1 + c2 = " << c1 + c2 << std::endl;
	std::cout << std::endl << "c2 + c1 = " << c2 + c1 << std::endl;
	std::cout << std::endl << "c1 - c2 = " << c1 - c2 << std::endl;
	std::cout << std::endl << "c2 - c1 = " << c2 - c1 << std::endl << std::endl;

	c1 = "-23";
	c2 = 1204;

	std::cout << "c1 = " << c1 << std::endl;
	std::cout << "c2 = " << c2 << std::endl << std::endl;

	std::cout << std::endl << "c1 + c2 = " << c1 + c2 << std::endl;
	std::cout << std::endl << "c2 + c1 = " << c2 + c1 << std::endl;
	std::cout << std::endl << "c1 - c2 = " << c1 - c2 << std::endl;
	std::cout << std::endl << "c2 - c1 = " << c2 - c1 << std::endl << std::endl;

	c1 = "23";
	c2 = -1204;

	std::cout << "c1 = " << c1 << std::endl;
	std::cout << "c2 = " << c2 << std::endl << std::endl;

	std::cout << std::endl << "c1 + c2 = " << c1 + c2 << std::endl;
	std::cout << std::endl << "c2 + c1 = " << c2 + c1 << std::endl;
	std::cout << std::endl << "c1 - c2 = " << c1 - c2 << std::endl;
	std::cout << std::endl << "c2 - c1 = " << c2 - c1 << std::endl << std::endl;
}