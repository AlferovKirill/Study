#include "../inc/Vector.hpp"
#include <string>

int main() {
	Vector<int> v1;

	v1.reserve(40);

	v1.push_back(4);
	v1.push_back(5);

	v1.resize(30, 1);

	std::cout << "1. v1 = " << v1[0] << " " << v1[1] << " " << v1[2] << std::endl;

	Vector<int> v2(3);

	std::cout << "2. v2 = " << v2[0] << " " << v2[1] << " " << v2[2] << std::endl;

	v2 = v1;

	std::cout << "3. v2 = " << v2[0] << " " << v2[1] << " " << v2[2] << std::endl;

	v2[0] = 10;
	v2[1] = 10;
	v2[2] = 10;

	std::cout << "4. v2 = " << v2[0] << " " << v2[1] << " " << v2[2] << std::endl;

	Vector<int> v3 = v2;

	std::cout << "5. v3 = " << v3[0] << " " << v3[1] << " " << v3[2] << std::endl << std::endl;

	for (Vector<int>::const_iterator it = v1.cbegin(); it != v1.cend(); ++it) {
		std::cout << *it << " ";
	}

	std::cout << std::endl << std::endl << "v1.end() - v1.begin() = " << (v1.end() - v1.begin()) << std::endl << std::endl;

	for (int i : v2) {
		std::cout << i << " ";
	}

	std::cout << std::endl << std::endl << "v1.begin() < v1.end() = " << (v1.begin() < v1.end()) << std::endl;
	std::cout << "v1.begin() > v1.end() = " << (v1.begin() > v1.end()) << std::endl;

	std::cout << std::endl << "v1.begin() <= v1.end() = " << (v1.begin() <= v1.end()) << std::endl;
	std::cout << "v1.begin() >= v1.end() = " << (v1.begin() >= v1.end()) << std::endl;

	std::cout << std::endl << "v1.begin() == v1.end() = " << (v1.begin() == v1.end()) << std::endl;
	std::cout << "v1.begin() != v1.end() = " << (v1.begin() != v1.end()) << std::endl << std::endl;

	std::cout << std::endl << std::endl << "v1.begin() < v1.begin() = " << (v1.begin() < v1.begin()) << std::endl;
	std::cout << "v1.begin() > v1.begin() = " << (v1.begin() > v1.begin()) << std::endl;

	std::cout << std::endl << "v1.begin() <= v1.begin() = " << (v1.begin() <= v1.begin()) << std::endl;
	std::cout << "v1.begin() >= v1.begin() = " << (v1.begin() >= v1.begin()) << std::endl;

	std::cout << std::endl << "v1.begin() == v1.begin() = " << (v1.begin() == v1.begin()) << std::endl;
	std::cout << "v1.begin() != v1.begin() = " << (v1.begin() != v1.begin()) << std::endl << std::endl;

	std::cout << std::endl << std::endl << "v1.rend() - v1.rbegin() = " << (v1.rend() - v1.rbegin()) << std::endl << std::endl;

	for (Vector<int>::const_reverse_iterator it = v1.crbegin(); it != v1.crend(); ++it) {
		std::cout << *it << " ";
	}

	std::cout << std::endl << std::endl << "v1.rbegin() < v1.rend() = " << (v1.rbegin() < v1.rend()) << std::endl;
	std::cout << "v1.rbegin() > v1.rend() = " << (v1.rbegin() > v1.rend()) << std::endl;

	std::cout << std::endl << "v1.rbegin() <= v1.rend() = " << (v1.rbegin() <= v1.rend()) << std::endl;
	std::cout << "v1.rbegin() >= v1.rend() = " << (v1.rbegin() >= v1.rend()) << std::endl;

	std::cout << std::endl << "v1.rbegin() == v1.rend() = " << (v1.rbegin() == v1.rend()) << std::endl;
	std::cout << "v1.rbegin() != v1.rend() = " << (v1.rbegin() != v1.rend()) << std::endl << std::endl;

	std::cout << std::endl << std::endl << "v1.rbegin() < v1.rbegin() = " << (v1.rbegin() < v1.rbegin()) << std::endl;
	std::cout << "v1.rbegin() > v1.rbegin() = " << (v1.rbegin() > v1.rbegin()) << std::endl;

	std::cout << std::endl << "v1.rbegin() <= v1.rbegin() = " << (v1.rbegin() <= v1.rbegin()) << std::endl;
	std::cout << "v1.rbegin() >= v1.rbegin() = " << (v1.rbegin() >= v1.rbegin()) << std::endl;

	std::cout << std::endl << "v1.rbegin() == v1.rbegin() = " << (v1.rbegin() == v1.rbegin()) << std::endl;
	std::cout << "v1.rbegin() != v1.rbegin() = " << (v1.rbegin() != v1.rbegin()) << std::endl;

	std::cout << std::string(50, '-') << std::endl;

	Vector<std::string> v4;
	
	v4.push_back("111");
	v4.push_back("222");
	v4.push_back("333");
	v4.push_back("444");
	v4.push_back("555");

	for (auto item : v4) {
		std::cout << item << " ";
	}

	std::cout << std::endl;

	auto v4_iter = v4.begin();
	auto v4_r_iter = v4.rbegin();

	std::cout << "*v4_iter = "<< *v4_iter << std::endl;
	std::cout << "*v4_r_iter = "<< *v4_r_iter << std::endl;

	std::cout << "v4_iter->size() = "<< v4_iter->size() << std::endl;
	std::cout << "v4_r_iter->size() = "<< v4_r_iter->size() << std::endl;

	std::cout << "v4: ";

	for (auto item : v4) {
		std::cout << item << " ";
	}

	std::cout << std::endl;

	Vector<std::string> v5 = std::move(v4);

	std::cout << "v4: ";

	for (auto item : v4) {
		std::cout << item << " ";
	}

	std::cout << std::endl;

	std::cout << "v5: ";

	for (auto item : v5) {
		std::cout << item << " ";
	}

	std::cout << std::endl;

	v4 = std::move(v5);

	std::cout << "v4: ";

	for (auto item : v4) {
		std::cout << item << " ";
	}

	std::cout << std::endl;

	std::cout << "v5: ";

	for (auto item : v5) {
		std::cout << item << " ";
	}

	std::cout << std::endl;
}