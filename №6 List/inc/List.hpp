#pragma once

#include <iostream>
#include <exception>
#include <memory>
#include <iterator>
#include <type_traits>
#include <initializer_list>

/*
	1) Реализовать конструкторы
	2) Сделать оболочку try-catch для конструкторов
	3) Сверить сигнатуры методов с cppreference
*/

template <typename T, typename Allocator = std::allocator<T>>
class List {
public:
	List();
	List(size_t sz, const T& value = T(), const Allocator& allocator = Allocator());
	List(const std::initializer_list<T>& lst);
	List(const List<T, Allocator>& another);
	//List(List<T, Allocator>&& another) noexcept;
	//List<T, Allocator>& operator=(const List<T, Allocator>& another) &;
	//List<T, Allocator>& operator=(List<T, Allocator>&& another) & noexcept;
	~List();

	void resize(size_t new_sz, const T& value = T());

	void push_back(const T& value);
	void push_back(T&& value);
	void pop_back();

	void push_front(const T& value);
	void push_front(T&& value);
	void pop_front();

	size_t size() const noexcept;

	T& front();
	T& back();
	const T& front() const;
	const T& back() const;

	template<bool IsConst>
	struct common_iterator;

	template<typename Iterator>
	struct common_reverse_iterator;

	using iterator = common_iterator<false>;
	using const_iterator = common_iterator<true>;

	using reverse_iterator = common_reverse_iterator<iterator>;
	using const_reverse_iterator = common_reverse_iterator<const_iterator>;

	iterator begin() noexcept;
	iterator end() noexcept;
	const_iterator begin() const noexcept;
	const_iterator end() const noexcept;
	const_iterator cbegin() const noexcept;
	const_iterator cend() const noexcept;

	reverse_iterator rbegin() noexcept;
	reverse_iterator rend() noexcept;
	const_reverse_iterator rbegin() const noexcept;
	const_reverse_iterator rend() const noexcept;
	const_reverse_iterator crbegin() const noexcept;
	const_reverse_iterator crend() const noexcept;
private:
	struct Node;

	using AllocatorTraits = typename std::allocator_traits<Allocator>::rebind_traits<Node>;
	using AllocatorNode = typename std::allocator_traits<Allocator>::rebind_alloc<Node>;
	
	Node* head;
	Node* tail;

	Node* fake_begin;
	Node* fake_end;

	size_t sz;
	AllocatorNode allocator;
};

//			Implementation of Node

template <typename T, typename Allocator>
struct List<T, Allocator>::Node {
	T value;

	Node* prev;
	Node* next;

	Node(const T& value, Node* prev = nullptr, Node* next = nullptr) : value(value), prev(prev), next(next) {}
	Node(T&& value, Node* prev = nullptr, Node* next = nullptr) : value(std::move_if_noexcept(value)), prev(prev), next(next) {}
};

//			Implementation of iterators

template <typename T, typename Allocator>
template<bool IsConst>
struct List<T, Allocator>::common_iterator {
public:
	using iterator_category = std::bidirectional_iterator_tag;
	using value_type = std::conditional_t<IsConst, const T, T>;
	using pointer = value_type*;
	using reference = value_type&;

	common_iterator(std::conditional_t<IsConst, const Node*, Node*> node) : node(node) {}
	pointer operator->() const {
		return &(node->value);
	}
	reference operator*() const {
		return node->value;
	}
	common_iterator<IsConst>& operator++() {
		node = node->next;
		return *this;
	}
	common_iterator<IsConst> operator++(int) {
		common_iterator<IsConst> temp(node);
		node = node->next;

		return temp;
	}
	common_iterator<IsConst>& operator--() {
		node = node->prev;
		return *this;
	}
	common_iterator<IsConst> operator--(int) {
		common_iterator<IsConst> temp(node);
		node = node->prev;

		return temp;
	}
	bool operator==(const common_iterator<IsConst>& another) const {
		return node == another.node;
	}
	bool operator!=(const common_iterator<IsConst>& another) const {
		return node != another.node;
	}
private:
	std::conditional_t<IsConst, const Node*, Node*> node;
};

template<typename T, typename Allocator>
template<typename Iterator>
struct List<T, Allocator>::common_reverse_iterator {
public:
	using iterator_category = std::bidirectional_iterator_tag;
	using value_type = typename Iterator::value_type;
	using pointer = value_type*;
	using reference = value_type&;

	common_reverse_iterator(const Iterator& iterator) : iterator(iterator) {}
	reference operator*() {
		return *iterator;
	}
	pointer operator->() {
		return &(*iterator);
	}
	common_reverse_iterator<Iterator>& operator++() {
		--iterator;
		return *this;
	}
	common_reverse_iterator<Iterator> operator++(int) {
		common_reverse_iterator<Iterator> temp(iterator);
		--iterator;

		return temp;
	}
	common_reverse_iterator<Iterator>& operator--() {
		++iterator;
		return *this;
	}
	common_reverse_iterator<Iterator> operator--(int) {
		common_reverse_iterator<Iterator> temp(iterator);
		++iterator;
		
		return temp;
	}
	bool operator==(const common_reverse_iterator<Iterator>& another) const {
		return iterator == another.iterator;
	}
	bool operator!=(const common_reverse_iterator<Iterator>& another) const {
		return iterator != another.iterator;
	}
private:
	Iterator iterator;
};

