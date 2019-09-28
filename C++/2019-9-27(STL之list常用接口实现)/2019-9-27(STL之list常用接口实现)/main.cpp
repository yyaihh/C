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
	p.Print_vector(mylist_1);
	p.Print_vector(mylist_2);
	p.Print_vector(mylist_3);
	p.Print_vector(mylist_4);
	p.Print_vector(mylist_5);
	p.Print_vector(mylist_6);
	//mylist_2.clear();
	/*cout << mylist_2.size() << endl;
	mylist_3.push_back(10);
	cout << mylist_3.size() << endl;
	cout << mylist_4.size() << endl;*/
	system("pause");
	return 0;
}