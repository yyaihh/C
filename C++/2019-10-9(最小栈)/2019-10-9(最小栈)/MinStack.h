#pragma once
#include<stack>
using namespace std;
template<class T>
class MinStack {
	stack<T> s;
	stack<T> min;
public:
	MinStack() {

	}

	void push(int x) {
		s.push(x);
		if (min.empty()) {
			min.push(x);
		}
		else if (x <= min.top()) {
			min.push(x);
		}
	}

	void pop() {
		if (min.top() == s.top()) {
			min.pop();
		}
		s.pop();
	}

	int top() {
		return s.top();
	}

	int getMin() {
		return min.top();
	}
};
