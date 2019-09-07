#pragma once
#include<iostream>
using namespace std;
class Date {
	static int m_s_month[12];
	int m_year;
	int m_month;
	int m_day;
public:
	Date(int y, int m, int d);
	friend ostream& operator<<(ostream& _cout, Date& a);
	Date ComputationTime(int n);
	bool LeapYear(int y);
	~Date();
	Date& operator=(const Date& d) {
		m_year = d.m_year;
		m_month = d.m_month;
		m_day = d.m_day;
	}
};
void input(int& y, int& m, int& d);