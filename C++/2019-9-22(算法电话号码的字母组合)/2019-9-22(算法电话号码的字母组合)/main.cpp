#include<iostream>
#include<vector>
#include<string>
using namespace std;
//class Solution {
//
//public:
//	static string str[8];
//	void dealletterCombinations(string& digits, size_t pos, vector<string>& alldata) {
//		static string tmp = digits;
//		if (pos < digits.size()) {
//			for (auto i : str[digits[pos] - '2']) {
//				tmp[pos] = i;
//				dealletterCombinations(digits, pos + 1, alldata);
//			}
//		}
//		else {
//			alldata.push_back(tmp);
//		}
//	}
//	vector<string> letterCombinations(string& digits) {
//		vector<string> res;
//		if (digits.empty()) {
//			return res;
//		}
//		dealletterCombinations(digits, 0, res);
//		return res;
//	}
//};
class Solution {
	static string str[8];
	void dealletterCombinations(vector<string>& res, const string& s, int pos) {
		int _size = s.size();
		static string tmp(s.size(), 0);
		if (pos < _size) {
			for (auto i : str[s[pos] - '2']) {
				tmp[pos] = i;
				dealletterCombinations(res, s, pos + 1);
			}
		}
		else {
			res.push_back(tmp);
		}
	}
public:
	vector<string>& letterCombinations(const string& s) {
		static vector<string> res;
		if (s.empty()) return res;
		for (auto i : s) {
			if (i < '2') {
				return res;
			}
		}
		dealletterCombinations(res, s, 0);
		return res;
	}
};
string Solution::str[8] = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };

int main() {
	string test = "23456789";
	Solution fun;
	for (auto i : fun.letterCombinations(test)) {
		cout << i << endl;
	}

	system("pause");
	return 0;
}
