#include<iostream>
#include<stack>
#include<deque>
#include<list>
#include<vector>
#include"mystack.h"
using namespace std;

void Test_stack() {
	cout << "STL中的stack\n";
	stack<int, deque<int>> s;
	for (int i = 1; i <= 5; ++i) {
		s.push(i);
	}
	cout << "size = " << s.size() << endl;
	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	cout << "size = " << s.size() << endl;
}
void Test_mystack() {
	cout << "自己实现的的stack\n";
	mystack<int> s;
	//mystack<int, list<int>> s;
	//mystack<int, vector<int>> s;
	for (int i = 1; i <= 5; ++i) {
		s.push(i);
	}
	cout << "size = " << s.size() << endl;
	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	cout << "size = " << s.size() << endl;
}
int main() {
	Test_stack();
	Test_mystack();
	system("pause");
	return 0;
}