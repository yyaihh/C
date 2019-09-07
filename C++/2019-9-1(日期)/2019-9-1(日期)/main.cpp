#include"Date.h"
int main() {
	int y, m, d, n;
	input(y, m, d);
	Date a(y, m, d);
	cout << "你想知道多少天后的日期,请输入\n";
	cin >> n;
	cout << a << endl;
	cout << "在" << n << "天后是";
	Date b = a.ComputationTime(n);
	Date c = a;
	cout << b << endl;
	system("pause");
	return 0;
}