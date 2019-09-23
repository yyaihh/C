#include "Solution.h"

int Solution::singleNumber_1(const vector<int>& v) {
	int res = 0;
	for (auto i : v) {
		res ^= i;
	}
	return res;
}
int cmp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}
int Solution::singleNumber_2(const vector<int>& v) {
#if 1
	vector<int> tmp(v);
	//qsort(&tmp[0], tmp.size(), sizeof(tmp[0]), cmp);
	QuickSort(&tmp[0], v.size());
	if (tmp[0] != tmp[1] && tmp[1] == tmp[2]) {
		return tmp[0];
	}
	size_t size = tmp.size();
	size_t i = 0;
	for (; i + 1 < size; i += 3) { 
		if (tmp[i] != tmp[i + 1]) break;
	}
	return  tmp[i];
#elif 1
	int count = 0;
	auto m = v.end();
	for (auto i = v.begin(); i < m; ++i) { 
		for (auto j = i; j < m ; ++j) { 
			*i ^ *j ? count : ++count;
			if (count > 2) break;
		}
		if (count == 1) {
			return *i;
		}
		count = 0;
	}
	return count;
#else
	int sum = 0, tmp = 0;
	for (auto &i : nums) {
		sum = (sum ^ i) & ~tmp;
		tmp = (tmp ^ i) & ~sum;
	}
	return sum;
#endif
}
vector<int>  Solution::singleNumber_3(const vector<int>& v) {
#if 1
	vector<int> res;
	vector<int> tmp(v);
	bool flag = false;
	QuickSort(&tmp[0], v.size());
	auto _size = tmp.end();
	auto i = tmp.begin();
	if (*i ^ *(1 + i)) {
		res.push_back(*i);
		flag = true;
	}
	if (*(_size - 1) ^ *(_size - 2)) {
		res.push_back(*(_size - 1));
		if (flag)return res;
		flag = true;
	}
	for ( ++i; i + 1 < _size; ++i) {
		if (*(i - 1) ^ *i && *i ^ *(i + 1)) {
			res.push_back(*i);
			if (flag)return res;
			flag = true;
		}
	}
	return res;
#else
	vector<int> res;
	
	return res;
#endif
}