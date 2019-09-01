#pragma once
#include<iostream>
using namespace std;
class Date {
	static int m_s_data[12];
	int m_year;
	int m_month;
	int m_day;
public:
	Date(int y, int m, int d);
	void print();
	void ComputationTime(int n);
	bool LeapYear(int y);
	~Date();
};