//			Implementation of methods

template <typename T, typename Allocator>
List<T, Allocator>::List() : sz(0), head(nullptr), tail(nullptr), fake_begin(nullptr), fake_end(nullptr), allocator(AllocatorNode()) {}

template <typename T, typename Allocator>
List<T, Allocator>::List(size_t sz, const T& value, const Allocator& allocator) : sz(0), head(nullptr), tail(nullptr), fake_begin(nullptr), fake_end(nullptr), allocator(allocator) {
	resize(sz, value);
}

template <typename T, typename Allocator>
List<T, Allocator>::List(const std::initializer_list<T>& lst) : List() {
	for (const T& item : lst) {
		push_back(item);
	}
}

template <typename T, typename Allocator>
List<T, Allocator>::List(const List<T, Allocator>& another) : List() {
	for (const T& item : another) {
		push_back(item);
	}
}

template <typename T, typename Allocator>
List<T, Allocator>::~List() {
	while (head != nullptr) {
		pop_back();
	}
}

template <typename T, typename Allocator>
void List<T, Allocator>::resize(size_t new_sz, const T& value) {
	if (new_sz == sz) return;

	if (new_sz > sz) {
		while (new_sz != sz) {
			push_back(value);
		}
	}
	else if (new_sz < sz) {
		while (new_sz != sz) {
			pop_back();
		}
	}
}

template <typename T, typename Allocator>
void List<T, Allocator>::push_back(const T& value) {
	if (head == nullptr) {
		head = AllocatorTraits::allocate(allocator, 1);
		fake_begin = AllocatorTraits::allocate(allocator, 1);
		fake_end = AllocatorTraits::allocate(allocator, 1);

		AllocatorTraits::construct(allocator, head, Node(value, fake_begin, fake_end));

		++sz;
	}
	else if (tail == nullptr) {
		tail = AllocatorTraits::allocate(allocator, 1);
		AllocatorTraits::construct(allocator, tail, Node(value, head, fake_end));
			
		head->next = tail;

		++sz;
	}
	else {
		AllocatorTraits::construct(allocator, fake_end, Node(value, tail, nullptr));
		tail = fake_end;

		fake_end = AllocatorTraits::allocate(allocator, 1);
		tail->next = fake_end;
		++sz;
	}
}

template <typename T, typename Allocator>
void List<T, Allocator>::push_back(T&& value) {
	if (head == nullptr) {
		head = AllocatorTraits::allocate(allocator, 1);
		fake_begin = AllocatorTraits::allocate(allocator, 1);
		fake_end = AllocatorTraits::allocate(allocator, 1);

		AllocatorTraits::construct(allocator, head, Node(std::move_if_noexcept(value), fake_begin, fake_end));

		++sz;
	}
	else if (tail == nullptr) {
		tail = AllocatorTraits::allocate(allocator, 1);
		AllocatorTraits::construct(allocator, tail, Node(std::move_if_noexcept(value), head, fake_end));
			
		head->next = tail;

		++sz;
	}
	else {
		AllocatorTraits::construct(allocator, fake_end, Node(std::move_if_noexcept(value), tail, nullptr));
		tail = fake_end;

		fake_end = AllocatorTraits::allocate(allocator, 1);
		tail->next = fake_end;
		++sz;
	}
}

template <typename T, typename Allocator>
void List<T, Allocator>::pop_back() {
	if (tail != nullptr) {
		Node* temp = tail;
		
		tail = tail->prev;
		tail->next = fake_end;

		AllocatorTraits::destroy(allocator, temp);
		AllocatorTraits::deallocate(allocator, temp, 1);

		if (head == tail) tail = nullptr;
	}
	else {
		AllocatorTraits::destroy(allocator, head);
		AllocatorTraits::deallocate(allocator, head, 1);
		AllocatorTraits::deallocate(allocator, fake_begin, 1);
		AllocatorTraits::deallocate(allocator, fake_end, 1);

		head = nullptr;
		fake_begin = nullptr;
		fake_end = nullptr;
	}

	--sz;
}

template <typename T, typename Allocator>
void List<T, Allocator>::push_front(const T& value) {
	if (head == nullptr) {
		head = AllocatorTraits::allocate(allocator, 1);
		fake_begin = AllocatorTraits::allocate(allocator, 1);
		fake_end = AllocatorTraits::allocate(allocator, 1);

		AllocatorTraits::construct(allocator, head, Node(value, fake_begin, fake_end));

		++sz;
	}
	else if (tail == nullptr) {
		tail = head;

		head = AllocatorTraits::allocate(allocator, 1);
		AllocatorTraits::construct(allocator, head, Node(value, fake_begin, tail));
			
		tail->prev = head;

		++sz;
	}
	else {
		AllocatorTraits::construct(allocator, fake_begin, Node(value, nullptr, head));
		head = fake_begin;

		fake_begin = AllocatorTraits::allocate(allocator, 1);
		head->prev = fake_begin;
		++sz;
	}
}

