#include"Date.h"

int main() {
	Date a, b, c;
	cin >> a;
	cin >> b;
	c = b;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "c:" << c << endl;
	a > b ? cout << a << ">" << b << endl : cout << a << "<=" << b << endl;
	a < b ? cout << a << "<" << b << endl : cout << a << ">=" << b << endl;
	a >= b ? cout << a << ">=" << b << endl : cout << a << "<" << b << endl;
	a <= b ? cout << a << "<=" << b << endl : cout << a << ">" << b << endl;
	b == c ? cout << b << "==" << c << endl : cout << b << "!=" << c << endl;
	b != c ? cout << b << "!=" << c << endl : cout << b << "==" << c << endl;
	cout << a++ << endl;
	cout << a << endl;
	cout << ++a << endl;
	cout << a-- << endl;
	cout << a << endl;
	cout << --a << endl;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "c:" << c << endl;
	cout << a - b;
	system("pause");
	return 0;
}