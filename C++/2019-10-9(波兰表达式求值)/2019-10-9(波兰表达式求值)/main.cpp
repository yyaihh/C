#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<string>
#include<cassert>
using namespace std;
//(a + b)*c - (a + b) / e�ĺ�׺���ʽΪ��
//(a + b)*c - (a + b) / e
//��((a + b)*c)((a + b) / e) -
//��((a + b)c*)((a + b)e / ) -
//��(ab + c * )(ab + e / ) -
//��ab + c * ab + e / -
class Solution {
	stack<char> ch;
	stack<int> num;
public:
	int evalRPN(vector<string>& tokens) {
		//���������������Ĺ���
		//����ֱ����vector��, �ҵ��������, ǰ����������Ҫ�����ֵ, Ȼ��������λ�û��ɼ����ֵ
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