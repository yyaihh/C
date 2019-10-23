#include<iostream>
#include"class.h"
using namespace std;

int main() {
	/*T1* t1_p = T1::newT1_p(10);
	cout << t1_p->b << endl;
	T1& t1 = T1::newT1(20);
	cout << t1.b << endl;*/
	T2* t2_p = new T2(10);
	cout << t2_p->b << endl;
	t2_p = t2_p->Destroy();
	t2_p ? cout << t2_p->b << endl : cout << "t2_p±»ÊÍ·Å\n";
	T3 a;
	cout << a.a << endl;
	T3 b(10);
	cout << b.a << endl;
	T3* p1 = new T3;
	T3* p2 = new T3(10);
	system("pause");
	return 0;
}