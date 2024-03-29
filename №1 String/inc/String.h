#ifndef String_h
#define String_h

#include <iostream>
#include <cstring>
#include <algorithm>
#include <initializer_list>

class String {
public:
	String();
	String(const String& string);
	String& operator=(const String& string);
	String(String&& string);
	String& operator=(String&& string);
	~String();

	String(const char* cstring);
	String(size_t size, char ch = '_');
	String(std::initializer_list<char> l);

	String(char, size_t) = delete;

	char& operator[](size_t i);
	const char& operator[](size_t i) const;
	size_t len() const;

	friend std::ostream& operator<<(std::ostream& out, const String& string);
	friend bool operator==(const String& string_1, const String& string_2);
	friend bool operator<(const String& string_1, const String& string_2);
private:
	size_t size;
	char* str = nullptr;
};

bool operator>(const String& string_1, const String& string_2);
bool operator>=(const String& string_1, const String& string_2);
bool operator<=(const String& string_1, const String& string_2);
bool operator!=(const String& string_1, const String& string_2);

#endif