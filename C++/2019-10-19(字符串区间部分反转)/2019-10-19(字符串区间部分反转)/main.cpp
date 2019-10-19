#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	string reverseStr(string s, int k) {
		string res;
		int size = s.size();
		int i, j, m;
		bool flag = true;
		for (i = 0, j = k - 1; j < size; i = j + 1, j = i + k - 1) {
			if (flag) {
				for (m = j; m >= i; --m) {
					res.push_back(s[m]);
				}
				flag = false;
			}
			else {
				for (m = i; m <= j; ++m) {
					res.push_back(s[m]);
				}
				flag = true;
			}
		}
		if (flag) {
			for (m = size - 1; m >= i; --m) {
				res.push_back(s[m]);
			}
		}
		else {
			for (m = i; m < size; ++m) {
				res.push_back(s[m]);
			}
		}
		return res;
	}
};
int main() {
	Solution p;
	string s = "abcdefghigklmn";
	cout<<p.reverseStr(s,3);
	system("pause");
	return 0;
}