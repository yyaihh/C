#include"Date.h"
int main() {
	int y, m, d, n;
	input(y, m, d);
	Date a(y, m, d);
	cout << "你想知道多少天后的日期,请输入\n";
	cin >> n;
	a.print();
	cout << "在" << n << "天后是";
	Date b = a.ComputationTime(n);
	b.print();
	system("pause");
	return 0;
}