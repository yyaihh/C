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
	Vector<T>& operator=(const Vector<T>& x);
	size_t size();
	size_t capacity();
	void swap(Vector<T>& x);
	friend void swap(Vector<T>& a, Vector<T>& b) {
		Vector<T> tmp = a;
		a = b;
		b = tmp;
	}
	bool empty();
	void clear();
	void resize(size_t n, const T& val = T()) {
			if (n >= m_capacity) {
				size_t m = m_size;
				m_size = n;
				reserve(n);
				for (size_t i = 0; i < m_size; memcpy(m_data + i, &val, sizeof(T)), ++i);
			}
		
	}
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
		memcpy(position, position + 1, (end() - position - 1)*sizeof(T));//不需要深拷贝
		--m_size;
		return position;
	}
	Iterator erase(Iterator first, Iterator last) {
		memcpy(first, last, (end() - last) * sizeof(T));//不需要深拷贝
		m_size -= (last - first);
		return first;
	}
	Iterator insert(Iterator position, const T& val) {
		reserve(++m_size);
		for (Iterator i = end(); i >= position; --i) {
			*i = *(i - 1);
		}
		*position = val;
		return position;
	}
	Iterator insert(Iterator position, size_t n = 1, const T& val = T()) {
		m_size += n;
		reserve(m_size);
		for (Iterator i = end(); i >= position + n; --i) {
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
		position = m_data + tmp;//迭代器的值可能会发生变化, 因为reserve可能会重新分配内存, 释放掉原来的内存
		//迭代器可能失效
		for (Iterator i = end(); i >= position + n; --i) {
			*i = *(i - n);
		}
		//memcpy(m_data + tmp, first, n * sizeof(T));
		//可能会出现深拷贝
		for (Iterator i = position; i < position + n; ++i, ++first) {
			*i = *first;
		}
		return position;
	}
	Iterator insert(Iterator position, T&& val) {
		reserve(++m_size);
		for (Iterator i = end(); i >= position; --i) {
			*i = *(i - 1);
		}
		*position = val;
		return position;
	}
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
void Vector<T>::swap(Vector<T>& x) {
	Vector<T> tmp = *this;
	*this = x;
	x = tmp;
}
template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& x) {
	m_size = x.m_size;
	m_capacity = x.m_capacity;
	m_data = new T[x.m_capacity];
	memcpy(m_data, x.m_data, m_capacity * sizeof(T));
	return *this;
}
template <class T>
void Vector<T>::push_back(const T& x) {
	++m_size;
	reserve(m_size);
	memcpy(m_data + m_size - 1, &x, sizeof(T));
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
