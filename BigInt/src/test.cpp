#include "../inc/BigInt.h"
#include <iostream>

int main() {
	BigInt a1 = "987654321987654321", a2 = 111;

	std::cout << "a1 = " << a1 << "\na2 = " << a2 << std::endl << std::endl;

	std::cout << "a1 + a2 = " << a1 + a2 << std::endl;
	std::cout << "a1 - a2 = " << a1 - a2 << std::endl;
	std::cout << "a1 * a2 = " << a1 * a2 << std::endl;
	std::cout << "a1 / a2 = " << a1 / a2 << std::endl;
	std::cout << "a1 % a2 = " << a1 % a2 << std::endl << std::endl;

	std::cout << "a1 = " << a1 << "\na2 = " << a2 << std::endl << std::endl;
	std::cout << "++a1 = " << ++a1 << std::endl;
	std::cout << "a1++ = " << a1++ << std::endl;
	std::cout << "a1-- = " << a1-- << std::endl;
	std::cout << "--a1 = " << --a1 << std::endl << std::endl;

	if (a1) {
		std::cout << "a1 = true" << std::endl;
	}
	else {
		std::cout << "a1 = false" << std::endl;
	}

	std::cout << "a1.len() = " << a1.len() << std::endl << std::endl;

	std::cout << "a1 < a2 = " << (a1 < a2) << std::endl;
	std::cout << "a1 > a2 = " << (a1 > a2) << std::endl;
	std::cout << "a1 <= a2 = " << (a1 <= a2) << std::endl;
	std::cout << "a1 >= a2 = " << (a1 >= a2) << std::endl;
	std::cout << "a1 == a2 = " << (a1 == a2) << std::endl;
	std::cout << "a1 != a2 = " << (a1 != a2) << std::endl << std::endl;

	a1 = 10, a2 = 10;

	std::cout << "a1 = " << a1 << "\na2 = " << a2 << std::endl << std::endl;

	std::cout << "a1 < a2 = " << (a1 < a2) << std::endl;
	std::cout << "a1 > a2 = " << (a1 > a2) << std::endl;
	std::cout << "a1 <= a2 = " << (a1 <= a2) << std::endl;
	std::cout << "a1 >= a2 = " << (a1 >= a2) << std::endl;
	std::cout << "a1 == a2 = " << (a1 == a2) << std::endl;
	std::cout << "a1 != a2 = " << (a1 != a2) << std::endl;

	return 0;
}