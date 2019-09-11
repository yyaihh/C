#include"Date.h"
int Date::m_s_months[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int Date::getMonthDay(int y, size_t n) {
	return m_s_months[n-1]+ (n == 2 && (y % 400 == 0 || (y % 4 == 0 && y % 100)));
}
Date& Date::operator=(const Date& t) {
	if (this != &t) {
		m_year = t.m_year;
		m_month = t.m_month;
		m_day = t.m_day;
	}
	return *this;
}
ostream& operator<<(ostream& os, const Date& t) {
	cout << t.m_year << "年" << t.m_month << "月" << t.m_day << "日";
	return os;
}
istream& operator>>(istream& os, Date& t) {
	cout << "请依次输入年月日\n";
	cin >> t.m_year >> t.m_month >> t.m_day;
	return os;
}
bool Date::operator<(const Date& t)const {
	if (this == &t) {
		return false;
	}
	if (m_year < t.m_year) {
		return true;
	}
	if (m_year == t.m_year && m_month < t.m_month) {
		return true;
	}
	if (m_month == t.m_month && m_day < t.m_day) { 
		return true;
	}
	return false;
}
bool Date::operator>(const Date& t)const {
	if (this == &t) {
		return false;
	}
	if (m_year > t.m_year) {
		return true;
	}
	if (m_year == t.m_year && m_month > t.m_month) {
		return true;
	}
	if (m_month == t.m_month && m_day > t.m_day) {
		return true;
	}
	return false;
}
bool Date::operator!=(const Date& t)const {
	if (this == &t) {
		return false;
	}
	return (m_year != t.m_year) || (m_month != t.m_month) || (m_day != t.m_day);
	//或者
	//return !(*this == t);
}
bool Date::operator==(const Date& t)const {
	if (this == &t) {
		return true;
	}
	return (m_year == t.m_year) && (m_month == t.m_month) && (m_day == t.m_day);
	//或者
	//return !(*this != t);
}
bool Date::operator<=(const Date& t)const {
	if (this == &t) {
		return true;
	}
	if (m_year > t.m_year) {
		return false;
	}
	else if (m_year == t.m_year && m_month > t.m_month) {
		return false;
		if (m_month == t.m_month && m_day > t.m_day) {
			return false;
		}
	}
	return true;
	//或者
	//return *this == t || *this < t;
}
bool Date::operator>=(const Date& t)const {
	if (this == &t) {
		return true;
	}
	if (m_year < t.m_year) {
		return false;
	}
	else if (m_year == t.m_year && m_month < t.m_month) {
		return false;
		if (m_month == t.m_month && m_day < t.m_day) {
			return false;
		}
	}
	return true;
	//或者
	//return *this == t || *this > t;
}
Date& Date::operator++() {
	if (m_day == getMonthDay(m_year, m_month)) {
		m_day = 1;
		m_month == 12 ? m_month = 1, ++m_year : ++m_month;
	}
	else {
		++m_day;
	}
	return *this;
}
Date& Date::operator--() {
	if (m_day == 1) {
		m_month == 1 ? m_month = 12, --m_year : --m_month;
		m_day = getMonthDay(m_year, m_month);
	}
	else {
		--m_day;
	}
	return *this;
}
Date Date::operator++(int) {
	Date tmp = *this;
	if (m_day == getMonthDay(m_year, m_month)) {
		m_day = 1;
		m_month == 12 ? m_month = 1, ++m_year : ++m_month;
	}
	else {
		++m_day;
	}
	return tmp;
}
Date Date::operator--(int) {
	Date tmp = *this;
	if (m_day == 1) {
		m_month == 1 ? m_month = 12, --m_year : --m_month;
		m_day = getMonthDay(m_year, m_month);
	}
	else {
		--m_day;
	}
	return tmp;
}
bool Date::LeapYear(int year) const{
	return year % 400 == 0 || (year % 4 == 0 && year % 100);
}
Date& Date::operator+=(size_t n) {
	size_t count = 0;
	for (int i = 1; i < (int)m_month; ++i) {
		count += getMonthDay(m_year, i);
	}
	count += m_day;
	if (n >= (365 + LeapYear(m_year) - count)) { 
		n -= (365 + LeapYear(m_year) - count);
		--n;
		m_month = 1;
		m_day = 1;
		++m_year;
		while ((int)n > (365 + LeapYear(m_year))) {
			n -= (365 + LeapYear(m_year++));
		}
	}
	for (;n > 0; --n) {
		if (m_day == getMonthDay(m_year, m_month)) {
			m_day = 1;
			m_month == 12 ? m_month = 1 : ++m_month;
		}
		else {
			++m_day;
		}
	}
	return *this;
}
//Date Date::operator+(size_t n)const {
//
//}
//Date Date::operator-(size_t n)const {
//
//}
//Date& Date::operator-=(size_t n) {
//
//}
int Date::countLeapYear(int year)const {
	int begin = m_year;
	int end = year;
	if (m_year > year) {
		begin = year;
		end = m_year;
	}
	while (!(LeapYear(begin) && begin < end)) {
		++begin;
	}
	return (end - begin) / 4 + (begin <= end);
}
int Date::operator-(const Date& t)const {
	Date mindate = *this;
	Date maxdate = t;
	if (mindate > maxdate) {
		maxdate = *this;
		mindate = t;
	}
	int count = 0;
	if (maxdate.m_year > mindate.m_year) {
		count += countLeapYear(t.m_year) + (maxdate.m_year - mindate.m_year) * 365;
	}
	for (int i = 1; i < (int)mindate.m_month; ++i) {
		count -= getMonthDay(mindate.m_year, i);
	}
	count -= mindate.m_day;

	for (int i = 1; i < (int)maxdate.m_month; ++i) {
		count += getMonthDay(maxdate.m_year, i);
	}
	count += maxdate.m_day;
	return count;
}