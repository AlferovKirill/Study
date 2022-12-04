#include "../inc/string.h"
#include <iostream>

int main() {
	String s1;
	String s2("123");
	String s3(3, '1');
	String s4 = s3;
	String s5 = {'a', 'b', 'c', 'd'};

	std::cout << "s1 = " << s1 << std::endl;
	std::cout << "s2 = " << s2 << std::endl;
	std::cout << "s3 = " << s3 << std::endl;
	std::cout << "s4 = " << s4 << std::endl;
	std::cout << "s5 = " << s5 << std::endl;
	std::cout << "--------------------------" << std::endl;

	s2 = s4;

	std::cout << "s2 = s4" << std::endl;
	std::cout << "s2 = " << s2 << std::endl;
	std::cout << "s4 = " << s4 << std::endl;

	std::cout << "--------------------------"<< std::endl;
	std::cout << "s4.len() = " << s4.len() << std::endl;
	s4[1] = '5';
	std::cout << "s4[1] = '5', s4 = " << s4 << std::endl;
	std::cout << "s5[3] = " << s5[3] << std::endl;

	std::cout << "--------------------------" << std::endl;

	s1 = "12345";
	s2 = "54321";

	std::cout << "s1 = " << s1 << std::endl;
	std::cout << "s2 = " << s2 << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "s1 == s2: " << (s2 == s4) << std::endl;
	std::cout << "s1 != s2: " << (s2 != s4) << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "s1 < s2: " << (s1 < s2) << std::endl;
	std::cout << "s2 < s1: " << (s2 < s1) << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "s1 > s2: " << (s1 > s2) << std::endl;
	std::cout << "s2 > s1: " << (s2 > s1) << std::endl;

	std::cout << "--------------------------" << std::endl;

	s3 = "abcd";
	s4 = "123456";

	std::cout << "s1 = " << s1 << std::endl;
	std::cout << "s2 = " << s2 << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "s1 == s2: " << (s2 == s4) << std::endl;
	std::cout << "s1 != s2: " << (s2 != s4) << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "s1 < s2: " << (s1 < s2) << std::endl;
	std::cout << "s2 < s1: " << (s2 < s1) << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "s1 > s2: " << (s1 > s2) << std::endl;
	std::cout << "s2 > s1: " << (s2 > s1) << std::endl;

	return 0;
}