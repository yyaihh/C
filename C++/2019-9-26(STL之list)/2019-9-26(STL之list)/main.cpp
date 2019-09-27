#include<iostream>
#include<list>
using namespace std;

class Solution {
public:
	void Print_list(list<int>& mylist) {
		for (auto i : mylist) {
			cout << i;
		}
		cout << endl;
	}
};
int main() {
	list<int> mylist_1;
	list<int> mylist_2(10, 1);//10¸ö1
	list<int> mylist_3(10);//10¸ö0
	list<int> mylist_4(mylist_2);
	Solution p;
	cout << sizeof(mylist_1) << endl;
	//mylist_1.push_back(10);
	p.Print_list(mylist_1);
	p.Print_list(mylist_2);
	p.Print_list(mylist_3);
	p.Print_list(mylist_4);
	system("pause");
	return 0;
}