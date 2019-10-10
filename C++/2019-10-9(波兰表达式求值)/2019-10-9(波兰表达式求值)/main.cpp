#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<string>
#include<cassert>
using namespace std;
//(a + b)*c - (a + b) / e的后缀表达式为：
//(a + b)*c - (a + b) / e
//→((a + b)*c)((a + b) / e) -
//→((a + b)c*)((a + b)e / ) -
//→(ab + c * )(ab + e / ) -
//→ab + c * ab + e / -
class Solution {
	stack<char> ch;
	stack<int> num;
public:
	int evalRPN(vector<string>& tokens) {
		//二叉树后序变中序的过程
		//可以直接用vector做, 找到符运算符, 前两个就是需要计算的值, 然后将这三个位置换成计算的值
		for (auto i : tokens) { 
			if (i[0] >= '0' && i[0] <= '9' || i.size() > 1) { 
				num.push(atoi(i.c_str()));
			}
			else {
				ch.push(i[0]);
			}
		}
	

		while (q.size()) {
			if (s.top() == '+') {
				num += q.top();
			}
			else if (s.top() == '-') {
				num -= q.top();
			}
			else if (s.top() == '*') {
				num *= q.top();
			}
			else  {
				num /= q.top();
			}
			q.pop();
			s.pop();
		}
		return num;
	}
};

int main() {
	vector<string> tokens;
	tokens.push_back("4");
	tokens.push_back("13");
	tokens.push_back("5");
	tokens.push_back("/");
	tokens.push_back("+");
	Solution p;
	cout << p.evalRPN(tokens) << endl;
	system("pause");
	return 0;
}