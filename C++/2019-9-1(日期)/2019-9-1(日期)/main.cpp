#include"Date.h"
int main() {
	int y, m, d, n;
	input(y, m, d);
	Date a(y, m, d);
	cout << "����֪��������������,������\n";
	cin >> n;
	a.print();
	cout << "��" << n << "�����";
	Date b = a.ComputationTime(n);
	b.print();
	system("pause");
	return 0;
}