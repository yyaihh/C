#pragma once
#include<vector>
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
#if 1
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

		auto m = numbers.end();
		auto begin = numbers.begin();
		for (auto i = begin; i + 1< m; ++i) { 
			if()
		}
#endif
	}
};

