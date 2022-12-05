﻿#include "../inc/BigInt.h"

BigInt::BigInt() : size(1), sign(true), num_str(new char[size + 1]) {
	num_str = "0";
}

BigInt::BigInt(const BigInt& big_int): size(big_int.size), sign(big_int.sign), num_str(new char[size + 1]) {
	strcpy(num_str, big_int.num_str);
}

BigInt& BigInt::operator=(BigInt big_int) {
	swap(big_int);
	return *this;
}

BigInt::~BigInt() {
	delete[] num_str;
}

BigInt::BigInt(int num) : num_str(new char[12]) {
	_itoa(num, num_str, 10);
	size = strlen(num_str);

	if (size < 11) {
		char* cut_str = new char[size + 1];
		strncpy(cut_str, num_str, size);
		cut_str[size] = '\0';

		std::swap(cut_str, num_str);
		delete[] cut_str;
	}

	cut();
}

BigInt::BigInt(long long int num) : num_str(new char[21]) {
	_i64toa(num, num_str, 10);
	size = strlen(num_str);

	if (size < 20) {
		char* cut_str = new char[size + 1];
		strncpy(cut_str, num_str, size);
		cut_str[size] = '\0';

		std::swap(cut_str, num_str);
		delete[] cut_str;
	}

	cut();
}

BigInt::BigInt(const char* str) : size(strlen(str)), num_str(new char[size + 1]) {
	strcpy(num_str, str);
	cut();
}

BigInt& BigInt::operator+=(const BigInt& big_int) {
	if ((sign != big_int.sign) && sign) {
		BigInt abs = big_int.num_str;

		if (*this < abs) {
			sign = false;
		}

		operator_assigment_minus(big_int);
	}
	else if ((sign != big_int.sign) && !sign) {
		BigInt abs = num_str;

		if (abs < big_int) {
			sign = true;
		}

		operator_assigment_minus(big_int);
	}
	else {
		operator_assigment_plus(big_int);
	}

	return *this;
}

BigInt& BigInt::operator-=(const BigInt& big_int) {
	if ((sign == big_int.sign) && sign) {
		if (*this < big_int) {
			sign = false;
		}

		operator_assigment_minus(big_int);
	}
	else if ((sign == big_int.sign) && !sign) {
		if (*this < big_int) {
			sign = true;
		}

		operator_assigment_minus(big_int);
	}
	else {
		operator_assigment_plus(big_int);
	}
	
	return *this;
}

size_t BigInt::len() const {
	return size;
}

void BigInt::cut() const {
	size_t cut_size = 0;

	for (size_t i = 0; i < size; ++i) {
		if ((num_str[i] >= '1') && (num_str[i] <= '9')) {
			break;
		}
		else if (num_str[i] == '-') {
			sign = false;
			++cut_size;
		}
		else {
			++cut_size;
		}
	}

	if ((num_str[0] == '0') && (size == 1)) {
		sign = true;
		cut_size = 0;
	}

	if (cut_size > 0) {
		char* new_str = new char[size - cut_size + 1];
		strncpy(new_str, &num_str[cut_size], size - cut_size);
		new_str[size - cut_size] = '\0';

		size = size - cut_size;		
		std::swap(num_str, new_str);

		delete[] new_str;
	}
}

void BigInt::swap(BigInt& big_int) {
	std::swap(sign, big_int.sign);
	std::swap(size, big_int.size);
	std::swap(num_str, big_int.num_str);
}

BigInt& BigInt::operator_assigment_plus(const BigInt& big_int) {
	size_t max_size = (size > big_int.size) ? (size) : (big_int.size);
	size_t min_size = (size > big_int.size) ? (big_int.size) : (size);

	char* result_str = new char[max_size + 2];
	result_str[max_size + 1] = '\0';

	short sum_symbol = 0, sum_remainder = 0;

	for (long long int i = max_size - 1, j = min_size - 1; i >= 0; --i, --j) {
		if ((j < 0) && (big_int.size == max_size)) {
			sum_symbol = sum_remainder + (big_int.num_str[i] - '0');
		}
		else if ((j < 0) && (size == max_size)) {
			sum_symbol = sum_remainder + (num_str[i] - '0');
		}
		else if (size == max_size) {
			sum_symbol = sum_remainder + (big_int.num_str[j] - '0') + (num_str[i] - '0');
		}
		else if (big_int.size == max_size) {
			sum_symbol = sum_remainder + (big_int.num_str[i] - '0') + (num_str[j] - '0');
		}

		sum_remainder = sum_symbol / 10;
		sum_symbol = sum_symbol % 10;

		result_str[i + 1] = sum_symbol + '0';
	}

	size = max_size + 1;
	std::swap(result_str, num_str);
	cut();

	delete[] result_str;
	return *this;
}

