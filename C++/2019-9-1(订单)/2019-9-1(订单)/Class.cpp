#include "Class.h"

Class::Class(int n) {
	m_size = 0;
}

int Class::count(int n) {
	int sum = 0;
	int m = 0;
	cout << "������۸�ϵ��\n";
	cin >> m;
	for (int i = 0; i < n; ++i) {
		cout << "�������Ʒ" << i + 1 << "������\n";
		cin >> m_size;
		sum += m_size * m_OriginalCost[i] * m;
	}
	return sum;
}
void Class::input(int n) {
	if (m_OriginalCost == nullptr) { 
		m_OriginalCost = new int[n];
	}
	for (int i = 0; i < n; ++i) {
		cout << "�������Ʒ" << i + 1 << "��ԭ��\n";
		cin >> m_OriginalCost[i];
	}
}
void Class::m() {
	delete m_OriginalCost;
}
Class::~Class() {
}
int* Class::m_OriginalCost = nullptr;