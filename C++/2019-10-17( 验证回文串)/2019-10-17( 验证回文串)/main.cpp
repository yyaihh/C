#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	bool isPalindrome(string s) {
		int size = s.size();
		char ch1, ch2;
		for (int i = 0, j = size - 1; i < j; ++i, --j) {
			ch1 = s[i];
			while ((ch1 < 'a' || ch1 > 'z') && (ch1 < 'A' || ch1 > 'Z') && (ch1 < '0' || ch1 > '9')) {
				++i;
				if (i == size) return true;
				ch1 = s[i];
			}
			if (i > j) return true;
			ch2= s[j];
			while ((ch2 < 'a' || ch2 > 'z') && (ch2 < 'A' || ch2 > 'Z') && (ch2 < '0' || ch2 > '9')) {
				--j;
				if (i > j) return false;
				ch2 = s[j];
			}
			if (ch1 >= '0'&&ch1 <= '9' && (ch2 < '0' || ch2 > '9')) {
				return false;
			}
			if (ch2 >= '0'&&ch2 <= '9' && (ch1 < '0' || ch1 > '9')) {
				return false;
			}
			if (ch1 != ch2 && ch1 + 32 != ch2 && ch2 + 32 != ch1) {
				return false;
			}
		}
		return true;
	}
	/*bool isPalindrome(string s) {
		string t;
		char ch1, ch2;
		for (auto i : s) {
			if (i >= 'a'&&i <= 'z' || i >= 'A'&&i <= 'Z' || i >= '0'&&i <= '9') { 
				t.push_back(i);
			}
		}
		for (int i = 0, j = t.size() - 1; i < j; ++i, --j) {
			ch1 = t[i];
			ch2 = t[j];
			if ( ch1 >= '0'&& ch1 <= '9' && (ch2 < '0' || ch2 > '9')) {
				return false;
			}
			if (ch2 >= '0'&&ch2 <= '9' && (ch1 < '0' || ch1 > '9')) {
				return false;
			}
			if (ch1 != ch2 && ch1 + 32 != ch2 && ch2 + 32 != ch1) {
				return false;
			}
		}
		return true;
	}*/
};
int main() {
	Solution p;
	cout << p.isPalindrome("a:}{>a}>{a") << endl;
	system("pause");
	return 0;
}