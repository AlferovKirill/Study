#pragma once

#include <iostream>
#include <exception>
#include <memory>
#include <iterator>

template <typename T, typename Allocator = std::allocator<T>>
class Vector {
public:
	Vector() : sz(0), cap(0), arr(nullptr), allocator(Allocator()) {}
	Vector(size_t sz, const T& value = T(), const Allocator& allocator = Allocator()) : sz(0), cap(0), arr(nullptr), allocator(allocator) {
		resize(sz, value);
	}
	Vector(const Vector<T, Allocator>& another) : sz(0), cap(0), arr(nullptr) {
		allocator = AllocatorTraits::select_on_container_copy_construction(another.allocator);

		reserve(another.cap);
		
		for (size_t i = 0; i < another.sz; ++i) {
			AllocatorTraits::construct(allocator, arr + i, another[i]);
		}

		sz = another.sz;
	}
	Vector<T, Allocator>& operator=(const Vector<T, Allocator>& another) {
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
	~Vector() {
		for (size_t i = 0; i < sz; ++i) {
			AllocatorTraits::destroy(allocator, arr + i);
		}

		AllocatorTraits::deallocate(allocator, arr, cap);
	}
	void reserve(size_t new_cap) {
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
	void resize(size_t new_sz, const T& value = T()) {
		if (cap < new_sz) reserve(new_sz);

		for (size_t i = sz; i < new_sz; ++i) {
			AllocatorTraits::construct(allocator, arr + i, value);
		}

		sz = new_sz;
	}
	void push_back(const T& value) {
		if (sz == cap) reserve(2 * cap);

		AllocatorTraits::construct(allocator, arr + sz, value);
		++sz;
	}
	void push_back(T&& value) {
		if (sz == cap) reserve(2 * cap);

		AllocatorTraits::construct(allocator, arr + sz, std::move(value));
		++sz;
	}
	void pop_back() {
		AllocatorTraits::destroy(allocator, arr + sz - 1);
		--sz;
	}
	T& operator[](size_t i) {
		return arr[i];
	}
	const T& operator[](size_t i) const {
		return arr[i];
	}
	T& at(size_t i) {
		if (i >= sz) throw std::out_of_range("Index out of range!");
		return arr[i];
	}
	const T& at(size_t i) const {
		if (i >= sz) throw std::out_of_range("Index out of range!");
		return arr[i];
	}
	T& front() {
		return arr[0];
	}
	T& back() {
		return arr[sz - 1];
	}
	const T& front() const {
		return arr[0];
	}
	const T& back() const {
		return arr[sz - 1];
	}
	size_t size() const noexcept {
		return sz;
	}
	size_t capacity() const noexcept {
		return cap;
	}

	// Убрать conditional, заменить на traits
	template <bool IsConst, typename True, typename False>
	struct conditional {
		using type = True;
	};
	template <typename True, typename False>
	struct conditional<false, True, False> {
		using type = False;
	};
	template <bool IsConst, typename True, typename False>
	using conditional_t = typename conditional<IsConst, True, False>::type;

	template <bool IsConst>
	class common_iterator {
	public:
		common_iterator(conditional_t<IsConst, const T*, T*> ptr) : ptr(ptr) {}
		conditional_t<IsConst, const T*, T*> operator->() const {
			return ptr;
		}
		conditional_t<IsConst, const T&, T&> operator*() const {
			return *ptr;
		}
		conditional_t<IsConst, const T&, T&> operator[](size_t i) const {
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

		using iterator_category = std::random_access_iterator_tag;
		using value_type = conditional_t<IsConst, const T, T>;
		using difference_type = long long int;
		using pointer = conditional_t<IsConst, const T*, T*>;
		using reference = conditional_t<IsConst, const T&, T&>;

		template <typename Iterator>
		friend class common_reverse_iterator;
	private:
		conditional_t<IsConst, const T*, T*> ptr;
	};

	template <typename Iterator>
	class common_reverse_iterator {
	public:
		common_reverse_iterator(const Iterator& iterator) : iterator(iterator) {}
		typename std::iterator_traits<Iterator>::pointer operator->() {
			return iterator.ptr;
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

	iterator begin() {
		return iterator(arr);
	}
	iterator end() {
		return iterator(arr + sz);
	}
	const_iterator cbegin() const {
		return const_iterator(arr);
	}
	const_iterator cend() const {
		return const_iterator(arr + sz);
	}

	reverse_iterator rbegin() {
		return reverse_iterator(end() - 1);
	}
	reverse_iterator rend() {
		return reverse_iterator(begin() - 1);
	}
	const_reverse_iterator crbegin() const {
		return const_reverse_iterator(cend() - 1);
	}
	const_reverse_iterator crend() const {
		return const_reverse_iterator(cbegin() - 1);
	}
private:
	size_t sz;
	size_t cap;

	T* arr;
	Allocator allocator;

	using AllocatorTraits = std::allocator_traits<Allocator>;
};