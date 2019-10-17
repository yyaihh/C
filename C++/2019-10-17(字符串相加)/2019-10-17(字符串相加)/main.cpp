#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string addStrings(string num1, string num2) {
		string t;
		auto i = num1.rbegin();
		auto j = num2.rbegin();
		auto iend = num1.rend();
		auto jend = num2.rend();
		char c1 = '0';
		int tmp;
		for (; i != iend && j != jend; ++i, ++j) {
			tmp = *i + *j + c1 - 144;//和
			c1 = tmp / 10 + '0';//进位
			t.push_back(tmp % 10 + '0');
		}
		for (; i != iend; ++i) {
			tmp = *i + c1 - 96;//和
			c1 = tmp / 10 + '0';//进位
			t.push_back(tmp % 10 + '0');
		}
		for (; j != jend;++j) {
			tmp = *j + c1 - 96;//和
			c1 = tmp / 10 + '0';//进位
			t.push_back(tmp % 10 + '0');
		}
		if (c1 != '0') {
			t.push_back(c1);
		}
		auto y = t.rend();
		string res(t.rbegin(), t.rend());
		return res;
	}
};
int main() {
	Solution p;
	cout << p.addStrings("9","99")<<endl;
	system("pause");
	return 0;
}