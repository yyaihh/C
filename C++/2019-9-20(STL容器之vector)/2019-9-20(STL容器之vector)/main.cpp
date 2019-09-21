#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> arr,arr1(10);
	vector<string> str(10);
	for (int i = 0; i < 10; ++i) {
		arr.push_back(i + 1);
		cout << arr.capacity() << " ";
	}
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