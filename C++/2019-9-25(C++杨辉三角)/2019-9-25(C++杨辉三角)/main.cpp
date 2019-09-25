#include<iostream>
#include"Solution.h"
using namespace std;

int main() {
	Solution fun;
	for (auto i : fun.generate(33)) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}