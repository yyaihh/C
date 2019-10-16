#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int StrToInt(string str) {
		long long num = 0;
		int tmp = 1;
		int flag = 1;
		int min = -2147483647;
		int max = 2147483647;
		char ch;
		if (!str.empty()) {
			if (str[0] == '-') {
				flag = -1;
			}
			for (auto s = str.rbegin(); s != str.rend(); ++s, tmp *= 10) {
				ch = *s;
				if (ch >= '0'&&ch <= '9') {
					num += ((ch - '0')*tmp);
				}
				else if (s != (str.rend() - 1)) {
					return 0;
				}
			}
		}
		else {
			return 0;
		}
		num *= flag;
		if (num > max || num < min - 1) {
			return 0;
		}
		return (int)num;
	}
};

int main() {
	Solution p;
	cout << p.StrToInt("-2147483648") << endl;
	cout << p.StrToInt("-2147483649") << endl;
	cout << p.StrToInt("2147483648") << endl;
	cout << p.StrToInt("123456") << endl;
	cout << p.StrToInt("2sf36") << endl;
	system("pause");
	return 0;
}