#include<iostream>
using namespace std;
int main() {
	int* p = new int[20];
	*p = 0;//第一个为0
	*(p + 1) = 1;//第二个为1
	for (int i = 2; i < 20; ++i) { 
		*(p + i) = *(p + i - 1) + *(p + i - 2);
	}
	for (int i = 0; i < 20; ++i) {
		cout << *(p + i)<<"\t";
	}
	cout << endl;
	delete[]p;
	system("pause");
	return 0;
}