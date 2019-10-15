#pragma once
#include<deque>
using namespace std;
template<class T, class Con = deque<T>>
class myqueue {
	Con qu;
public:
	myqueue() {

	}

	void push(const T& val) {
		qu.push_back(val);
	}
	void pop() {
		qu.pop_front();
	}
	T& front() {
		return qu.front();
	}
	T& back() {
		return qu.back();
	}
	int size() {
		return qu.size();
	}
	bool empty() {
		return qu.empty();
	}
};