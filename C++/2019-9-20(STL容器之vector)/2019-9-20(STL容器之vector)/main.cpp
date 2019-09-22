#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		for (auto i : nums) {
			res ^= i;
		}
		return res;
	}
};
int main() {
	vector<int> arr, arr1(10, -1);
	vector<vector<int>>arr2;//¶şÎ¬Êı×é
	vector<string> str(10);
	for (int i = 0; i < 10; ++i) {
		arr.push_back(i + 1); 
	}
	//vector<int>::iterator i = arr.erase(arr.begin() + 2, arr.begin() + 4);
	//vector<int>::iterator i = arr.insert(arr.begin() + 2, arr1.begin(), arr1.end());
	//vector<int>::iterator j = arr.insert(arr.begin() + 2, 3, 10);
	//cout << *i << endl;
	//swap(arr, arr1);
	//arr.swap(arr1);
	//arr.erase(arr.begin());
	cout << endl;
	for (auto i : arr) {
		cout << i << ' ';
	}
	cout << endl;
	//arr.pop_back();
	for (auto i : arr1) {
		cout << i << ' ';
	}
	cout << endl;
	cout << endl;
	Solution fun;
	int a = fun.singleNumber(arr);
	cout << a << endl;
	system("pause");
	return 0;
}