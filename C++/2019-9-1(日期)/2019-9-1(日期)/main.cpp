#include"Date.h"
int main() {
	int n;
	Date a, b;
	cout << "请输入日期\n";
	cin >> a;
	cout << "你想知道多少天后的日期,请输入\n";
	cin >> n;
	b = a + n;
	cout << a << endl;
	cout << "在" << n << "天后是";
	cout << b << endl;
	system("pause");
	return 0;
}