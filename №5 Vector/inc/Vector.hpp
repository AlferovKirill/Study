#pragma once

#include <iostream>
#include <exception>
#include <memory>
#include <iterator>
#include <type_traits>

/*
	Notes:
	1) Create initializer_list
	2) Realise move-copy constructor n' move-operator assigment 
*/

template <typename T, typename Allocator = std::allocator<T>>
class Vector {
public:
	Vector();
	Vector(size_t sz, const T& value = T(), const Allocator& allocator = Allocator());
	Vector(const Vector<T, Allocator>& another);
	Vector<T, Allocator>& operator=(const Vector<T, Allocator>& another);
	~Vector();

	void reserve(size_t new_cap);
	void resize(size_t new_sz, const T& value = T());
	void push_back(const T& value);
	void push_back(T&& value);
	void pop_back();

	T& operator[](size_t i);
	const T& operator[](size_t i) const;
	T& at(size_t i);
	const T& at(size_t i) const;

	T& front();
	T& back();
	const T& front() const;
	const T& back() const;

	size_t size() const noexcept;
	size_t capacity() const noexcept;

	template <bool IsConst>
	class common_iterator {
	public:
		using iterator_category = std::random_access_iterator_tag;
		using value_type = std::conditional_t<IsConst, const T, T>;
		using difference_type = long long int;
		using pointer = std::conditional_t<IsConst, const T*, T*>;
		using reference = std::conditional_t<IsConst, const T&, T&>;

		common_iterator(std::conditional_t<IsConst, const T*, T*> ptr) : ptr(ptr) {}
		std::conditional_t<IsConst, const T*, T*> operator->() const {
			return ptr;
		}
		std::conditional_t<IsConst, const T&, T&> operator*() const {
			return *ptr;
		}
		std::conditional_t<IsConst, const T&, T&> operator[](size_t i) const {
			return *(ptr + i);
		}
		common_iterator<IsConst> operator++() {
			++ptr;
			return *this;
		}
		common_iterator<IsConst> operator++(int) {
			common_iterator<IsConst> temp(ptr);
			++ptr;

			return temp;
		}
		common_iterator<IsConst> operator--() {
			--ptr;
			return *this;
		}
		common_iterator<IsConst> operator--(int) {
			common_iterator<IsConst> temp(ptr);
			--ptr;

			return temp;
		}
		common_iterator<IsConst> operator+=(long long int n) {
			ptr += n;
			return *this;
		}
		common_iterator<IsConst> operator-=(long long int n) {
			ptr -= n;
			return *this;
		}
		long long int operator-(const common_iterator<IsConst>& another) const {
			return ptr - another.ptr;
		}
		common_iterator<IsConst> operator+(long long int n) const {
			return common_iterator<IsConst>(ptr + n);
		}
		common_iterator<IsConst> operator-(long long int n) const {
			return common_iterator<IsConst>(ptr - n);
		}
		bool operator==(const common_iterator<IsConst>& another) const {
			return ptr == another.ptr;
		}
		bool operator!=(const common_iterator<IsConst>& another) const {
			return ptr != another.ptr;
		}
		bool operator<(const common_iterator<IsConst>& another) const {
			return (another - *this > 0);
		}
		bool operator>(const common_iterator<IsConst>& another) const {
			return another < *this;
		}
		bool operator<=(const common_iterator<IsConst>& another) const {
			return !(*this > another);
		}
		bool operator>=(const common_iterator<IsConst>& another) const {
			return !(*this < another);
		}
	private:
		std::conditional_t<IsConst, const T*, T*> ptr;
	};

	template <typename Iterator>
	class common_reverse_iterator {
	public:
		using iterator_category = std::random_access_iterator_tag;
		using value_type = typename std::iterator_traits<Iterator>::value_type;
		using difference_type = long long int;
		using pointer = typename std::iterator_traits<Iterator>::pointer;
		using reference = typename std::iterator_traits<Iterator>::reference;

