#include<iostream>
#include"vector.h"
using namespace std;
int main() {
	Vector<int> arr;
	for (int i = 0; i < 11; ++i) {
		arr.push_back(i + 1);
	}
	Vector<int>arr2(arr);
	//Vector<int>::Iterator j = arr.erase(arr.begin() + 2, arr.begin() + 4);
	//Vector<int>::Iterator j = arr.insert(arr.begin() + 2, (size_t)3, 100);
	Vector<int>::Iterator j = arr.insert(arr.begin() + 2, arr2.begin(), arr2.end());
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