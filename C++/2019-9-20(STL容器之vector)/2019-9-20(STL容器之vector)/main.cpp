#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> arr, arr1(10, -1);
	vector<string> str(10);
	for (int i = 0; i < 10; ++i) {
		arr.push_back(i + 1); 
	}
	//vector<int>::iterator i = arr.erase(arr.begin() + 2, arr.begin() + 4);
	vector<int>::iterator i = arr.insert(arr.begin() + 2, arr1.begin(), arr1.end());
	vector<int>::iterator j = arr.insert(arr.begin() + 2, 3, 10);
	cout << *i << endl;
	cout << endl;
	for (auto i : arr) {
		cout << i << ' ';
	}
	cout << endl;
	arr.pop_back();
	for (auto i : arr) {
		cout << i << ' ';
	}
	cout << endl;
	cout << endl;
	system("pause");
	return 0;
}