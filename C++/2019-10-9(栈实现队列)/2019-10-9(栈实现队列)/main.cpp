#include<iostream>
#include"StackQueue.h"

int main() {
	StackQueue<int> a;
	for (int i = 0; i < 5; ++i) {
		a.push(i + 1);
	}
	cout << a.peek() << endl;
	a.pop();
	cout << a.peek() << endl;
	a.pop();
	cout << a.peek() << endl;
	a.pop();
	cout << a.peek() << endl;
	a.pop();
	cout << a.peek() << endl;
	cout << a.empty() << endl;
	a.pop();
	cout << a.empty() << endl;
	system("pause");
	return 0;
}