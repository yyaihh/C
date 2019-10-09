#include<iostream>
#include"MinStack.h"
int main() {
	MinStack<int> s;
	s.push(4);
	s.push(5);
	s.push(3);
	s.push(6);
	s.push(2);
	s.push(2);
	cout << s.getMin() << endl;
	s.pop();
	cout << s.getMin() << endl;
	system("pause");
	return 0;
}