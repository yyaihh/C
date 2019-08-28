#include<iostream>
using namespace std;
struct AB {
	int a;
	int b;
	void print1() {
		cout << a<<endl;
	}
	void print2();
};
void AB:: print2() {
	cout << b << endl;
}
int main_() {

	AB test;
	test.a = 10;
	test.b = 100;
	test.print1();
	test.print2();
	system("pause");
	return 0;
}