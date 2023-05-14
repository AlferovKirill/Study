#include "../Headers/Vector.hpp"

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
}
