#pragma once
#include<vector>
#include<deque>
#include<functional>
#include<algorithm>
using namespace std;
template <class T>
class Greater {
public:
	bool operator()(const T& left, const T& right){
		return left > right;
	}
};
template <class T>
class Less {
public:
	bool operator()(const T& left, const T& right) {
		return left < right;
	}
};
template<class T, class Con = vector<int>, class Cmp = Less<int>>
class my_priority_queue {
	Con m_data;
	Cmp m_cmp;
public:
	my_priority_queue() {

	}
	template <class InputIterator>
	my_priority_queue(InputIterator first, InputIterator last)
		: m_data(first, last){
		make_heap(m_data.begin(), m_data.end(), m_cmp);
	}
	void push(const T& val) {
		m_data.push_back(val);
		push_heap(m_data.begin(), m_data.end(), m_cmp);
	}
	void pop() {
		pop_heap(m_data.begin(), m_data.end(), m_cmp);
		m_data.pop_back();
	}
	T& top() {
		return m_data.front();
	}
	int size() {
		return m_data.size();
	}
	bool empty() {
		return m_data.empty();
	}

};