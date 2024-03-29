﻿#include "../inc/BigInt.h"

BigInt::BigInt() : size(1), sign(true), num_str(new char[size + 1]) {
	num_str[0] = '0';
	num_str[0] = '\0';
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

BigInt::BigInt(char ch): size(1), sign(true), num_str(new char[2]) {
	num_str[0] = ch;
	num_str[1] = '\0';
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
	BigInt big_int_1 = *this, big_int_2 = big_int;
	big_int_1.sign = true, big_int_2.sign = true;

	if (sign && !big_int.sign) {
		if (big_int_1 >= big_int_2) {
			big_int_1.operator_assigment_minus(big_int_2);
			big_int_1.sign = true;
			
			swap(big_int_1);
		}
		else {
			big_int_2.operator_assigment_minus(big_int_1);
			big_int_2.sign = false;
			
			swap(big_int_2);
		}
	}
	else if (!sign && big_int.sign) {
		if (big_int_1 >= big_int_2) {
			big_int_1.operator_assigment_minus(big_int_2);
			big_int_1.sign = false;
			
			swap(big_int_1);
		}
		else {
			big_int_2.operator_assigment_minus(big_int_1);
			big_int_2.sign = true;
			
			swap(big_int_2);
		}
	}
	else {
		if (big_int_1 >= big_int_2) {
			big_int_1.operator_assigment_plus(big_int_2);
			big_int_1.sign = sign;
			
			swap(big_int_1);
		}
		else {
			big_int_2.operator_assigment_plus(big_int_1);
			big_int_2.sign = sign;
			
			swap(big_int_2);
		}
	}

	if ((num_str[0] == '0') && (size == 1)) {
		sign = true;
	}

	return *this;
}

BigInt& BigInt::operator-=(const BigInt& big_int) {
	BigInt big_int_1 = *this, big_int_2 = big_int;
	big_int_1.sign = true, big_int_2.sign = true;

	if (sign && big_int.sign) {
		if (big_int_1 >= big_int_2) {
			big_int_1.operator_assigment_minus(big_int_2);
			big_int_1.sign = true;

			swap(big_int_1);
		}
		else {
			big_int_2.operator_assigment_minus(big_int_1);
			big_int_2.sign = false;

			swap(big_int_2);
		}
	}
	else if (!sign && !big_int.sign) {
		if (big_int_1 >= big_int_2) {
			big_int_1.operator_assigment_minus(big_int_2);
			big_int_1.sign = false;

			swap(big_int_1);
		}
		else {
			big_int_2.operator_assigment_minus(big_int_1);
			big_int_2.sign = true;
			
			swap(big_int_2);
		}
	}
	else {
		if (big_int_1 >= big_int_2) {
			big_int_1.operator_assigment_plus(big_int_2);
			big_int_1.sign = sign;
			
			swap(big_int_1);
		}
		else {
			big_int_2.operator_assigment_plus(big_int_1);
			big_int_2.sign = sign;

			swap(big_int_2);
		}
	}

	if ((num_str[0] == '0') && (size == 1)) {
		sign = true;
	}
	
	return *this;
}

BigInt& BigInt::operator*=(const BigInt& big_int) {
	if (sign == big_int.sign) {
		operator_assigment_multi(big_int);
		sign = true;
	}
	else {
		operator_assigment_multi(big_int);

		if ((num_str[0] == '0') && (size == 1)) {
			sign = true;
		}
		else {
			sign = false;
		}
	}

	if ((num_str[0] == '0') && (size == 1)) {
		sign = true;
	}

	return *this;
}

BigInt& BigInt::operator/=(const BigInt& big_int) {
	if (sign && big_int.sign) {
		operator_assigment_division(big_int);
		sign = true;
	}
	else if (!sign && !big_int.sign) {
		BigInt big_int_1 = *this, big_int_2 = big_int;
		big_int_1.sign = true, big_int_2.sign = true;

		big_int_1.operator_assigment_division(big_int_2);
		swap(big_int_1);
	}
	else {
		BigInt big_int_1 = *this, big_int_2 = big_int;
		big_int_1.sign = true, big_int_2.sign = true;

		big_int_1.operator_assigment_division(big_int_2);
		big_int_1.sign = false;
		swap(big_int_1);
	}

	if ((num_str[0] == '0') && (size == 1)) {
		sign = true;
	}

	return *this;
}

BigInt& BigInt::operator%=(const BigInt& big_int) {
	if (sign && big_int.sign) {
		operator_assigment_remainder(big_int);
		sign = true;
	}
	else if (!sign && !big_int.sign) {
		BigInt big_int_1 = *this, big_int_2 = big_int;
		big_int_1.sign = true, big_int_2.sign = true;

		big_int_1.operator_assigment_remainder(big_int_2);
		big_int_1.sign = false;
		swap(big_int_1);
	}
	else {
		BigInt big_int_1 = *this, big_int_2 = big_int;
		big_int_1.sign = true, big_int_2.sign = true;

		big_int_1.operator_assigment_remainder(big_int_2);
		big_int_1.sign = sign;
		swap(big_int_1);
	}

	if ((num_str[0] == '0') && (size == 1)) {
		sign = true;
	}

	return *this;
}

BigInt& BigInt::operator++() {
	*this += 1;
	return *this;
}

BigInt& BigInt::operator--() {
	*this -= 1;
	return *this;
}

BigInt BigInt::operator++(int) {
	BigInt copy = *this;
	++(*this);

	return copy;
}

BigInt BigInt::operator--(int) {
	BigInt copy = *this;
	--(*this);

	return copy;
}

BigInt::operator bool() {
	if ((size == 1) && (num_str[0] == '0')) {
		return false;
	}
	
	return true;
}

size_t BigInt::len() const {
	return size;
}

void BigInt::cut() const {
	size_t cut_size = 0;
	sign = true;

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

	if (size == cut_size) {
		char* new_str = new char[2];
		new_str[0] = '0';
		new_str[1] = '\0';

		size = 1;
		std::swap(num_str, new_str);

		delete[] new_str;
	}
	else if (cut_size > 0) {
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

BigInt& BigInt::digit_multiplied() {
	++size;
	char* new_str = new char[size + 1];

	strncpy(new_str, num_str, size - 1);
	new_str[size - 1] = '0';
	new_str[size] = '\0';

	std::swap(num_str, new_str);
	delete[] new_str;

	return *this;
}

BigInt& BigInt::digit_division() {
	--size;
	char* new_str = new char[size + 1];

	strncpy(new_str, num_str, size);
	new_str[size] = '\0';

	std::swap(num_str, new_str);
	delete[] new_str;

	return *this;
}

void BigInt::operator_assigment_plus(const BigInt& big_int) {
	char* result_str = new char[size + 2];
	result_str[size + 1] = '\0';

	short sum_symbol = 0, sum_remainder = 0;

	for (long long int i = size - 1, j = big_int.size - 1; i >= 0; --i, --j) {
		if (j < 0) {
			sum_symbol = sum_remainder + (num_str[i] - '0');
		}
		else {
			sum_symbol = sum_remainder + (big_int.num_str[j] - '0') + (num_str[i] - '0');
		}

		sum_remainder = sum_symbol / 10;
		sum_symbol = sum_symbol % 10;

		result_str[i + 1] = sum_symbol + '0';
	}

	++size;
	result_str[0] = sum_remainder + '0';

	std::swap(result_str, num_str);
	cut();

	delete[] result_str;
}

void BigInt::operator_assigment_minus(const BigInt& big_int) {
	if ((big_int.size == 1) && (big_int.num_str[0] == '0')) {
		return;
	}

	char* result_str = new char[size + 1];
	result_str[size] = '\0';

	int diff_deep = 0, diff_remainder = 0;

	for (long long int i = size - 1, j = big_int.size - 1; i >= 0; --i, --j) {
		if ((j < 0) && ((num_str[i] - '0') - diff_deep < 0)) {
			diff_remainder = 9;
		}
		else if ((j < 0) && ((num_str[i] - '0') - diff_deep >= 0)) {
			diff_remainder = (num_str[i] - '0') - diff_deep;
			diff_deep = 0;
		}
		else if (((num_str[i] - '0') - (big_int.num_str[j] - '0') - diff_deep) >= 0) {
			diff_remainder = (num_str[i] - '0') - (big_int.num_str[j] - '0') - diff_deep;
			diff_deep = 0;
		}
		else if (((num_str[i] - '0') - (big_int.num_str[j] - '0') - diff_deep) < 0) {
			diff_remainder = 10 + (num_str[i] - '0') - (big_int.num_str[j] - '0') - diff_deep;
			diff_deep = 1;
		}

		result_str[i + 1] = diff_remainder + '0';
	}

	++size;

	std::swap(result_str, num_str);
	cut();

	delete[] result_str;
}

void BigInt::operator_assigment_multi(const BigInt& big_int) {
	BigInt result_of_multi = 0, temp = 0;
	short multi_symbol = 0, multi_remainder = 0;
	char* interim_result;

	if (size > big_int.size) {
		interim_result = new char[size + 2];
		interim_result[size + 1] = '\0';

		for (long long int i = 0, k = big_int.size - 1; i < big_int.size; ++i, --k) {
			for (long long int j = size - 1; j >= 0; --j) {
				multi_symbol = (big_int.num_str[i] - '0') * (num_str[j] - '0') + multi_remainder;
				multi_remainder = multi_symbol / 10;
				multi_symbol %= 10;

				interim_result[j + 1] = multi_symbol + '0';
			}

			interim_result[0] = multi_remainder + '0';
			multi_remainder = 0;

			temp = interim_result;
			temp.cut();

			for (long long int j = 0; j < k; ++j) {
				temp.digit_multiplied();
			}

			result_of_multi += temp;
		}
	}
	else {
		interim_result = new char[big_int.size + 2];
		interim_result[big_int.size + 1] = '\0';

		for (long long int i = 0, k = size - 1; i < size; ++i, --k) {
			for (long long int j = big_int.size - 1; j >= 0; --j) {
				multi_symbol = (big_int.num_str[j] - '0') * (num_str[i] - '0') + multi_remainder;
				multi_remainder = multi_symbol / 10;
				multi_symbol %= 10;

				interim_result[j + 1] = multi_symbol + '0';
			}

			interim_result[0] = multi_remainder + '0';
			multi_remainder = 0;

			temp = interim_result;
			temp.cut();

			for (long long int j = 0; j < k; ++j) {
				temp.digit_multiplied();
			}

			result_of_multi += temp;
		}
	}

	*this = result_of_multi;
	delete[] interim_result;
}

void BigInt::operator_assigment_division(const BigInt& big_int) {
	if (*this < big_int) {
		delete[] num_str;

		size = 1;
		sign = true;
		num_str = new char[2];
		num_str[0] = '0';
		num_str[1] = '\0';

		return;
	}

	if (*this == big_int) {
		delete[] num_str;

		size = 1;
		sign = true;
		num_str = new char[2];
		num_str[0] = '1';
		num_str[1] = '\0';

		return;
	}

	if ((big_int.size == 1) && (big_int.num_str[0] == '1')) {
		return;
	}

	if ((big_int.size == 1) && (big_int.num_str[0] == '0')) {
		throw "Error! Devision on zero!";
	}

	BigInt result = 0, div_remainder = 0, ZERO = 0;
	size_t index_of_deep = 0;

	for (size_t i = 0; i < size; ++i) {
		BigInt bi_num = num_str[i];

		if ((index_of_deep == 0) && ((bi_num + div_remainder - big_int) >= ZERO)) {
			BigInt j;
			for (j = 1; (bi_num + div_remainder - (big_int * j)) >= ZERO; ++j) {}
			--j;

			result += j;
			result.digit_multiplied();

			div_remainder = bi_num + div_remainder - big_int * j;

			if (!((div_remainder.size) == 1 && (div_remainder.num_str[0] == '0'))) {
				div_remainder.digit_multiplied();
			}
		}
		else if ((index_of_deep == 0) && (bi_num - big_int + div_remainder < ZERO)) {
			if (!((result.size) == 1 && (result.num_str[0] == '0'))) {
				result.digit_multiplied();
			}

			div_remainder += bi_num;

			if (!((div_remainder.size) == 1 && (div_remainder.num_str[0] == '0'))) {
				div_remainder.digit_multiplied();
			}

			++index_of_deep;
		}
		else if (index_of_deep != 0) {
			if (bi_num + div_remainder - big_int >= ZERO) {
				BigInt j;
				for (j = 1; (bi_num + div_remainder - (big_int * j)) >= ZERO; ++j) {}
				--j;

				result += j;
				result.digit_multiplied();
				index_of_deep = 0;

				div_remainder = (bi_num + div_remainder) - (big_int * j);

				if (!((div_remainder.size) == 1 && (div_remainder.num_str[0] == '0'))) {
					div_remainder.digit_multiplied();
				}
			}
			else {
				if (!((result.size) == 1 && (result.num_str[0] == '0'))) {
					result.digit_multiplied();
				}

				div_remainder += bi_num;

				if (!((div_remainder.size) == 1 && (div_remainder.num_str[0] == '0'))) {
					div_remainder.digit_multiplied();
				}

				++index_of_deep;
			}
		}
	}

	result.digit_division();

	if (!((div_remainder.size) == 1 && (div_remainder.num_str[0] == '0'))) {
		div_remainder.digit_division();
	}

	if (div_remainder == big_int) {
		++result;
	}

	*this = result;
}

void BigInt::operator_assigment_remainder(const BigInt& big_int) {
	if (*this == big_int) {
		delete[] num_str;

		size = 1;
		sign = true;
		num_str = new char[2];
		num_str[0] = '0';
		num_str[1] = '\0';

		return;
	}

	if (*this < big_int) {
		return;
	}


	if ((big_int.size == 1) && (big_int.num_str[0] == '1')) {
		delete[] num_str;

		size = 1;
		sign = true;
		num_str = new char[2];
		num_str[0] = '0';
		num_str[1] = '\0';

		return;
	}

	if ((big_int.size == 1) && (big_int.num_str[0] == '0')) {
		throw "Error! Devision on zero!";
	}

	BigInt result = 0, div_remainder = 0, ZERO = 0;
	size_t index_of_deep = 0;

	for (size_t i = 0; i < size; ++i) {
		BigInt bi_num = num_str[i];

		if ((index_of_deep == 0) && ((bi_num + div_remainder - big_int) >= ZERO)) {
			BigInt j;
			for (j = 1; (bi_num + div_remainder - (big_int * j)) >= ZERO; ++j) {}
			--j;

			result += j;
			result.digit_multiplied();

			div_remainder = bi_num + div_remainder - big_int * j;

			if (!((div_remainder.size) == 1 && (div_remainder.num_str[0] == '0'))) {
				div_remainder.digit_multiplied();
			}
		}
		else if ((index_of_deep == 0) && (bi_num - big_int + div_remainder < ZERO)) {
			if (!((result.size) == 1 && (result.num_str[0] == '0'))) {
				result.digit_multiplied();
			}

			div_remainder += bi_num;

			if (!((div_remainder.size) == 1 && (div_remainder.num_str[0] == '0'))) {
				div_remainder.digit_multiplied();
			}

			++index_of_deep;
		}
		else if (index_of_deep != 0) {
			if (bi_num + div_remainder - big_int >= ZERO) {
				BigInt j;
				for (j = 1; (bi_num + div_remainder - (big_int * j)) >= ZERO; ++j) {}
				--j;

				result += j;
				result.digit_multiplied();
				index_of_deep = 0;

				div_remainder = (bi_num + div_remainder) - (big_int * j);

				if (!((div_remainder.size) == 1 && (div_remainder.num_str[0] == '0'))) {
					div_remainder.digit_multiplied();
				}
			}
			else {
				if (!((result.size) == 1 && (result.num_str[0] == '0'))) {
					result.digit_multiplied();
				}

				div_remainder += bi_num;

				if (!((div_remainder.size) == 1 && (div_remainder.num_str[0] == '0'))) {
					div_remainder.digit_multiplied();
				}

				++index_of_deep;
			}
		}
	}

	result.digit_division();

	if (!((div_remainder.size) == 1 && (div_remainder.num_str[0] == '0'))) {
		div_remainder.digit_division();
	}

	if (div_remainder == big_int) {
		++result;
	}

	*this = div_remainder;
}

std::ostream& operator<<(std::ostream& out, const BigInt& big_int) {
	if (!big_int.sign) {
		out << '-';
	}

	out << big_int.num_str;
	return out;
}

std::istream& operator>>(std::istream& cin, BigInt& big_int) {
	return cin;
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
			else if ((big_int_1.num_str[i] < big_int_2.num_str[i]) && (big_int_1.sign)) {
				return false;
			}
			else if ((big_int_1.num_str[i] < big_int_2.num_str[i]) && (!big_int_1.sign)) {
				return true;
			}
			else if ((big_int_1.num_str[i] > big_int_2.num_str[i]) && (!big_int_1.sign)) {
				return false;
			}
		}
	}

	return false;
}

bool operator<(const BigInt& big_int_1, const BigInt& big_int_2) {
	return (big_int_2 > big_int_1);
}

bool operator>=(const BigInt& big_int_1, const BigInt& big_int_2) {
	return ((big_int_1 > big_int_2) || (big_int_1 == big_int_2));
}

bool operator<=(const BigInt& big_int_1, const BigInt& big_int_2) {
	return ((big_int_1 < big_int_2) || (big_int_1 == big_int_2));
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

BigInt operator*(const BigInt& big_int_1, const BigInt& big_int_2) {
	BigInt result = big_int_1;
	result *= big_int_2;
	
	return result;
}

BigInt operator/(const BigInt& big_int_1, const BigInt& big_int_2) {
	BigInt result = big_int_1;
	result /= big_int_2;

	return result;
}

BigInt operator%(const BigInt& big_int_1, const BigInt& big_int_2) {
	BigInt result = big_int_1;
	result %= big_int_2;

	return result;
}