		common_reverse_iterator(const Iterator& iterator) : iterator(iterator) {}
		typename std::iterator_traits<Iterator>::pointer operator->() {
			return &(*iterator);
		}
		typename std::iterator_traits<Iterator>::value_type operator*() {
			return *iterator;
		}
		Iterator base() const {
			return iterator;
		}
		common_reverse_iterator<Iterator> operator++() {
			--iterator;
			return *this;
		}
		common_reverse_iterator<Iterator> operator++(int) {
			common_reverse_iterator<Iterator> temp(iterator);
			--iterator;

			return temp;
		}
		common_reverse_iterator<Iterator> operator--() {
			++iterator;
			return *this;
		}
		common_reverse_iterator<Iterator> operator--(int) {
			common_reverse_iterator<Iterator> temp(iterator);
			++iterator;

			return temp;
		}
		common_reverse_iterator<Iterator> operator+=(long long int n) {
			iterator -= n;
			return *this;
		}
		common_reverse_iterator<Iterator> operator-=(long long int n) {
			iterator += n;
			return *this;
		}
		long long int operator-(const common_reverse_iterator<Iterator>& another) const {
			return another.base() - iterator;
		}
		common_reverse_iterator<Iterator> operator+(long long int n) const {
			return common_reverse_iterator<Iterator>(iterator - n);
		}
		common_reverse_iterator<Iterator> operator-(long long int n) const {
			return common_reverse_iterator<Iterator>(iterator + n);
		}
		bool operator==(const common_reverse_iterator<Iterator>& another) const {
			return iterator == another.base();
		}
		bool operator!=(const common_reverse_iterator<Iterator>& another) const {
			return iterator != another.base();
		}
		bool operator<(const common_reverse_iterator<Iterator>& another) const {
			return iterator > another.base();
		}
		bool operator>(const common_reverse_iterator<Iterator>& another) const {
			return iterator < another.base();
		}
		bool operator<=(const common_reverse_iterator<Iterator>& another) const {
			return iterator >= another.base();
		}
		bool operator>=(const common_reverse_iterator<Iterator>& another) const {
			return iterator <= another.base();
		}
	private:
		Iterator iterator;
	};

	using iterator = common_iterator<false>;
	using const_iterator = common_iterator<true>;

	using reverse_iterator = common_reverse_iterator<iterator>;
	using const_reverse_iterator = common_reverse_iterator<const_iterator>;

	iterator begin();
	iterator end();
	const_iterator cbegin() const;
	const_iterator cend() const;

	reverse_iterator rbegin();
	reverse_iterator rend();
	const_reverse_iterator crbegin() const;
	const_reverse_iterator crend() const;
private:
	size_t sz;
	size_t cap;

	T* arr;
	Allocator allocator;

	using AllocatorTraits = std::allocator_traits<Allocator>;
};

//			Implementation

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector() : sz(0), cap(0), arr(nullptr), allocator(Allocator()) {}

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector(size_t sz, const T& value, const Allocator& allocator) : sz(0), cap(0), arr(nullptr), allocator(allocator) {
	resize(sz, value);
}

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector(const Vector<T, Allocator>& another) : sz(0), cap(0), arr(nullptr) {
	allocator = AllocatorTraits::select_on_container_copy_construction(another.allocator);

	reserve(another.cap);
		
	for (size_t i = 0; i < another.sz; ++i) {
		AllocatorTraits::construct(allocator, arr + i, another[i]);
	}

	sz = another.sz;
}

template <typename T, typename Allocator>
Vector<T, Allocator>& Vector<T, Allocator>::operator=(const Vector<T, Allocator>& another) {
	if (this == &another) return *this;

	for (size_t i = 0; i < sz; ++i) {
		AllocatorTraits::destroy(allocator, arr + i);
	}

	AllocatorTraits::deallocate(allocator, arr, cap);

	sz = another.sz;
	cap = another.cap;

	if (AllocatorTraits::propagate_on_container_copy_assignment::value && allocator != another.allocator) {
		allocator = another.allocator;
	}
		
	arr = AllocatorTraits::allocate(allocator, cap);

	for (size_t i = 0; i < sz; ++i) {
		AllocatorTraits::construct(allocator, arr + i, another[i]);
	}

	return *this;
}

template <typename T, typename Allocator>
Vector<T, Allocator>::~Vector() {
	for (size_t i = 0; i < sz; ++i) {
		AllocatorTraits::destroy(allocator, arr + i);
	}

	AllocatorTraits::deallocate(allocator, arr, cap);
}

