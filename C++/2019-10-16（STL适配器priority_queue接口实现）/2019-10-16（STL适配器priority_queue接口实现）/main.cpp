#include<iostream>
#include"priority_queue.h"
#include<queue>
#include<vector>
#include<functional>
using namespace std;
void Test_priority_queue() {
	cout << "STL中的priority_queue\n";
	priority_queue<int> pq;
	for (int i = 1; i <= 5; ++i) {
		pq.push(i);
	}
	cout << "size = " << pq.size() << endl;
	for (int i = 1; !pq.empty(); i *= 2) {
		for (int j = i; !pq.empty() && j > 0; --j) {
			cout << pq.top() << ' ';
			pq.pop();
		}
		cout << endl;
	}
	cout << "size = " << pq.size() << endl;
}
void Test_my_priority_queue() {
	cout << "自己实现的的priority_queue\n";
	my_priority_queue<int, deque<int>, Less<int>> pq;
	//my_priority_queue<int> pq;
	for (int i = 1; i <= 5; ++i) {
		pq.push(i);
	}
	cout << "size = " << pq.size() << endl;
	for (int i = 1; !pq.empty(); i *= 2) {
		for (int j = i; !pq.empty() && j > 0; --j) {
			cout << pq.top() << ' ';
			pq.pop();
		}
		cout << endl;
	}
	cout << "size = " << pq.size() << endl;
}
int main() {
	Test_priority_queue();
	Test_my_priority_queue();
	system("pause");
	return 0;
}
