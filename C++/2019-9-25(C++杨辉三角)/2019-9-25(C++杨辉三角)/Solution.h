#pragma once
#include<vector>
using namespace std;
class Solution {

public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res;
		if (numRows <= 0) {
			return res;
		}
		vector<int>tmp(1, 1);
		res.push_back(tmp);
		int n, m;
		for (int i = 1; i < numRows; ++i) {
			m = 1;
			tmp.resize(tmp.size() + 1);
			for (int j = 1; j < i; ++j) {
				n = tmp[j];
				tmp[j] += m;
				m = n;
			}
			tmp[i] = 1;
			res.push_back(tmp);
		}
		return res;
	}
};