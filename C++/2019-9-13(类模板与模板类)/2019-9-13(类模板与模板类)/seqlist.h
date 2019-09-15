#pragma once
#include<iostream>
using namespace std;

template<class T>
class seqList {
	T* m_data;
	size_t m_capacity;
	size_t m_size;
public:
	seqList(int n = 0) :
		m_capacity(n),
		m_size(0),
		m_data(new T[n])
	{
	}
	~seqList() {
		if (m_data) {
			delete []m_data;
			m_data = nullptr;
		}
		m_size = 0;
		m_capacity = 0;
	}
	void PushBack(const T& data);
	void PopBack();
	size_t size();
	T& operator[](size_t i);
	template <class T>
	friend ostream& operator<< (ostream& os,const seqList<T>& t);
};
template <class T>
void seqList<T>::PushBack(const T& data) {
	if (m_size == m_capacity) {
		T* tmp;
		while (m_size >= m_capacity) {
			m_capacity += 10;
		}
		tmp = new T[m_capacity];
		for (size_t i = 0; i < m_size; ++i) {
			tmp[i] = m_data[i];
		}
		tmp[m_size++] = data;
		m_data = tmp;
		return;
	}
	m_data[m_size++] = data;
}
template <class T>
void seqList<T>::PopBack() {
	if (m_size) {
		--m_size;
		return;
	}

}
template <class T>
ostream& operator<<(ostream& os, const seqList<T>& t) {
	for (size_t i = 0; i < t.m_size; ++i) {
		os << t.m_data[i] << " ";
	}
	return os;
}
template<class T>
T& seqList<T>::operator[](size_t i) {
	return m_data[i];
}
template<class T>
size_t seqList<T>::size() {
	return m_size;
}