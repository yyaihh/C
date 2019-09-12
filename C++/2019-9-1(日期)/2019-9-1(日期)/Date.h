#pragma once
#include<iostream>
using namespace std;
class Date {
	static int m_s_month[12];
	int m_year;
	int m_month;
	int m_day;
public:
	Date(int y = 0, int m = 0, int d = 0) {
		m_year = y;
		m_month = m;
		m_day = d;
	}
	friend ostream& operator<<(ostream& os, Date& a);
	friend istream& operator>>(istream& os, Date& a);
	static int getMonthDay(int y, size_t n);//返回y年n月的天数
	bool LeapYear(int year)const;
	int countLeapYear(int year)const;
	Date operator+(size_t n)const;
};