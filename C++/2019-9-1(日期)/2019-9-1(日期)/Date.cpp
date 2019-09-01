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
void Date::ComputationTime(int n) {
	int year = m_year;
	int month = m_month;
	int day = m_day;
	bool flag;
	for (; n > 0; ++month) {
		if (month == 13) {
			++year;
			month = 1;
			flag = LeapYear(year) ? m_s_data[1] = 29 : m_s_data[1] = 28;
		}
		for (; n > 0 && day < m_s_data[month - 1] ? ++day : day = 0; --n);
	}
	cout << "之后是" << year << "年" << month << "月" << day << "日\n";
}
Date::~Date() {
}
int Date::m_s_data[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

