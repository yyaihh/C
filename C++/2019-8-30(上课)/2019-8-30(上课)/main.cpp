#include<iostream>
using namespace std;

class A {
public:
	int a;
	const int b;
	int& c;
	A(int& d):b(3),c(d),a(10)
	{}
	void test() {
		test_();
	}
	void print()const {
		cout << a;
	}
	const void test_() {
		a = 100;
	}
};
int main() {
	int i = 9;
	A test(i);
	A const test2(i);
	test2.print();
	test.test();
	cout << test.a;
	
	return 0;
}