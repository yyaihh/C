#include<iostream>
using namespace std;
int a = 1;
#define T1 a+a
#define T2 T1-T1
const int t1 = a + a;
const int t2 = t1 - t1;
int main() {
	cout << "T2= " << T2 << endl;
	cout << "t2= " << t2 << endl;
	system("pause");
	return 0;
}