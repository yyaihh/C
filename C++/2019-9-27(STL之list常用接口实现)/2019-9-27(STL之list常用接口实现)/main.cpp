#include<iostream>
#include"list.h"
using namespace std;
class Solution {
public:
	void Print_vector_int(List<int>& v) {
		for (auto i : v) {
			cout << i << ' ';
		}
		cout << endl;
	}
};
int main() {
	List<int> mylist_1;
	List<int> mylist_2(5, 10);
	List<int> mylist_3(mylist_2); 
	cout << mylist_1.size() << endl;
	cout << mylist_2.size() << endl;
	cout << mylist_3.size() << endl;
	Solution p;
	p.Print_vector_int(mylist_2);
	p.Print_vector_int(mylist_3);
	mylist_2.clear();
	cout << mylist_2.size() << endl;
	mylist_3.push_back(10);
	cout << mylist_3.size() << endl;
	system("pause");
	return 0;
}