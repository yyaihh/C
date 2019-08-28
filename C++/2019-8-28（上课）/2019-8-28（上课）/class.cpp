#include<iostream>
using namespace std;
class A {
	int a;
public :
	int b;
	void input() {
		cin >> a;
	}
	void print1() {
		cout << a << endl;
	}
	void print2();
	void test() {
	
	}
};
void A::print2() {
	cout << b << endl;
}

int main() {
	A c;
	A* p;
	p = nullptr;
	p->test();
	c.input();
	c.print1();
	c.b = 100;
	c.print2();
	system("pause");
	return 0;
}