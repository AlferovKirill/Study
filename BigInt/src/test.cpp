#include <iostream>
#include "../inc/BigInt.h"

int main() {
	BigInt bi_num_1, bi_num_2;
	int i_num_1, i_num_2;

	int k1 = 0, k2 = 0, k3 = 0, k4 = 0, k5 = 0;
	
	/*
	bi_num_1 = 1000; bi_num_2 = 98;
	i_num_1 = 1000; i_num_2 = 98;

	std::cout << "bi_num_1 = " << bi_num_1 << ", bi_num_2 = " << bi_num_2 << std::endl;
	std::cout << "i_num_1 = " << i_num_1 << ", i_num_2 = " << i_num_2 << std::endl << std::endl;

	std::cout << "bi_num_1 / bi_num_2 = " << (bi_num_1 / bi_num_2) << std::endl;
	std::cout << "i_num_1 / i_num_2 = " << i_num_1 / i_num_2 << std::endl << std::endl;

	std::cout << "bi_num_1 % bi_num_2 = " << (bi_num_1 % bi_num_2) << std::endl;
	std::cout << "i_num_1 % i_num_2 = " << i_num_1 % i_num_2 << std::endl << std::endl;

	//std::cout << "i_num_1 / i_num_2 == bi_num_1 % bi_num_2 = " << (BigInt(i_num_1 / i_num_2) == (bi_num_1 / bi_num_2)) << std::endl << std::endl;
	*/

	for (int i = -100; i < 100; ++i) {
		for (int j = 100; j > -100; --j) {
			if (j == 0) {
				continue;
			}

			bi_num_1 = i; bi_num_2 = j;
			i_num_1 = i; i_num_2 = j;
			
			if ((bi_num_1 + bi_num_2) == BigInt(i_num_1 + i_num_2)) {}
			else {
				std::cout << "-1 " << std::endl;
				std::cout << "i = " << i << ", j = " << j << std::endl;
				std::cout << "bi_num_1 + bi_num_2 = " << (bi_num_1 + bi_num_2) << std::endl;
				std::cout << "BigInt(i_num_1 + i_num_2) = " << BigInt(i_num_1 + i_num_2) << std::endl;

				++k1;
			}

			if ((bi_num_1 - bi_num_2) == BigInt(i_num_1 - i_num_2)) {}
			else {
				std::cout << "-2 " << std::endl;

				++k2;
			}

			if ((bi_num_1 * bi_num_2) == BigInt(i_num_1 * i_num_2)) {}
			else {
				std::cout << "-3 " << std::endl;
				++k3;
			}

			if ((bi_num_1 / bi_num_2) == BigInt(i_num_1 / i_num_2)) {}
			else {
				std::cout << "-4 " << std::endl;
				++k4;
			}

			if ((bi_num_1 % bi_num_2) == BigInt(i_num_1 % i_num_2)) {}
			else {
				std::cout << "-5 " << std::endl;
				++k5;
			}
		}
	}


	std::cout << "Errors: k1 =  "<< k1 << ", k2 = " << k2 << ", k3 = " << k3 << ", k4 = " << k4 << ", k5 = " << k5 << std::endl;
}