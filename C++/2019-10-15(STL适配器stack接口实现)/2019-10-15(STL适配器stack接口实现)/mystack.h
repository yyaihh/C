#pragma once
#include<deque>
using namespace std;
template<class T, class Con = deque<T>>
class mystack {
	Con s;
public:
	mystack() {

	}

	void push(const T& val) {
		s.push_back(val);
	}
	void pop() {
		s.pop_back();
	}
	T& top() {
		return s.back();
	}
	int size() {
		return s.size();
	}
	bool empty() {
		return s.empty();
	}
};