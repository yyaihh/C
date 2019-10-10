#pragma once
#include<stack>
using namespace std;

template<class T>
class StackQueue {
	stack<T> s1;
	stack<T> s2;
public:
	StackQueue() {

	}
	void push(const T& x) {
		while (s2.size()) {
			s1.push(s2.top());
			s2.pop();
		}
		s1.push(x);
	}
	T pop() {
		/*while (s1.size()) {
			s2.push(s1.top());
			s1.pop();
		}*/
		T tmp = front();
		s2.pop();
		return tmp;
	}
	T front() {
		while (s1.size()) {
			s2.push(s1.top());
			s1.pop();
		}
		return s2.top();
	}
	T back() {
		while (s2.size()) {
			s1.push(s2.top());
			s2.pop();
		}
		return s1.top();
	}
	bool empty() {
		return s1.empty() && s2.empty();
	}
};