#include<iostream>
using namespace std;
class T1 {
public:
	int a;
	T1(int b) {
		a = b;
	}
};
class T2 :public T1{
public:
	int b;
	T2(int c, int d) :T1(d){
		b = c;
	}
};
class T3 {
	T3(int val = 0):b(val) {

	}
public:
	int b;
	static T3* newT3_p(int val = 0) {
		return new T3(val);
	}
	static T3& newT3(int val = 0) {
		return *new T3(val);
	}
};

class T4 {
	~T4() {

	}
public:
	int b;
	T4(int val = 0) :b(val) {

	}
	T4* Destroy() {
		delete this;
		return nullptr;
	}
};
int main() {
	T1* p1 = new T1(1);
	T2* p2 = (T2*)p1;
	cout << p2->a << endl;
	cout << p2->b << endl;
	T3* T3_p = T3::newT3_p(10);
	cout << T3_p->b << endl;
	T4* T4_p = new T4(10);
	T4_p = T4_p->Destroy();
	cout << T4_p->b << endl;
	system("pause");
	return 0;
}