#include<iostream>
#include"list.h"
using namespace std;
class Solution {
public:
	void Print_vector(List<int>& v) {
		for (auto i : v) {
			cout << i << ' ';
		}
		cout << endl;
	}
};
int main() {
	List<int> mylist_1;
	List<int> mylist_2(5, 10);
	for (int i = 0; i < 10; i++) {
		mylist_1.push_back(i + 1);
	}
	List<int> mylist_3(mylist_2);
	List<int> mylist_4(mylist_2.begin(), --mylist_2.end());
	List<int> mylist_5(mylist_3.begin(), --mylist_3.end());
	List<int> mylist_6;
	mylist_6.push_back(-1);
	auto  j = mylist_6.begin();
	cout << *j << endl;
	auto i = mylist_6.insert(mylist_6.begin(), mylist_1.begin(), mylist_1.end());
	//mylist_6.pop_back();
	cout << *i << endl;
	cout << *j << endl;
	Solution p;
	cout << "mylist_1:";
	p.Print_vector(mylist_1);
	cout << "mylist_2:";
	p.Print_vector(mylist_2);
	cout << "mylist_3:";
	p.Print_vector(mylist_3);
	cout << "mylist_4:";
	p.Print_vector(mylist_4);
	cout << "mylist_5:";
	p.Print_vector(mylist_5);
	cout << "mylist_6:";
	p.Print_vector(mylist_6);
	mylist_6.pop_back();
	cout << "mylist_6:";
	p.Print_vector(mylist_6);
	mylist_6.push_front(100);
	cout << "mylist_6:";
	p.Print_vector(mylist_6);
	mylist_6.erase(mylist_6.begin(), ++++mylist_6.begin());
	cout << "mylist_6:";
	p.Print_vector(mylist_6);
	cout << "mylist_1的元素个数:";
	cout << mylist_1.size() << endl;
	cout << "清空mylist_1\n";
	mylist_1.clear();
	mylist_1.empty() ? cout << "mylist_1为空" << endl : cout << "mylist_1为空" << endl;
	cout << "mylist_1的元素个数:";
	cout << mylist_1.size() << endl;
	cout << "交换mylist_5和mylist_6\n";
	mylist_6.swap(mylist_5);
	cout << "mylist_5:";
	p.Print_vector(mylist_5);
	cout << "mylist_6:";
	p.Print_vector(mylist_6);
	system("pause");
	return 0;
}