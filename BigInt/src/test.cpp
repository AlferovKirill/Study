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

	/*
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

	std::cout << "++c1 = " << ++c1 << std::endl;
	std::cout << "c1++ = " << c1++ << std::endl;
	std::cout << "c1 = " << c1 << std::endl;

	std::cout << std::endl << "--c2 = " << --c2 << std::endl;
	std::cout << "c2-- = " << c2-- << std::endl;
	std::cout << "c2 = " << c2 << std::endl;

	BigInt m1 = 2132;
	BigInt m2 = 123;

	std::cout << "m1 = " << m1 << std::endl;
	std::cout << "m2 = " << m2 << std::endl << std::endl;

	m1 *= m2;

	std::cout << "m1 = " << m1 << std::endl;
	std::cout << "m2 = " << m2 << std::endl << std::endl;
	*/

	BigInt m1 = 999;
	BigInt m2 = 999;

	std::cout << "m1 = " << m1 << std::endl;
	std::cout << "m2 = " << m2 << std::endl;

	std::cout << "m1 * m2 = " << m1 * m2 << std::endl << std::endl;

	m1 = -1;
	m2 = 1;

	std::cout << "m1 = " << m1 << std::endl;
	std::cout << "m2 = " << m2 << std::endl;

	std::cout << "m1 * m2 = " << m1 * m2 << std::endl << std::endl;

	m1 = -1;
	m2 = 0;

	std::cout << "m1 = " << m1 << std::endl;
	std::cout << "m2 = " << m2 << std::endl;

	std::cout << "m1 * m2 = " << m1 * m2 << std::endl << std::endl;

	m1 = -1000;
	m2 = -11;

	std::cout << "m1 = " << m1 << std::endl;
	std::cout << "m2 = " << m2 << std::endl;

	std::cout << "m1 * m2 = " << m1 * m2 << std::endl << std::endl;

	m1 = 113;
	m2 = -1;

	std::cout << "m1 = " << m1 << std::endl;
	std::cout << "m2 = " << m2 << std::endl;

	std::cout << "m1 * m2 = " << m1 * m2 << std::endl << std::endl;

	m1 = 0;
	m2 = 0;

	std::cout << "m1 = " << m1 << std::endl;
	std::cout << "m2 = " << m2 << std::endl;

	std::cout << "m1 * m2 = " << m1 * m2 << std::endl << std::endl;

	m1 = 1;
	m2 = 1000000;

	std::cout << "m1 = " << m1 << std::endl;
	std::cout << "m2 = " << m2 << std::endl;

	std::cout << "m1 * m2 = " << m1 * m2 << std::endl << std::endl;

	m1 = 0;
	m2 = 1331;

	std::cout << "m1 = " << m1 << std::endl;
	std::cout << "m2 = " << m2 << std::endl;

	std::cout << "m1 * m2 = " << m1 * m2 << std::endl << std::endl;

	m1 = 111111;
	m2 = 2;

	std::cout << "m1 = " << m1 << std::endl;
	std::cout << "m2 = " << m2 << std::endl;

	std::cout << "m1 * m2 = " << m1 * m2 << std::endl << std::endl;

	m1 = 12345;
	m2 = 999;

	std::cout << "m1 = " << m1 << std::endl;
	std::cout << "m2 = " << m2 << std::endl;

	std::cout << "m1 * m2 = " << m1 * m2 << std::endl << std::endl;

	m1 = "123456789123456789";
	m2 = "123456789123456789";

	std::cout << "m1 = " << m1 << std::endl;
	std::cout << "m2 = " << m2 << std::endl;

	std::cout << "m1 * m2 = " << m1 * m2 << std::endl << std::endl;
}