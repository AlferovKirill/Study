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

	BigInt b1 = "000044";
	BigInt b2 = -1244251;

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;

	b2 += b1;

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
}