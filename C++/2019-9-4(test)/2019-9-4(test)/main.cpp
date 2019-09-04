#include<iostream>
using namespace std;
void f(int) {
	cout << "f(int)" << endl;
}
void f(int*) {
	cout << "f(int*)" << endl;
}
int main() {
	int* p = nullptr;
	f(0);
	f(NULL);
	f((int*)NULL);
	system("pause");
	return 0;
}