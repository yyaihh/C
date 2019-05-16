#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;
double sroot(int n) {
	return sqrt(n);
}
double sroot(long n) {
	return sqrt(n);
}
double sroot(double n) {
	return sqrt(n);
}
int main() {
	int a = 10;
	long b = 10000;
	double c = 13.14;
	cout << a << "的二次方根为" << sroot(a) << endl;//此时调用的是参数为int型的sroot
	cout << b << "的二次方根为" << sroot(b) << endl;//此时调用的是参数为long型的sroot
	cout << c << "的二次方根为" << sroot(c) << endl;//此时调用的是参数为double型的sroot	
	system("pause");
	return 0;
}