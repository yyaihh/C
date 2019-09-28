#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Solution {
public:
	void Print_list(list<int>& mylist) {
		for (auto i : mylist) {
			cout << i <<" ";
		}
		cout << endl;
	}
};
int main() {
	//list<int> mylist_1;//空
	//list<int> mylist_2(10, 1);//10个1
	//list<int> mylist_3(10);//10个0
	//list<int> mylist_4(mylist_2);
	//int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	//list<int> mylist_5(a, a + sizeof(a) / sizeof(a[0]));
	//vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
	//list<int>mylist_6(v.begin(), v.end());
	//Solution p;
	//cout << sizeof(mylist_1) << endl;
	////mylist_1.push_back(10);
	//p.Print_list(mylist_1);
	//p.Print_list(mylist_2);
	//p.Print_list(mylist_3);
	//p.Print_list(mylist_4);
	//p.Print_list(mylist_5);
	//p.Print_list(mylist_6);
	////链表中有sort函数, 用插排实现
	////两个有序链表的合并,merge函数

	////insert迭代器失效测试
	//mylist_5.back() = -10;
	//list<int> ::iterator pos = mylist_6.begin();
	//++pos;
	//cout << *pos << endl;
	//cout << *mylist_6.insert(pos, mylist_5.rbegin(),mylist_5.rend()) << endl;
	//p.Print_list(mylist_6);
	//cout << *++pos << endl;
	////结论, insert不会导致迭代器失效, pos还是指向原来的位置
	////insert返回的是新插入的结点(连续结点)的(开头)迭代器

	list<int> mylist_1;
	list<int> mylist_2(5, 10);
	for (int i = 0; i < 10; i++) {
		mylist_1.push_back(i + 1);
	}
	list<int> mylist_3(mylist_1);
	list<int> mylist_4(++mylist_1.begin(), --mylist_1.end());
	list<int> mylist_5(++mylist_3.begin(), --mylist_3.end());
	list<int> mylist_5_(mylist_5);
	list<int> mylist_2_(mylist_2);
	list<int> mylist_6(++mylist_2.begin(), --mylist_2.end());
	list<int> mylist_7(++mylist_2_.begin(), --mylist_2_.end());
	list<int> mylist_8(++mylist_5_.begin(), --mylist_5_.end());
	list<int> mylist_9(++mylist_2.begin(), --mylist_2.end());
	cout << mylist_1.size() << endl;
	cout << mylist_2.size() << endl;
	cout << mylist_3.size() << endl;
	Solution p;
	p.Print_list(mylist_1);
	p.Print_list(mylist_2);
	p.Print_list(mylist_2_);
	p.Print_list(mylist_3);
	p.Print_list(mylist_4);
	p.Print_list(mylist_5);
	p.Print_list(mylist_5_);
	p.Print_list(mylist_6);
	p.Print_list(mylist_7);
	p.Print_list(mylist_8);
	p.Print_list(mylist_9);

	system("pause");
	return 0;
}