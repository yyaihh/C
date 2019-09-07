#include "Date.h"

Date::Date(int y, int m, int d) {
	m_year = y;
	m_month = m;
	m_day = d;
}
bool Date::LeapYear(int y) {
	return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}
Date Date::ComputationTime(int n) {
	//Date a(year, month, day);
	int year = m_year;
	int month = m_month;
	int day = m_day;
	int m;
	for (LeapYear(year) ? m = 365 : m = 366; n >= m; n -= m, ++year) {
		LeapYear(year) ? m = 365 : m = 366;
	}
	LeapYear(year) ? m_s_month[1] = 29 : m_s_month[1] = 28;
	while (1) { 
		for (; n > 0 && day < m_s_month[month - 1]; ++day, --n);
		if (n == 0) {
			Date a(year, month, day);
			return a;
		}
		if (month == 12) {
			month = 1;
			++year;
			LeapYear(year) ? m_s_month[1] = 29 : m_s_month[1] = 28;
		}
		else {
			++month;
		}
		day = 0;
	}
}
Date::~Date() {
}
int Date::m_s_month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
ostream& operator<<(ostream& _cout, Date& a) {
	cout << a.m_year << "��" << a.m_month << "��" << a.m_day << "��";
	return _cout;
}
void input(int& y, int& m, int& d) {
	printf("���������\n");
	while (1) {
		cin >> y;
		if (y >= 0) {
			break;
		}
		cout << "��ݱ���Ǹ�,�������������\n";
	}
	cout << "�������·�\n";
	while (1) {
		cin >> m;
		if (m < 1) {
			cout << "�·ݱ������0, ����������\n";
			continue;
		}
		if (m > 12) {
			cout << "�·ݱ���С�ڵ���12, ����������\n";
			continue;
		}
		break;
	}
	cout << "��������\n";
	while (1) {
		cin >> d;
		if (d < 1) {
			cout << "���������0������\n";
			continue;
		}
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
			if (d > 31) {
				cout << "���������������" << m << "������,����������\n";
				continue;
			}
			break;
		}
		else if (m == 2) {
			if ((y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) && d > 29) {
				cout << "���������������" << m << "������,����������\n";
				continue;
			}
			if (!(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) && d > 28) {
				cout << "���������������" << m << "������,����������\n";
				continue;
			}
			break;
		}
		else {
			if (d > 30) {
				cout << "���������������" << m << "������,����������\n";
				continue;
			}
			break;
		}
	}
}


