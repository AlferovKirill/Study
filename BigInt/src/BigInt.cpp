#include "../inc/BigInt.h"

BigInt::BigInt() : size(1), num_str(new char[size + 1]) {
	num_str = "0";
}

BigInt::BigInt(const BigInt& big_int): size(big_int.size), num_str(new char[size + 1]) {
	strcpy(num_str, big_int.num_str);
}

BigInt& BigInt::operator=(BigInt big_int) {
	std::swap(size, big_int.size);
	std::swap(num_str, big_int.num_str);
	return *this;
}

BigInt::~BigInt() {
	delete[] num_str;
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
	return operator_assigment_plus(big_int);
}

BigInt& BigInt::operator-=(const BigInt& big_int) {
	return operator_assigment_minus(big_int);
}

size_t BigInt::len() const {
	return size;
}

void BigInt::cut() const {
	size_t cut_size = 0;

	for (size_t i = 0; i < size; ++i) {
		if (((num_str[i] >= '1') && (num_str[i] <= '9')) || (num_str[i] == '-')) {
			break;
		}
		else {
			++cut_size;
		}
	}

	if ((num_str[0] == '0') && (size == 1)) {
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
	return *this;
}

std::ostream& operator<<(std::ostream& out, const BigInt& big_int) {
	out << big_int.num_str;
	return out;
}

BigInt operator+(const BigInt& big_int_1, const BigInt& big_int_2) {
	BigInt result;
	result += big_int_1;

	return result;
}

BigInt operator-(const BigInt& big_int_1, const BigInt& big_int_2) {
	BigInt result;
	result -= big_int_1;

	return result;
}