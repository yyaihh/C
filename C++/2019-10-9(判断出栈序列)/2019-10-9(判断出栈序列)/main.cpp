#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
//假设压入栈的所有数字均不相等。例如序列1, 2, 3, 4, 5是某栈的压入顺序，
//序列4, 5, 3, 2, 1是该压栈序列对应的一个弹出序列，但4, 3, 5, 1, 2就不可能是该压栈序列的弹出序列。
//（注意：这两个序列的长度是相等的）
class Solution {
public:
	bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
		stack<int> s;
		auto i = pushV.begin();
		auto j = popV.begin();
		for (; i != pushV.end(); ++i) { 
			if (*i != *j) {
				s.push(*i);
			}
			else {
				++j;
			}
		}
		for (; j != popV.end(); ++j) {
			if (s.top() != *j) {
				return false;
			}
			s.pop();
		}
		return true;
	}
};
int main() {
	int a[] = { 1,2,3,4,5 };
	//int b[] = { 4,5,3,2,1 };
	int b[] = { 4,3,5,1,2 };
	vector<int> v1(a, a + 5);
	vector<int> v2(b, b + 5);
	Solution p;
	cout << p.IsPopOrder(v1, v2) << endl;
	system("pause");
	return 0;
}