BigInt& BigInt::operator_assigment_minus(const BigInt& big_int) {
	size_t max_size = (size > big_int.size) ? (size) : (big_int.size);
	size_t min_size = (size > big_int.size) ? (big_int.size) : (size);

	char* result_str = new char[max_size + 2];
	result_str[max_size + 1] = '\0';

	short diff_deep = 0, diff_remainder = 0;

	if (max_size == size) {
		for (long long int i = max_size - 1, j = min_size - 1; i >= 0; --i, --j) {
			if (j < 0) {
				diff_remainder = (num_str[i] - '0') - diff_deep;
				diff_deep = 0;
			}
			else if (((num_str[i] - '0') - (big_int.num_str[j] - '0') - diff_deep) >= 0) {
				diff_remainder = (num_str[i] - '0') - (big_int.num_str[j] - '0') - diff_deep;
				diff_deep = 0;
			}
			else if (((num_str[i] - '0') - (big_int.num_str[j] - '0') - diff_deep) < 0) {
				++diff_deep;
				diff_remainder = 10 + (num_str[i] - '0') - (big_int.num_str[j] - '0');
			}

			result_str[i + 1] = diff_remainder + '0';
		}
	}
	else {
		for (long long int i = max_size - 1, j = min_size - 1; i >= 0; --i, --j) {
			if (j < 0) {
				diff_remainder = (big_int.num_str[i] - '0') - diff_deep;
				diff_deep = 0;
			}
			else if (((big_int.num_str[i] - '0') - (num_str[j] - '0') - diff_deep) >= 0) {
				diff_remainder = (big_int.num_str[i] - '0') - (num_str[j] - '0') - diff_deep;
				diff_deep = 0;
			}
			else if (((big_int.num_str[i] - '0') - (num_str[j] - '0') - diff_deep) < 0) {
				++diff_deep;
				diff_remainder = 10 + (big_int.num_str[i] - '0') - (num_str[j] - '0');
			}

			result_str[i + 1] = diff_remainder + '0';
		}
	}

	size = max_size + 1;

	std::swap(result_str, num_str);
	cut();

	delete[] result_str;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const BigInt& big_int) {
	if (!big_int.sign) {
		out << '-';
	}

	out << big_int.num_str;
	return out;
}

bool operator==(const BigInt& big_int_1, const BigInt& big_int_2) {
	if ((big_int_1.size != big_int_2.size) || (big_int_1.sign != big_int_2.sign)) {
		return false;
	}
	else {
		for (size_t i = 0; i < big_int_1.size; ++i) {
			if (big_int_1.num_str[i] != big_int_2.num_str[i]) {
				return false;
			}
		}
	}

	return true;
}

bool operator!=(const BigInt& big_int_1, const BigInt& big_int_2) {
	return !(big_int_1 == big_int_2);
}

bool operator>(const BigInt& big_int_1, const BigInt& big_int_2) {
	if (big_int_1 == big_int_2) {
		return false;
	}
	
	if ((big_int_1.sign != big_int_2.sign) && big_int_1.sign) {
		return true;
	}
	else if ((big_int_1.sign != big_int_2.sign) && big_int_2.sign) {
		return false;
	}

	size_t max_size = (big_int_1.size > big_int_2.size) ? (big_int_1.size) : (big_int_2.size);
	size_t min_size = (big_int_1.size > big_int_2.size) ? (big_int_2.size) : (big_int_1.size);

	if ((max_size != min_size) && (max_size == big_int_1.size)) {
		return true;
	}
	else if (max_size == min_size) {
		for (size_t i = 0; i < max_size; ++i) {
			if ((big_int_1.num_str[i] > big_int_2.num_str[i]) && (big_int_1.sign)) {
				return true;
			}
			else if ((big_int_1.num_str[i] < big_int_2.num_str[i]) && (!big_int_1.sign)) {
				return true;
			}
		}
	}
	
	return false;
}

bool operator<(const BigInt& big_int_1, const BigInt& big_int_2) {
	return (big_int_2 > big_int_1);
}

bool operator>=(const BigInt& big_int_1, const BigInt& big_int_2) {
	return !(big_int_1 < big_int_2);
}

bool operator<=(const BigInt& big_int_1, const BigInt& big_int_2) {
	return !(big_int_1 > big_int_2);
}

BigInt operator+(const BigInt& big_int_1, const BigInt& big_int_2) {
	BigInt result = big_int_1;
	result += big_int_2;

	return result;
}

BigInt operator-(const BigInt& big_int_1, const BigInt& big_int_2) {
	BigInt result = big_int_1;
	result -= big_int_2;

	return result;
}