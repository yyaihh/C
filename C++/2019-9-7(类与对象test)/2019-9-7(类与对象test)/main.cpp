#include"Person.h"
#include<iostream>
using namespace std;
class T1 {
	int a;
public:
	void fun1() {

	}
};
class T2 {
	int a;
	int b;
public:
	void fun1() {

	}
};
class T3 {
public:
	void fun1() {

	}
};
class Test {
	double a;
	char c;
};
int main() {
	cout << sizeof(Test) << endl;
	cout << sizeof(T2) << endl;
	cout << sizeof(T3) << endl;
	system("pause");
	return 0;
}