template <typename T, typename Allocator>
void Vector<T, Allocator>::reserve(size_t new_cap) {
	if (new_cap <= cap) return;

	T* new_arr = AllocatorTraits::allocate(allocator, new_cap);

	size_t i = 0;

	try {
		for (; i < sz; ++i) {
			AllocatorTraits::construct(allocator, new_arr + i, std::move(arr[i]));
		}
	}
	catch (...) {
		for (size_t j = 0; j < i; ++j) {
			AllocatorTraits::destroy(allocator, new_arr + j);
		}

		AllocatorTraits::deallocate(allocator, new_arr, new_cap);

		throw;
	}

	for (size_t i = 0; i < sz; ++i) {
		AllocatorTraits::destroy(allocator, arr + i);
	}

	AllocatorTraits::deallocate(allocator, arr, cap);

	arr = new_arr;
	cap = new_cap;
}

template <typename T, typename Allocator>
void Vector<T, Allocator>::resize(size_t new_sz, const T& value) {
	if (cap < new_sz) reserve(new_sz);

	for (size_t i = sz; i < new_sz; ++i) {
		AllocatorTraits::construct(allocator, arr + i, value);
	}

	sz = new_sz;
}

template <typename T, typename Allocator>
void Vector<T, Allocator>::push_back(const T& value) {
	if (cap == 0) reserve(1);
	else if (sz == cap) reserve(2 * cap);

	AllocatorTraits::construct(allocator, arr + sz, value);
	++sz;
}

template <typename T, typename Allocator>
void Vector<T, Allocator>::push_back(T&& value) {
	if (cap == 0) reserve(1);
	else if (sz == cap) reserve(2 * cap);

	AllocatorTraits::construct(allocator, arr + sz, std::move(value));
	++sz;
}

template <typename T, typename Allocator>
void Vector<T, Allocator>::pop_back() {
	AllocatorTraits::destroy(allocator, arr + sz - 1);
	--sz;
}

template <typename T, typename Allocator>
T& Vector<T, Allocator>::operator[](size_t i) {
	return arr[i];
}

template <typename T, typename Allocator>
const T& Vector<T, Allocator>::operator[](size_t i) const {
	return arr[i];
}

template <typename T, typename Allocator>
T& Vector<T, Allocator>::at(size_t i) {
	if (i >= sz) throw std::out_of_range("Index out of range!");

	return arr[i];
}

template <typename T, typename Allocator>
const T& Vector<T, Allocator>::at(size_t i) const {
	if (i >= sz) throw std::out_of_range("Index out of range!");

	return arr[i];
}

template <typename T, typename Allocator>
T& Vector<T, Allocator>::front() {
	return arr[0];
}

template <typename T, typename Allocator>
T& Vector<T, Allocator>::back() {
	return arr[sz - 1];
}

template <typename T, typename Allocator>
const T& Vector<T, Allocator>::front() const {
	return arr[0];
}

template <typename T, typename Allocator>
const T& Vector<T, Allocator>::back() const {
	return arr[sz - 1];
}

template <typename T, typename Allocator>
size_t Vector<T, Allocator>::size() const noexcept {
	return sz;
}

template <typename T, typename Allocator>
size_t Vector<T, Allocator>::capacity() const noexcept {
	return cap;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator Vector<T, Allocator>::begin() {
	return Vector<T, Allocator>::iterator(arr);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator Vector<T, Allocator>::end() {
	return Vector<T, Allocator>::iterator(arr + sz);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_iterator Vector<T, Allocator>::cbegin() const {
	return Vector<T, Allocator>::const_iterator(arr);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_iterator Vector<T, Allocator>::cend() const {
	return Vector<T, Allocator>::const_iterator(arr + sz);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::reverse_iterator Vector<T, Allocator>::rbegin() {
	return Vector<T, Allocator>::reverse_iterator(end() - 1);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::reverse_iterator Vector<T, Allocator>::rend() {
	return Vector<T, Allocator>::reverse_iterator(begin() - 1);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_reverse_iterator Vector<T, Allocator>::crbegin() const {
	return Vector<T, Allocator>::const_reverse_iterator(cend() - 1);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_reverse_iterator Vector<T, Allocator>::crend() const {
	return Vector<T, Allocator>::const_reverse_iterator(cbegin() - 1);
}