template <typename T, typename Allocator>
void List<T, Allocator>::push_front(T&& value) {
	if (head == nullptr) {
		head = AllocatorTraits::allocate(allocator, 1);
		fake_begin = AllocatorTraits::allocate(allocator, 1);
		fake_end = AllocatorTraits::allocate(allocator, 1);

		AllocatorTraits::construct(allocator, head, Node(std::move_if_noexcept(value), fake_begin, fake_end));

		++sz;
	}
	else if (tail == nullptr) {
		tail = head;

		head = AllocatorTraits::allocate(allocator, 1);
		AllocatorTraits::construct(allocator, head, Node(std::move_if_noexcept(value), fake_begin, tail));
			
		tail->prev = head;

		++sz;
	}
	else {
		AllocatorTraits::construct(allocator, fake_begin, Node(std::move_if_noexcept(value), nullptr, head));
		head = fake_begin;

		fake_begin = AllocatorTraits::allocate(allocator, 1);
		head->prev = fake_begin;
		++sz;
	}
}

template <typename T, typename Allocator>
void List<T, Allocator>::pop_front() {
	if (head != nullptr) {
		Node* temp = head;
		
		head = head->next;
		head->prev = fake_begin;

		AllocatorTraits::destroy(allocator, temp);
		AllocatorTraits::deallocate(allocator, temp, 1);

		if (head == tail) tail = nullptr;
	}
	else {
		AllocatorTraits::destroy(allocator, head);
		AllocatorTraits::deallocate(allocator, head, 1);
		AllocatorTraits::deallocate(allocator, fake_begin, 1);
		AllocatorTraits::deallocate(allocator, fake_end, 1);

		head = nullptr;
		fake_begin = nullptr;
		fake_end = nullptr;
	}

	--sz;
}

template <typename T, typename Allocator>
size_t List<T, Allocator>::size() const noexcept {
	return sz;
}

template <typename T, typename Allocator>
T& List<T, Allocator>::front() {
	return head->value;
}

template <typename T, typename Allocator>
T& List<T, Allocator>::back() {
	return (tail != nullptr) ? (tail->value) : (head->value);
}

template <typename T, typename Allocator>
const T& List<T, Allocator>::front() const {
	return head->value;
}

template <typename T, typename Allocator>
const T& List<T, Allocator>::back() const {
	return (tail != nullptr) ? (tail->value) : (head->value);
}

template <typename T, typename Allocator>
typename List<T, Allocator>::iterator List<T, Allocator>::begin() noexcept {
	return List<T, Allocator>::iterator(head);
}

template <typename T, typename Allocator>
typename List<T, Allocator>::iterator List<T, Allocator>::end() noexcept {
	return List<T, Allocator>::iterator(fake_end);
}

template <typename T, typename Allocator>
typename List<T, Allocator>::const_iterator List<T, Allocator>::begin() const noexcept {
	return List<T, Allocator>::const_iterator(head);
}

template <typename T, typename Allocator>
typename List<T, Allocator>::const_iterator List<T, Allocator>::end() const noexcept {
	return List<T, Allocator>::const_iterator(fake_end);
}

template <typename T, typename Allocator>
typename List<T, Allocator>::const_iterator List<T, Allocator>::cbegin() const noexcept {
	return List<T, Allocator>::const_iterator(head);
}

template <typename T, typename Allocator>
typename List<T, Allocator>::const_iterator List<T, Allocator>::cend() const noexcept {
	return List<T, Allocator>::const_iterator(fake_end);
}

template <typename T, typename Allocator>
typename List<T, Allocator>::reverse_iterator List<T, Allocator>::rbegin() noexcept {
	return List<T, Allocator>::reverse_iterator((tail == nullptr) ? (head) : (tail));
}

template <typename T, typename Allocator>
typename List<T, Allocator>::reverse_iterator List<T, Allocator>::rend() noexcept {
	return List<T, Allocator>::reverse_iterator(List<T, Allocator>::iterator(fake_begin));
}

template <typename T, typename Allocator>
typename List<T, Allocator>::const_reverse_iterator List<T, Allocator>::rbegin() const noexcept {
	return List<T, Allocator>::const_reverse_iterator(List<T, Allocator>::const_iterator((tail == nullptr) ? (head) : (tail)));
}

template <typename T, typename Allocator>
typename List<T, Allocator>::const_reverse_iterator List<T, Allocator>::rend() const noexcept {
	return List<T, Allocator>::const_reverse_iterator(List<T, Allocator>::const_iterator(fake_begin));
}

template <typename T, typename Allocator>
typename List<T, Allocator>::const_reverse_iterator List<T, Allocator>::crbegin() const noexcept {
	return List<T, Allocator>::const_reverse_iterator(List<T, Allocator>::const_iterator((tail == nullptr) ? (head) : (tail)));
}

template <typename T, typename Allocator>
typename List<T, Allocator>::const_reverse_iterator List<T, Allocator>::crend() const noexcept {
	return List<T, Allocator>::const_reverse_iterator(List<T, Allocator>::const_iterator(fake_begin));
}