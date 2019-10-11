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
	stack<int> num;
public:
	int evalRPN(vector<string>& tokens) {
		//二叉树后序变中序的过程
		//可以直接用vector做, 找到符运算符, 前两个就是需要计算的值, 然后将这三个位置换成计算的值
		int leftnum;
		int rightnum;
		for (auto str : tokens) {
			if (str.size() > 1 || str[0] >= '0'&&str[0] <= '9') {
				num.push(atoi(str.c_str()));
			}
			else {
				rightnum = num.top();
				num.pop();
				leftnum = num.top();
				switch (str[0]) {
				case '+':
					num.top() = leftnum + rightnum;
					break;
				case '-':
					num.top() = leftnum - rightnum;
					break;
				case '*':
					num.top() = leftnum * rightnum;
					break;
				case '/':
					num.top() = leftnum / rightnum;
					break;
				}
			}
		}
		return num.top();
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