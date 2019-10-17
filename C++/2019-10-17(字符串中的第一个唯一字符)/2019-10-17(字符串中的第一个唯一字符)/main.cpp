//给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int firstUniqChar(string& s) {
		int flag[256] = { 0 };
		for (auto c : s) {
			++flag[c - '0'];
		}
		int size = s.size();
		for (int i = 0; i < size; ++i) {
			if (flag[s[i] - '0'] == 1) {
				return i;
			}
		}
		return -1;
	}
};
int main() {
	Solution p;
	string s;
	cin >> s;
	cout << p.firstUniqChar(s) << endl;
	system("pause");
	return 0;
}