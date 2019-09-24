#include<iostream>
#include<vector>
#include"Solution.h"
using namespace std;

int main() {
	int a[] = {-2,-8,-1,-5,-9, 0 };
	vector<int>arr(a, a + sizeof(a) / sizeof(a[0]));
	Solution fun;
	cout << fun.FindGreatestSumOfSubArray(arr) << endl;
	system("pause");
	return 0;
}