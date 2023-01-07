#include "../inc/BigInt.h"
#include <iostream>

void Simple_test(BigInt big_int_1, BigInt big_int_2) {
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "BigInt #1 = " << big_int_1 << "\nBigInt #2 = " << big_int_2 << std::endl << std::endl;

	std::cout << "BigInt #1 + BigInt #2 = " << big_int_1 + big_int_2 << std::endl;
	std::cout << "BigInt #1 - BigInt #2 = " << big_int_1 - big_int_2 << std::endl;
	std::cout << "BigInt #1 * BigInt #2 = " << big_int_1 * big_int_2 << std::endl;
	std::cout << "BigInt #1 / BigInt #2 = " << big_int_1 / big_int_2 << std::endl;
	std::cout << "BigInt #1 % BigInt #2 = " << big_int_1 % big_int_2 << std::endl << std::endl;

	std::cout << "BigInt #1 = " << big_int_1 << "\nBigInt #2 = " << big_int_2 << std::endl << std::endl;
	std::cout << "++BigInt #1 = " << ++big_int_1 << std::endl;
	std::cout << "BigInt #1++ = " << big_int_1++ << std::endl;
	std::cout << "BigInt #1-- = " << big_int_1-- << std::endl;
	std::cout << "--BigInt #1 = " << --big_int_1 << std::endl << std::endl;

	if (big_int_1) {
		std::cout << "BigInt #1 = true" << std::endl;
	}
	else {
		std::cout << "BigInt #1 = false" << std::endl;
	}

	std::cout << "BigInt #1.len() = " << big_int_1.len() << std::endl << std::endl;

	std::cout << "BigInt #1 < BigInt #2 = " << (big_int_1 < big_int_2) << std::endl;
	std::cout << "BigInt #1 > BigInt #2 = " << (big_int_1 > big_int_2) << std::endl;
	std::cout << "BigInt #1 <= BigInt #2 = " << (big_int_1 <= big_int_2) << std::endl;
	std::cout << "BigInt #1 >= BigInt #2 = " << (big_int_1 >= big_int_2) << std::endl;
	std::cout << "BigInt #1 == BigInt #2 = " << (big_int_1 == big_int_2) << std::endl;
	std::cout << "BigInt #1 != BigInt #2 = " << (big_int_1 != big_int_2) << std::endl << std::endl;
	std::cout << "----------------------------------------" << std::endl;
}

void Test_all_alg_operators(long long int test_limit_begin = -1000, long long int test_limit_end = 1000) {
	BigInt bi_num_1, bi_num_2;
	long long int i_num_1, i_num_2;

	size_t tests = 0, k1 = 0, k2 = 0, k3 = 0, k4 = 0, k5 = 0;

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Test all integers from " << test_limit_begin << " to " << test_limit_end << "." << std::endl;

	for (long long int i = test_limit_begin; i < test_limit_end; ++i) {
		for (long long int j = test_limit_begin; j < test_limit_end; ++j) {
			if (j == 0) {
				continue;
			}

			++tests;

			bi_num_1 = i; bi_num_2 = j;
			i_num_1 = i; i_num_2 = j;

			if ((bi_num_1 + bi_num_2) == BigInt(i_num_1 + i_num_2)) {}
			else {
				std::cout << "Error type #1" << std::endl;
				std::cout << "BigInt #1 = " << i << ", BigInt #2 = " << j << std::endl;
				std::cout << "BigInt #1 + BigInt #2 = " << (bi_num_1 + bi_num_2) << std::endl;
				std::cout << "BigInt(BigInt #1 + BigInt #2) = " << BigInt(i_num_1 + i_num_2) << std::endl;

				++k1;
			}

			if ((bi_num_1 - bi_num_2) == BigInt(i_num_1 - i_num_2)) {}
			else {
				std::cout << "Error type #2" << std::endl;
				std::cout << "BigInt #1 = " << i << ", BigInt #2 = " << j << std::endl;
				std::cout << "BigInt #1 - BigInt #2 = " << (bi_num_1 - bi_num_2) << std::endl;
				std::cout << "BigInt(BigInt #1 - BigInt #2) = " << BigInt(i_num_1 - i_num_2) << std::endl;

				++k2;
			}

			if ((bi_num_1 * bi_num_2) == BigInt(i_num_1 * i_num_2)) {}
			else {
				std::cout << "Error type #3" << std::endl;
				std::cout << "BigInt #1 = " << i << ", BigInt #2 = " << j << std::endl;
				std::cout << "BigInt #1 * BigInt #2 = " << (bi_num_1 * bi_num_2) << std::endl;
				std::cout << "BigInt(BigInt #1 * BigInt #2) = " << BigInt(i_num_1 * i_num_2) << std::endl;

				++k3;
			}

			if ((bi_num_1 / bi_num_2) == BigInt(i_num_1 / i_num_2)) {}
			else {
				std::cout << "Error type #4" << std::endl;
				std::cout << "BigInt #1 = " << i << ", BigInt #2 = " << j << std::endl;
				std::cout << "BigInt #1 / BigInt #2 = " << (bi_num_1 / bi_num_2) << std::endl;
				std::cout << "BigInt(BigInt #1 / BigInt #2) = " << BigInt(i_num_1 / i_num_2) << std::endl;


				++k4;
			}

			if ((bi_num_1 % bi_num_2) == BigInt(i_num_1 % i_num_2)) {}
			else {
				std::cout << "Error type #5" << std::endl;
				std::cout << "BigInt #1 = " << i << ", BigInt #2 = " << j << std::endl;
				std::cout << "BigInt #1 % BigInt #2 = " << (bi_num_1 % bi_num_2) << std::endl;
				std::cout << "BigInt(BigInt #1 % BigInt #2) = " << BigInt(i_num_1 % i_num_2) << std::endl;

				++k5;
			}
		}
	}

	std::cout << "Number of tests = " << tests << ", total errors = " << (k1 + k2 + k3 + k4 + k5) << std::endl;
	std::cout << "Errors: sum = " << k1 << ", difference = " << k2 << ", multiplication = " << k3 << ", division = " << k4 << ", remainder = " << k5 << std::endl;
	std::cout << "----------------------------------------" << std::endl;
}

int main() {
	Simple_test("987654321987654321", 111);
	Simple_test(10, 10);
	Simple_test(-12324, 6);

	Test_all_alg_operators();

	return 0;
}