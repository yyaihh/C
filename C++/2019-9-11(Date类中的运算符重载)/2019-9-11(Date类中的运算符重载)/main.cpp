#include"Date.h"
void test1() {
	Date a;
	Date c;
	Date b;
	cout << "输入a:\n";
	cin >> a;
	cout << "a:" << a << endl;
	cout<< "输入b:\n";
	cin >> b;
	c = b;
	cout << "b:" << b << endl;
	cout << "c:" << c << endl;
	a > b ? cout << a << ">" << b << endl : cout << a << "<=" << b << endl;
	a < b ? cout << a << "<" << b << endl : cout << a << ">=" << b << endl;
	a >= b ? cout << a << ">=" << b << endl : cout << a << "<" << b << endl;
	a <= b ? cout << a << "<=" << b << endl : cout << a << ">" << b << endl;
	b == c ? cout << b << "==" << c << endl : cout << b << "!=" << c << endl;
	a != c ? cout << a << "!=" << c << endl : cout << a << "==" << c << endl;
	system("pause");
	system("cls");
}
void test2() {
	Date a;
	Date b;
	Date c;
	size_t n = 1000000000;
	cout << "输入a\n";
	cin >> a;
	c = a;
	cout << "a:" << a << endl;
	a += n;
	cout << "a:" << a << endl;
	cout << a - c << endl;
	c = a;
	a -= n;
	cout << "a:" << a << endl;
	b = a + n;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	b = b - n;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "a:" << ++a << endl;
	cout << "a:" << a << endl;
	cout << "a:" << a++ << endl;
	cout << "a:" << a << endl;
	cout << "a:" << --a << endl;
	cout << "a:" << a << endl;
	cout << "a:" << a-- << endl;
	cout << "a:" << a << endl;
	cout << "日期a这一年的每个月天数\n";
	for (int i = 1; i <= 12; ++i) {
		cout << i << "月是" << a[i] << "天\n";
	}
}
int main() {
	test1();
	test2();
	system("pause");
	return 0;
}