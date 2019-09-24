#pragma once
#include<vector>
#include <algorithm>
#include<iostream>
using namespace std;
class Solution {
	void swapArga(int* a, int* b) {
		int tmp;
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
	int HoareWay(int* src, int start, int end) {
		int a = start + 1;
		int b = end - 2;
		int mid = (start + end) / 2;
		if (src[start] > src[mid]) {
			swapArga(src + start, src + mid);
		}
		if (src[mid] > src[end]) {
			swapArga(src + mid, src + end);
		}
		if (src[start] > src[mid]) {
			swapArga(src + start, src + mid);
		}
		if (end - start <= 2) {
			return mid;
		}
		swapArga(src + mid, src + end - 1);
		while (a <= b) {
			while (a < end - 1 && src[a] <= src[end - 1]) {
				++a;
			}
			while (b > 1 && src[b] >= src[end - 1]) {
				--b;
			}
			if (a == b && (a == 1 || a == end - 1)) {
				break;
			}
			if (a < b) {
				swapArga(src + a, src + b);
			}
		}
		swapArga(src + a, src + end - 1);
		return a;
	}
	void dealQuickSort(int* src, int start, int end) {
		int mid;
		if (start < end) {
			mid = HoareWay(src, start, end);
			dealQuickSort(src, start, mid - 1);
			dealQuickSort(src, mid + 1, end);
		}
	}
	void QuickSort(int* src, int size) {
		dealQuickSort(src, 0, size - 1);
	}
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
#if 0
		int s = numbers.size() / 2;
		QuickSort(&numbers[0], 2*s);
		int tmp = numbers[s / 2];
		auto m = numbers.begin();
		auto n = numbers.end();
		vector<int>::iterator left = m;
		vector<int>::iterator right = m;
		for (auto i = m; m < (m + s); ++i) { 
			if (*i == tmp) {
				left = i;
				break;
			}
		}
		for (auto i = n - 1; i >= (i-s); --i) { 
			if (*i == tmp) {
				right = i;
				break;
			}
		}
		if ((right - left + 1) > s) { 
			return tmp;
		}
		return 0;
#else
		int _size = numbers.size();
		if (_size == 0) {
			return 0;
		}
		if (_size == 1) {
			return numbers[0];
		}
		int count1 = 1;
		int count2 = 1;
		bool flag = true;
		int num;
		auto m = numbers.end();
		for (auto i = numbers.begin(); i + 1 < m; ++i) {
			if (flag) {
				*i^*(i + 1) ? flag = false : (++count2, num = *i);
			}
			else {
				*i^*(i + 1) ? flag = true : ++count1;
			}
			if (flag && count1 > count2) {
				num = *i;
				count2 = count1;
				count1 = 1;
			}
		}
		count1 = 0;
		for (auto i : numbers) {
			i ^ num ? 0 : ++count1;
		}
		return (count1 > _size / 2) ? num : 0;
#endif
	}
};

