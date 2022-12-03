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

	BigInt b1 = "00002";
	BigInt b2 = "32482175483270569712305239885644443";

	b2 += b1;

	std::cout << b2 << std::endl;
}