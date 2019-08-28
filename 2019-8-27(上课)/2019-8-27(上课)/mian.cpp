#include<iostream>
using namespace std;
void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}
int main (){
	int array[] = { 1, 2, 3, 4, 5 };
	for (auto e : array)
		e *= 2;
	for (auto e : array)
		cout << e << " ";
	f(0);
	f(nullptr);
	f((int*)NULL);
	return 0;
}