#include<iostream>
using namespace std;
#define N 4
#define M 4
int main() {
	int a[N][M] = {
		{1,2,8,9},
		{2,4,9,12},
		{4,7,10,13},
		{6,8,11,15}
	};
	int num;
	int i = 0;
	int j = M - 1;
	cout << "请输入需要查找的数\n";
	cin >> num;
	while (i < N && j >= 0) {
		for (; j >= 0 && a[i][j] > num; --j);
		for (; i < N && a[i][j] < num; ++i);
		if (num == a[i][j]) {
			break;
		}
	}
	if (i < N && j >= 0 && a[i][j]==num) {
		cout << "找到了!坐标是" << i << "  " << j << endl;
	}
	else {
		cout << "没找到!\n";
	}
	system("pause");
	return 0;
}