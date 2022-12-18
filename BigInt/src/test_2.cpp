#include "../inc/BigInt.h"
#include <iostream>

void test_alg_operators() {
	BigInt bi_num_1, bi_num_2;
	long long int i_num_1, i_num_2;
	
	size_t tests = 0, k1 = 0, k2 = 0, k3 = 0, k4 = 0, k5 = 0;

	for (long long int i = -1000; i < 1000; ++i) {
		for (long long int j = -1000; j < 1000; ++j) {
			if (j == 0) {
				continue;
			}

			++tests;

			bi_num_1 = i; bi_num_2 = j;
			i_num_1 = i; i_num_2 = j;

			if ((bi_num_1 + bi_num_2) == BigInt(i_num_1 + i_num_2)) {}
			else {
				std::cout << "1" << std::endl;
				std::cout << "i = " << i << ", j = " << j << std::endl;
				std::cout << "bi_num_1 + bi_num_2 = " << (bi_num_1 + bi_num_2) << std::endl;
				std::cout << "BigInt(i_num_1 + i_num_2) = " << BigInt(i_num_1 + i_num_2) << std::endl;

				++k1;
			}

			if ((bi_num_1 - bi_num_2) == BigInt(i_num_1 - i_num_2)) {}
			else {
				std::cout << "2" << std::endl;
				std::cout << "i = " << i << ", j = " << j << std::endl;
				std::cout << "bi_num_1 - bi_num_2 = " << (bi_num_1 - bi_num_2) << std::endl;
				std::cout << "BigInt(i_num_1 - i_num_2) = " << BigInt(i_num_1 - i_num_2) << std::endl;

				++k2;
			}

			if ((bi_num_1 * bi_num_2) == BigInt(i_num_1 * i_num_2)) {}
			else {
				std::cout << "3" << std::endl;
				std::cout << "i = " << i << ", j = " << j << std::endl;
				std::cout << "bi_num_1 * bi_num_2 = " << (bi_num_1 * bi_num_2) << std::endl;
				std::cout << "BigInt(i_num_1 * i_num_2) = " << BigInt(i_num_1 * i_num_2) << std::endl;

				++k3;
			}

			if ((bi_num_1 / bi_num_2) == BigInt(i_num_1 / i_num_2)) {}
			else {
				std::cout << "4" << std::endl;
				std::cout << "i = " << i << ", j = " << j << std::endl;
				std::cout << "bi_num_1 / bi_num_2 = " << (bi_num_1 / bi_num_2) << std::endl;
				std::cout << "BigInt(i_num_1 / i_num_2) = " << BigInt(i_num_1 / i_num_2) << std::endl;

				++k4;
			}

			if ((bi_num_1 % bi_num_2) == BigInt(i_num_1 % i_num_2)) {}
			else {
				std::cout << "5" << std::endl;
				std::cout << "i = " << i << ", j = " << j << std::endl;
				std::cout << "bi_num_1 % bi_num_2 = " << (bi_num_1 % bi_num_2) << std::endl;
				std::cout << "BigInt(i_num_1 % i_num_2) = " << BigInt(i_num_1 % i_num_2) << std::endl;

				++k5;
			}
		}
	}

	std::cout << "Errors: sum = " << k1 << ", diff = " << k2 << ", multi = " << k3 << ", div = " << k4 << ", mod = " << k5 << std::endl;
	std::cout << "Total errors = " << (k1 + k2 + k3 + k4 + k5) << std::endl;
	std::cout << "Number of tests = " << tests << std::endl;
}