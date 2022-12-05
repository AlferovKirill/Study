#ifndef BigInt_h
#define BigInt_h
#include <iostream>
#include <utility>

class BigInt {
public:
	BigInt();
	BigInt(const BigInt& big_int);
	BigInt& operator=(BigInt big_int);
	~BigInt();

	BigInt(int num);
	BigInt(long long int num);
	BigInt(const char* num_str);

	BigInt& operator+=(const BigInt& big_int);
	BigInt& operator-=(const BigInt& big_int);

	size_t len() const;

	friend std::ostream& operator<<(std::ostream& out, const BigInt& big_int);

	friend bool operator==(const BigInt& big_int_1, const BigInt& big_int_2);
	friend bool operator!=(const BigInt& big_int_1, const BigInt& big_int_2);
	friend bool operator>(const BigInt& big_int_1, const BigInt& big_int_2);
	friend bool operator<(const BigInt& big_int_1, const BigInt& big_int_2);
	friend bool operator>=(const BigInt& big_int_1, const BigInt& big_int_2);
	friend bool operator<=(const BigInt& big_int_1, const BigInt& big_int_2);

	friend BigInt operator+(const BigInt& big_int_1, const BigInt& big_int_2);
	friend BigInt operator-(const BigInt& big_int_1, const BigInt& big_int_2);
private:
	mutable bool sign;
	mutable size_t size;
	mutable char* num_str = nullptr;

	void cut() const;
	void swap(BigInt& big_int);

	BigInt& operator_assigment_plus(const BigInt& big_int);
	BigInt& operator_assigment_minus(const BigInt& big_int);
};

#endif