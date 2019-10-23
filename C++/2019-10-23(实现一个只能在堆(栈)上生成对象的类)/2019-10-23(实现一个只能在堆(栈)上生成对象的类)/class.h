#pragma once
class T1 {
	T1(int val = 0) :b(val) {

	}
public:
	int b;
	static T1* newT1_p(int val = 0) {
		return new T1(val);
	}
	static T1& newT1(int val = 0) {
		return *new T1(val);
	}
};
class T2 {
	~T2() {

	}
public:
	int b;
	T2(int val = 0) :b(val) {

	}
	T2* Destroy() {
		delete this;
		return nullptr;
	}
};
class T3 {
	void* operator new(size_t val) {}
public:
	int a;
	T3(int val = 0) :a(val) {

	}
};