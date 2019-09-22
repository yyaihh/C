#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {

public:
	static string str[8];
	void dealletterCombinations(string& digits, size_t pos, vector<string>& alldata) {
		static string tmp = digits;
		if (pos < digits.size()) {
			for (auto i : str[digits[pos] - '2']) {
				tmp[pos] = i;
				dealletterCombinations(digits, pos + 1, alldata);
			}
		}
		else {
			alldata.push_back(tmp);
		}
	}
	vector<string> letterCombinations(string& digits) {
		vector<string> res;
		if (digits.empty()) {
			return res;
		}
		dealletterCombinations(digits, 0, res);
		return res;
	}
};
string Solution::str[8] = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };

int main() {
	string test = "3";
	Solution fun;
	//res = fun.letterCombinations(test);
	for (auto i : fun.letterCombinations(test)) {
		cout << i << endl;
	}

	system("pause");
	return 0;
}
