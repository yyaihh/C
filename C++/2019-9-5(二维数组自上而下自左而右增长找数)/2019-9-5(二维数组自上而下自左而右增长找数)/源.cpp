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
	int i, j;
	i = j = 0;
	cout << "请输入需要查找的数\n";
	cin >> num;
	while (1) {
		if (a[i][j] < num) {
			++j;
		}
		else if (a[i][j] > num) {
			++i
		}
	}
	system("pause");
	return 0;
}