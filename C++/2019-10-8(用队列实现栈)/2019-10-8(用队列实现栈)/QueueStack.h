#pragma once
#include<queue>
using namespace std;
#if 0
template<class T>
class QueueStack {
	queue<T> qu1;
public:
	QueueStack() { 

	}
	void push(const T& val) {
		qu1.push(val);
	}
	void pop() {
		queue<T> qu2;
		while (qu1.size() > 1) {
			qu2.push(qu1.front());
			qu1.pop();
		}
		qu1 = qu2;
	}
	T& top() {
		return qu1.back();
	}
	bool empty() {
		return qu1.empty();
	}
};
#else
template<class T>
class QueueStack {
	queue<T> qu1;
public:
	QueueStack() {

	}
	void push(const T& val) {
		qu1.push(val);
		size_t size = qu1.size();
		while (--size) {
			qu1.push(qu1.front());
			qu1.pop();
		}
	}
	void pop() {
		qu1.pop();
	}
	T& top() {
		return qu1.front();
	}
	bool empty() {
		return qu1.empty();
	}
};
#endif