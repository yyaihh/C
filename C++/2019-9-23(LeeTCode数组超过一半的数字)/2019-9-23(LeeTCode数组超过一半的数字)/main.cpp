#include<iostream>
using namespace std;
#include"Solution.h"
int main() {
	int a[] = { 1,2,3,2,2,2,5,4,2 };
	vector<int> arr(a, a + sizeof(a) / sizeof(a[0]));
	Solution fun;
	cout << fun.MoreThanHalfNum_Solution(arr) << endl;
	system("pause");
	return 0;
}