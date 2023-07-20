#include "../inc/List.hpp"
#include <string>
#include <iostream>

int main() {
	List<int> lst;

	lst.push_back(9);
	lst.push_back(8);
	lst.push_back(7);

	List<char> lst2(2, '3');

	std::cout << "lst front() = " << lst.front() << "\n";
	std::cout << "lst back() = " << lst.back() << "\n";

	std::cout << "lst2 front() = " << lst2.front() << "\n";
	std::cout << "lst2 back() = " << lst2.back() << "\n";

	std::cout << "lst size() = " << lst.size() << "\n";
	std::cout << "lst2 size() = " << lst2.size() << "\n\n";

	lst.resize(2);
	lst2.resize(10, '-');

	std::cout << "lst front() = " << lst.front() << "\n";
	std::cout << "lst back() = " << lst.back() << "\n";

	std::cout << "lst2 front() = " << lst2.front() << "\n";
	std::cout << "lst2 back() = " << lst2.back() << "\n";

	std::cout << "lst size() = " << lst.size() << "\n";
	std::cout << "lst2 size() = " << lst2.size() << "\n\n";

	lst.resize(20);
	lst2.resize(1);

	std::cout << "lst front() = " << lst.front() << "\n";
	std::cout << "lst back() = " << lst.back() << "\n";

	std::cout << "lst2 front() = " << lst2.front() << "\n";
	std::cout << "lst2 back() = " << lst2.back() << "\n";

	std::cout << "lst size() = " << lst.size() << "\n";
	std::cout << "lst2 size() = " << lst2.size() << "\n\n";

	std::cout << "lst: ";

	for (auto item : lst) {
		std::cout << item << " ";
	}

	std::cout << std::endl;

	std::cout << "lst2: ";

	for (auto item : lst2) {
		std::cout << item << " ";
	}

	std::cout << std::endl;

	List<int> lst3;

	lst3.push_front(1);
	lst3.push_front(2);
	lst3.push_front(3);
	lst3.push_front(4);

	std::cout << "lst3: ";

	for (auto item : lst3) {
		std::cout << item << " ";
	}

	std::cout << std::endl;

	std::cout << "reverse lst3: ";

	for (auto iter = lst3.rbegin(); iter != lst3.rend(); ++iter) {
		std::cout << *iter << " ";
	}

	std::cout << std::endl;

	lst3.push_back(10);
	lst3.push_front(22);

	std::cout << "lst3: ";

	for (auto item : lst3) {
		std::cout << item << " ";
	}

	std::cout << std::endl;

	std::cout << "reverse lst3: ";

	for (auto iter = lst3.rbegin(); iter != lst3.rend(); ++iter) {
		std::cout << *iter << " ";
	}

	std::cout << std::endl << std::endl << std::endl;

	std::string ss = "321";

	List<int> lst_init_list = { 1, 2, 3, 4, 1, 2 };

	std::cout << "lst_init_list: ";

	for (auto item : lst_init_list) {
		std::cout << item << " ";
	}

	std::cout << std::endl;

	const List<int> lst_init_list_copy(lst_init_list);

	std::cout << "lst_init_list_copy: ";

	for (const int& item : lst_init_list_copy) {
		std::cout << item << " ";
	}

	std::cout << std::endl;

	std::cout << "lst_init_list_copy reverse: ";

	for (auto iter = lst_init_list_copy.rbegin(); iter != lst_init_list_copy.rend(); ++iter) {
		std::cout << *iter << " ";
	}

	std::cout << std::endl;

	{
		List<int> g = { 1, 2, 3 };	
	}

	std::cout << "end!" << std::endl;

	{
		std::cout << "Check list constructor by default" << std::endl;

		List<int> g = List<int>(3, 1);

		for (const int& item : g) {
			std::cout << item << " ";
		}
	}
}