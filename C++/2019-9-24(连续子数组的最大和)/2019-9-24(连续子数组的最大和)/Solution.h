#pragma once
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
	void dealFindGreatestSumOfSubArray(vector<int>::iterator start, vector<int>::iterator end,
		vector<int>::iterator End, int& sum) {
		static int tmp = *start;
		static vector<int>::iterator tmpend;
		if (end < End) {
			if (start < end) {
				if (sum < tmp) sum = tmp;
				for (auto i = start + 1; i <= end; ++i) {
					tmp += *i;
				}
				if (sum < tmp) sum = tmp;
				tmp = *start;
				dealFindGreatestSumOfSubArray(start, end + 1, End, sum);
			}
		}
		else {
			if (start + 1 < End) {
				tmpend = start + 2;
				dealFindGreatestSumOfSubArray(start + 1, tmpend, End, sum);
			}
		}
	}
public:
	int FindGreatestSumOfSubArray_1(vector<int>& arr) {
		int sum = arr[0];
		dealFindGreatestSumOfSubArray(arr.begin(), arr.begin() + 1, arr.end(), sum);
		return sum;
	}
	inline int GetMax(int a, int b) {
		return a > b ? a : b;
	}
	int FindGreatestSumOfSubArray_2(vector<int>& arr) {
#if 1
		int Sum = arr[0];   //临时最大值
		int MAX = arr[0];   //比较之后的最大值
		int _size = arr.size();
		for (int i = 1; i < _size; i++) {
			Sum = GetMax(Sum + arr[i], arr[i]); //状态方程
			if (Sum >= MAX) MAX = Sum;
		}
		return MAX;
#else
		int MAX = arr[0];
		int sum = arr[0];
		int _size = arr.size();
		for (int i = 1; i < _size; i++) {
			if (sum < 0) {
				sum = arr[i];
			}
			else {
				sum += arr[i];
			}
			if (sum > MAX) MAX = sum;
		}
		return MAX;
#endif
	}
};

