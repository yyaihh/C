#include<iostream>
using namespace std;
#define SWAP1(A,B)A=A^B;B=A^B;A=A^B
#define SWAP2(Type,A,B)Type s;s=A;A=B;B=s
inline void Swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}
inline void Swap(double& a, double& b) {
	double tmp = a;
	a = b;
	b = tmp;
}
int main() {

	int a = 100;
	int b = 200;
	double c = 10.234;
	double d = 52.01314;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl << endl;
	SWAP1(a, b);
	SWAP2(double, c, d);
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl << endl;
	Swap(a, b);
	Swap(c, d);
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl << endl;
	system("pause");
	return 0;
}