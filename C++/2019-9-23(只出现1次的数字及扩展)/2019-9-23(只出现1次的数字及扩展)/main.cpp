#include<iostream>
#include"Solution.h"
using namespace std;

int main() {
	int a1[] = { 1,2,3,4,5,5,4,3,2,1,6 };
	int a2[] = { 0,1,0,1,0,1,99 };
	int a3[] = { 1,2,3,4,5,6,5,4,3,2,1,9 };
	vector<int> arr1(a1, a1 + sizeof(a1) / sizeof(a1[0]));
	vector<int> arr2(a2, a2 + sizeof(a2) / sizeof(a2[0]));
	vector<int> arr3(a3, a3 + sizeof(a3) / sizeof(a3[0]));
	Solution fun;
	cout << fun.singleNumber_1(arr1) << endl;
	cout << fun.singleNumber_2(arr2) << endl;
	vector<int> tmp = fun.singleNumber_3(arr3);
	cout << tmp[0]<<" "<<tmp[1] << endl;
	system("pause");
	return 0;
}