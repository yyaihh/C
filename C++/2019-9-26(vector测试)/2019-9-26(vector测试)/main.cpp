#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void Print_vector_int(const vector<int>& v) {
		for (auto i : v) {
			cout << i << ' ';
		}
		cout << endl;
	}
};
int main() {
	vector<int> arr;
	//	vector<vector<int>>arr2;//二维数组
	for (int i = 0; i < 10; ++i) {
		arr.push_back(i + 1);
	}
	vector<int> arr1(arr);
	Solution p;
	//	/*vector<int> arr3(arr);
	//	vector<int> arr4(arr.begin() + 2, arr.begin() + 5);
	//	Solution p;
	//	cout << "arr :";
	//	for (auto i = arr.begin(); i < arr.end(); ++i) {
	//		cout << *i << " ";
	//	}
	//	cout << endl;
	//	cout << "arr1:";
	//	for (vector<int>::iterator i = arr1.begin(); i < arr1.end(); ++i) {
	//		cout << *i << " ";
	//	}
	//	cout << endl;
	//	cout << "arr3:";
	//	for (auto i = arr3.begin(); i < arr3.end(); ++i) {
	//		*i += 1;
	//	}
	//	p.Print_vector_int(arr3);
	//	cout << "arr4:";
	//	for (auto i = arr4.rbegin(); i < arr4.rend(); ++i) {
	//		cout << *i << " ";
	//	}
	//	cout << endl;*/
	//	//p.Print_vector_int(arr4);
	//	//vector<int>::iterator i = arr.erase(arr.begin() + 2, arr.begin() + 4);
	//	//vector<int>::iterator i = arr.insert(arr.begin() + 2, arr1.begin(), arr1.end());
	//	//vector<int>::iterator j = arr.insert(arr.begin() + 2, 3, 10);
	//	//cout << *i << endl;
	//	//swap(arr, arr1);
	//	//arr.swap(arr1);
	//	//arr.erase(arr.begin());

	/*cout << arr.size() << endl;
	cout << arr.capacity() << endl;
	arr.reserve(15);
	cout << arr.size() << endl;
	cout << arr.capacity() << endl;
	arr.resize(20, -1);
	cout << arr.size() << endl;
	cout << arr.capacity() << endl;
	p.Print_vector_int(arr);
	arr.empty() ? cout << "空\n" : cout << "不为空\n";
	arr.clear();
	arr.empty() ? cout << "空\n" : cout << "不为空\n";*/

	/*cout << arr.size() << endl;
	cout << arr.capacity() << endl;
	arr.push_back(11);
	p.Print_vector_int(arr);
	cout << arr.size() << endl;
	cout << arr.capacity() << endl;
	arr.pop_back();
	p.Print_vector_int(arr);
	cout << arr.size() << endl;
	cout << arr.capacity() << endl;
	arr.resize(11);
	arr[10] = 11;
	p.Print_vector_int(arr);
	arr.insert(arr.begin() + 2, -10);
	arr.insert(arr.begin() + 6, 3, -11);
	arr.insert(arr.begin() + 9, arr1.begin(), arr1.begin() + 5);
	p.Print_vector_int(arr);
	arr.erase(arr.begin() + 2);
	arr.erase(arr.begin() + 5, arr.begin() + 13);
	p.Print_vector_int(arr);
	vector<int>::iterator i = find(arr.begin(), arr.end(), 12);
	i >= arr.begin() && i < arr.end() ? cout << "找到了!" << *i << endl : cout << "没找到\n";
	i = find(arr.begin(), arr.end(), 10);
	i >= arr.begin() && i < arr.end() ? cout << "找到了!" << *i << endl : cout << "没找到\n";*/
	vector<int>::iterator i = arr.begin() + 3;
	cout << *i << endl;
	i = arr.insert(i, 20, 0);
	cout << *i << endl;
	system("pause");
	return 0;
}
