#include"Class.h"

int main() {
	int n;
	cout << "�������Ʒ������\n";
	cin >> n;
	Class::input(n);//����ԭ��, �������ԭ�����µ���
	Class a(n);
	int m = a.count(n);
	cout << "�����۸�Ϊ:" << m << endl;
	Class::m();
	system("pause");
	return 0;
}