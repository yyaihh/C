#pragma once
#include<iostream>
using namespace std;
class Date{
	int m_year;
	size_t m_month;
	size_t m_day;
	static int m_s_months[12];
public:
	Date(int y = 2019, size_t m = 10, size_t d = 1) :
		m_year(y),
		m_month(m),
		m_day(d) 
	{
	}
	static int getMonthDay(int y,size_t n);//返回y年n月的天数
	bool LeapYear(int year)const;
	int countLeapYear(int year)const;
	Date& operator=(const Date& t);
	friend ostream& operator<<(ostream& os, const Date& t);
	friend istream& operator>>(istream& os, Date& t);
	bool operator<(const Date& t)const;
	bool operator>(const Date& t)const;
	bool operator==(const Date& t)const;
	bool operator!=(const Date& t)const;
	bool operator<=(const Date& t)const;
	bool operator>=(const Date& t)const;
	Date& operator+=(size_t n);//计算当前日期+n天的日期值, 再将这个值给自己
	Date operator+(size_t n)const;//n天之后的日期
	Date operator-(size_t n)const;//n天之前的日期
	Date& operator-=(size_t n);//计算当前日期-n天的日期值, 再将这个值给自己
	int operator-(const Date& t)const;//两个日期之间差几天
	Date& operator++();
	Date& operator--();
	Date operator++(int);
	Date operator--(int);
};
