#include"Date.h"
int main() {
	int y, m, d, n;
	input(y, m, d);
	Date a(y, m, d);
	cout << "����֪��������������,������\n";
	cin >> n;
	cout << a << endl;
	cout << "��" << n << "�����";
	Date b = a.ComputationTime(n);
	Date c = a;
	cout << b << endl;
	system("pause");
	return 0;
}