#pragma once
#include<iostream>
using namespace std;
template<class T>
class Vector {
	size_t m_size;
	size_t m_capacity;
	T* m_data;
public:
	typedef T* Iterator;
	Vector();
	Vector(size_t n, const T& val);
	Vector(size_t n);
	Vector(const Vector<T>& x);
	~Vector();
	size_t size();
	size_t capacity();
	bool empty();
	void clear();
	void resize(size_t n, const T& val);
	void resize(size_t n);
	void reserve(size_t n);
	void push_back(const T& x);
	void pop_back();
	Iterator begin() {
		return m_data;
	}
	Iterator end() {
		return m_data + m_size;
	}
	Iterator erase(Iterator position) {
		for (Iterator i = position; i + 1 < m_data + m_size; ++i) {
			*i = *(i + 1);
		}
		--m_size;
		return position;
	}
	Iterator erase(Iterator first, Iterator last) {
		int m = last - first;
		for (Iterator i = first; i + m < m_data + m_size; ++i) {
			*i = *(i + m);
		}
		m_size -= m;
		return first;
	}
	Iterator insert(Iterator position, const T& val) {
		reserve(++m_size);
		for (Iterator i = end(); i > position; --i) {
			*i = *(i - 1);
		}
		*position = val;
		return position;
	}
	Iterator insert(Iterator position, const size_t n, const T& val) {
		m_size += n;
		reserve(m_size);
		for (Iterator i = end(); i > position + n; --i) {
			*i = *(i - n);
		}
		for (Iterator i = position; i < position + n; ++i) {
			*i = val;
		}
		return position;
	}

	template <class InputIterator>
	Iterator insert(Iterator position, InputIterator first, InputIterator last) {
		int tmp = position - begin();
		int n = last - first;
		if (n <= 0) {
			return position;
		}
		m_size += n;
		reserve(m_size);
		position = m_data + tmp;
		Iterator mend = end();
		for (Iterator i = position + n; i < mend; ++i) {
			*i = *(i - n);
		}
		for (Iterator i = position; i < position + n; ++i, ++first) {
			*i = *first;
		}
		return position;
	}
	Iterator insert(Iterator position, T&& val) {
		reserve(++m_size);
		for (Iterator i = end(); i > position; --i) {
			*i = *(i - 1);
		}
		*position = val;
		return position;
	}
	//Iterator insert(Iterator position, initializer_list<T> il) {
	//	int n = il.end() - il.begin();
	//	if (n <= 0) {
	//		return position;
	//	}
	//	m_size += n;
	//	reserve(m_size);
	//	for (Iterator i = end(); i > position + n; --i) {
	//		*i = *(i - n);
	//	}
	//	for (Iterator i = position, j = il.begin(); i < position + n; ++i, ++j) {
	//		*i = *j;
	//	}
	//	return position;
	//}
	T& operator[](const size_t n);
	T& operator[](const size_t n) const;
};
template <class T>
Vector<T>::Vector():m_size(0),
m_capacity(0),
m_data(new T[0])
{
}
template <class T>
Vector<T>::Vector(size_t n, const T& val) :m_size(n),
m_capacity(n),
m_data(new T[n])
{
	for (size_t i = 0; i < m_size; m_data[i] = val, ++i);
}
template <class T>
Vector<T>::Vector(size_t n) :m_size(0),
		m_capacity(n),
		m_data(new T[n])
	{
		for (size_t i = 0; i < m_capacity; m_data[i] = 0, ++i);
	}
template <class T>
Vector<T>::Vector(const Vector<T>& x) :m_size(x.m_size),
m_capacity(x.m_capacity),
m_data(new T[x.m_capacity])
{
	memcpy(m_data, x.m_data, m_capacity * sizeof(T));
}
template <class T>
Vector<T>::~Vector() {
	if (m_data) {
		delete[]m_data;
	}
	m_capacity = m_size = 0;
}
template <class T>
void Vector<T>::push_back(const T& x) {
	++m_size;
	reserve(m_size);
	memcpy(m_data + m_size - 1, &x, sizeof(T));
}
template <class T>
void Vector<T>::resize(size_t n, const T& val) {
	if (n >= m_capacity) {
		size_t m = m_size;
		m_size = n;
		reserve(n);
		for (size_t i = 0; i < m_size; memcpy(m_data + i, &val, sizeof(T)), ++i);
	}
}
template <class T>
void Vector<T>::resize(size_t n) {
	if (n >= m_capacity) {
		size_t m = m_size;
		m_size = n;
		reserve(n);
		memset(m_data + m_size, 0, (m_capacity - m_size) * sizeof(T));
	}
}
template <class T>
void Vector<T>::reserve(size_t n) {
	if (n >= m_capacity) {
		m_capacity != 0 ? m_capacity = n + (m_capacity / 2) : m_capacity = 10;
		m_data = (T*)realloc(m_data, sizeof(T)*m_capacity);
	}
}
template <class T>
size_t Vector<T>::size() {
	return m_size;
}
template <class T>
size_t Vector<T>::capacity() {
	return m_capacity;
}
template <class T>
bool Vector<T>::empty() {
	return m_size == 0;
}
template <class T>
void Vector<T>::clear() {
	m_size = 0;
}
template <class T>
T& Vector<T>::operator[](const size_t n) {
	return m_data[n];
}
template <class T>
T& Vector<T>::operator[](const size_t n)const { 
	return m_data[n];
}
template <class T>
void Vector<T>::pop_back() {
	if (m_size > 0) {
		--m_size;
	}
}
