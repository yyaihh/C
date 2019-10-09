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
	stack<char> s;
	stack<int> q;
public:
	int evalRPN(vector<string>& tokens) {
		for (auto i = tokens.rbegin(); i != tokens.rend(); ++i) {
			if ((*i)[0] < '0' || (*i)[0] > '9') {
				s.push((*i)[0]);
			}
			else {
				q.push(atoi((*i).c_str()));
			}
		}
		int num = q.top();
		q.pop();
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