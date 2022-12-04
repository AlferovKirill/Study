#include "../inc/string.h"

String::String() : size(1), str(new char('\0')) {}

String::String(const String& string) : String(string.str) {}

String& String::operator=(String string) {
	std::swap(size, string.size);
	std::swap(str, string.str);
	return *this;
}

String::~String() {
	delete str;
}

String::String(const char* cstring) : size(std::strlen(cstring)), str(new char[size + 1]) {
	std::strcpy(str, cstring);
}

String::String(size_t size, char ch) : size(size), str(new char[size + 1]) {
	std::memset(str, ch, size);
	str[size] = '\0';
}

String::String(std::initializer_list<char> l) : size(l.size()), str(new char[size + 1]) {
	std::copy(l.begin(), l.end(), str);
	str[size] = '\0';
}

char& String::operator[](size_t i) {
	return str[i];
}

const char& String::operator[](size_t i) const {
	return str[i];
}

size_t String::len() const {
	return size;
}

std::ostream& operator<<(std::ostream& out, const String& string) {
	out << string.str;
	return out;
}

bool operator==(const String& string_1, const String& string_2) {
	bool result = true;

	if (string_1.size != string_2.size) {
		result = false;
	}
	else {
		for (size_t i = 0; i < string_1.size; ++i) {
			if (string_1.str[i] != string_2.str[i]) {
				result = false;
			}
		}
	}

	return result;
}

bool operator!=(const String& string_1, const String& string_2) {
	return !(string_1 == string_2);
}

bool operator<(const String& string_1, const String& string_2) {
	if (string_1 == string_2) {
		return false;
	}
	else if (string_1.size < string_1.size) {
		return true;
	}
	else if (string_1.size > string_1.size) {
		return false;
	}
	else {
		for (size_t i = 0; i < string_1.size; ++i) {
			if (string_1[i] < string_2[i]) {
				return true;
			}
			else if (string_1[i] > string_2[i]) {
				return false;
			}
		}
	}
}

bool operator>(const String& string_1, const String& string_2) {
	return (string_2 < string_1);
}