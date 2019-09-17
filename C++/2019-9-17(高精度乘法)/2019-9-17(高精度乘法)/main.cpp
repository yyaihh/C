#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string multiply(string num1, string num2) {
		string stmp, res;
		char n = 0;//ำเสý
		char m = 0;//ษฬ
		int left1 = 0;
		int left2 = 0;
		int right1 = num1.size() - 1;
		int right2 = num2.size() - 1;
		stmp.resize(num1.size() + 2 + num2.size(), '0');
		if (right1 >= 0 && right2 >= 0) {
			num1[0] == '-' ? left1 = 1, stmp[0] = '-' : left1;
			num2[0] == '-' ? left2 = 1, stmp[0] = '-' : left2;
			(num1[0] == '-') && (num2[0] == '-') ? stmp[0] = '0' : left1;
		}
		else {
			stmp.clear();
			stmp = "0";
			return stmp;
		}
		int t;
		for (int j = (int)stmp.size() - 1; right2 >= left2; --right2, --j) {
			for (int i = right1, tmp = j; i >= left1; --i, --tmp) {
				n = (num1[i] - '0')*(num2[right2] - '0') % 10 + m;
				t = stmp[tmp] + n - '0';
				if (t < 10) {
					stmp[tmp] = (stmp[tmp] + n - '0') % 10 + '0';
					stmp[tmp - 1] = t / 10 + '0';
				}
				else {
					stmp[tmp] += n;
				}
				m = n / 10;
			}
		}
		if (stmp[0] == '-') {
			res.push_back('-');
		}
		int i = 1, j = stmp.size();
		for (; (i < j) && (stmp[i] == '0'); ++i);
		for (; i < j; ++i) {
			res.push_back(stmp[i]);
		}
		return res;
	}
};
int main() {
	string s1("-123");
	string s2("11");
	Solution mul;
	cout << mul.multiply(s1, s2) << endl;
	system("pause");
	return 0;
}
