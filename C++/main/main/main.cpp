#include<iostream>
using namespace std;
int main() {
	int a;
	cin >> a;
	while (a < 1 || a>1000000) {
		cin >> a;
	}
	int c = 0;
	int d = 1;
	int e ;
	int count = 0;
	bool flag = false;
	/*if (a == 1) {
		cout << count << endl;
		system("pause");
		return 0;
	}*/
	while(1) {
		e = c + d;
		if (a >= d && a <= e) {
			for (int i = a, j = a;; ++i, --j) {
				if (i == d || j == d|| i==e || j==e) {
					flag = true;
					break;
				}
				else {
					++count;
				}
			}
		}
		if (flag) {
			break;
		}
		c = d;
		d = e;
	}
	unsigned char ch = 255;
	ch = ch + 1;
	cout << (int)ch;
	cout << count << endl;
	system("pause");
	return 0;
}