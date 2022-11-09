#ifndef string_h
#define string_h
#include <iostream>
#include <cstring>
#include <algorithm>
#include <initializer_list>

class String {
public:
	String();
	String(const String& string);
	String(const char* cstring);
	String(size_t size, char ch = '_');
	String(std::initializer_list<char> l);
	String& operator=(String string);
	char& operator[](size_t i);
	const char& operator[](size_t i) const;
	size_t len() const;
	~String();

	friend std::ostream& operator<<(std::ostream& out, const String& string);
	friend bool operator==(const String& string_1, const String& string_2);
	friend bool operator!=(const String& string_1, const String& string_2);
	friend bool operator<(const String& string_1, const String& string_2);
	friend bool operator>(const String& string_1, const String& string_2);

	String(char, size_t) = delete;
private:
	size_t size;
	char* str = nullptr;

	void swap(String& string);
};

#endif