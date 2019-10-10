#include<iostream>
#include"StackQueue.h"

int main() {
	StackQueue<int> a;
	for (int i = 0; i < 5; ++i) {
		a.push(i + 1);
	}
	cout << a.front() << endl;
	a.pop();
	cout << a.front() << endl;
	a.pop();
	cout << a.front() << endl;
	a.pop();
	cout << a.front() << endl;
	a.pop();
	cout << a.front() << endl;
	cout << a.empty() << endl;
	a.pop();
	cout << a.empty() << endl;
	system("pause");
	return 0;
}