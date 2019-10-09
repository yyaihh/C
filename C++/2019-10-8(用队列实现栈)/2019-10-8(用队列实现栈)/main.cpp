#include<iostream>
#include"QueueStack.h"

int main() {
	QueueStack<int> a;
	for (int i = 0; i < 5; ++i) {
		a.push(i + 1);
	}
	cout << a.top() << endl;
	a.pop();
	cout << a.top() << endl;
	a.pop();
	cout << a.top() << endl;
	a.pop();
	cout << a.top() << endl;
	a.pop();
	cout << a.top() << endl;
	system("pause");
	return 0;
}