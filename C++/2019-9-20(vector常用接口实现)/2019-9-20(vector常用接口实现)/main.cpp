#include<iostream>
#include"vector.h"
using namespace std;
class Solution {
public:
	void Print_vector_int(Vector<int>& v) {
		for (auto i : v) {
			cout << i << ' ';
		}
	cout << endl;
	}
};
int main() {
	Vector<int> arr;
	for (int i = 0; i < 11; ++i) {
		arr.push_back(i + 1);
	}
	Vector<int>arr2(arr);
	Solution p;
	arr.swap(arr2);
	swap(arr, arr2);
	arr.erase(arr.begin() + 4);
	arr2.erase(arr2.begin() + 4, arr2.begin() + 7);
	Vector<int>::Iterator h = arr.begin() + 2;
	//arr.insert(h, 100);
	for (size_t i = 0; i < arr.size(); ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
	for (size_t i = 0; i < arr2.size(); ++i) {
		cout << arr2[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}