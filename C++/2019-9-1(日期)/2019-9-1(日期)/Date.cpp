#include "Date.h"

Date::Date(int y, int m, int d) {
	m_year = y;
	m_month = m;
	m_day = d;
}
void Date::print() {
	cout << m_year << "年" << m_month << "月" << m_day << "日\n";
}
bool Date::LeapYear(int y) {
	return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}
Date Date::ComputationTime(int n) {
	int year = m_year;
	int month = m_month;
	int day = m_day;
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

void input(int& y, int& m, int& d) {
	printf("请输入年份\n");
	while (1) {
		cin >> y;
		if (y >= 0) {
			break;
		}
		cout << "年份必须非负,请重新输入年份\n";
	}
	cout << "请输入月份\n";
	while (1) {
		cin >> m;
		if (m < 1) {
			cout << "月份必须大于0, 请重新输入\n";
			continue;
		}
		if (m > 12) {
			cout << "月份必须小于等于12, 请重新输入\n";
			continue;
		}
		break;
	}
	cout << "请输入日\n";
	while (1) {
		cin >> d;
		if (d < 1) {
			cout << "请输入大于0的天数\n";
			continue;
		}
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
			if (d > 31) {
				cout << "您输入的天数大于" << m << "月天数,请重新输入\n";
				continue;
			}
			break;
		}
		else if (m == 2) {
			if ((y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) && d > 29) {
				cout << "您输入的天数大于" << m << "月天数,请重新输入\n";
				continue;
			}
			if (!(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) && d > 28) {
				cout << "您输入的天数大于" << m << "月天数,请重新输入\n";
				continue;
			}
			break;
		}
		else {
			if (d > 30) {
				cout << "您输入的天数大于" << m << "月天数,请重新输入\n";
				continue;
			}
			break;
		}
	}
}


