#include<iostream>
#include<deque>
#include<queue>
#include<list>
#include"myqueue.h"
using namespace std;

void Test_queue() {
	cout << "STL中的queue\n";
	queue<int, deque<int>> qu;
	for (int i = 1; i <= 5; ++i) {
		qu.push(i);
	}
	cout << "size = " << qu.size() << endl;
	cout << qu.back() << endl;
	while (!qu.empty()) {
		cout << qu.front() << endl;
		qu.pop();
	}
	cout << "size = " << qu.size() << endl;
}
void Test_myqueue() {
	cout << "自己实现的的queue\n";
	myqueue<int> qu;
	//myqueue<int, list<int>> qu;
	for (int i = 1; i <= 5; ++i) {
		qu.push(i);
	}
	cout << "size = " << qu.size() << endl;
	cout << qu.back() << endl;
	while (!qu.empty()) {
		cout << qu.front() << endl;
		qu.pop();
	}
	cout << "size = " << qu.size() << endl;
}
int main() {
	Test_queue();
	Test_myqueue();
	system("pause");
	return 0;
}