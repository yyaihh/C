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
	os << t.m_year << "年" << t.m_month << "月" << t.m_day << "日";
	return os;
}
istream& operator>>(istream& os, Date& t) {
	printf("请输入年份\n");
	while (1) {
		os >> t.m_year;
		if (t.m_year >= 0) {
			break;
		}
		cout << "年份必须非负,请重新输入年份\n";
	}
	cout << "请输入月份\n";
	while (1) {
		os >> t.m_month;
		if (t.m_month < 1) {
			cout << "月份必须大于0, 请重新输入\n";
			continue;
		}
		if (t.m_month > 12) {
			cout << "月份必须小于等于12, 请重新输入\n";
			continue;
		}
		break;
	}
	cout << "请输入日\n";
	while (1) {
		os >> t.m_day;
		if (t.m_day < 1) {
			cout << "请输入大于0的天数\n";
			continue;
		}
		if (t.m_day > Date::getMonthDay(t.m_year,t.m_month)) {
			cout << "你输入的号数大于本月天数" << Date::getMonthDay(t.m_year, t.m_month) << "请重新输入\n";
			continue;
		}
		break;
	}
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
		m_month = 12;
		m_day = 31;
		while ((int)n >= (365 + LeapYear(m_year + 1))) {
			n -= (365 + LeapYear(++m_year));
		}
	}
	for (;n > 0; --n) {
		if (m_day == getMonthDay(m_year, m_month)) {
			m_day = 1;
			m_month == 12 ? m_month = 1, ++m_year: ++m_month;
		}
		else {
			++m_day;
		}
	}
	return *this;
}
Date Date::operator+(size_t n)const {
	Date tmp = *this;
	size_t count = 0;
	for (int i = 1; i < (int)tmp.m_month; ++i) {
		count += getMonthDay(tmp.m_year, i);
	}
	count += tmp.m_day;
	if (n >= (365 + LeapYear(tmp.m_year) - count)) {
		n -= (365 + LeapYear(tmp.m_year) - count);
		tmp.m_month = 12;
		tmp.m_day = 31;
		while ((int)n >= (365 + LeapYear(tmp.m_year + 1))) {
			n -= (365 + LeapYear(++tmp.m_year));
		}
	}
	for (; n > 0; --n) {
		if (tmp.m_day == getMonthDay(tmp.m_year, tmp.m_month)) {
			tmp.m_day = 1;
			tmp.m_month == 12 ? tmp.m_month = 1, ++tmp.m_year : ++tmp.m_month;
		}
		else {
			++tmp.m_day;
		}
	}
	return tmp;
}
Date Date::operator-(size_t n)const {
	Date tmp = *this;
	size_t count = 0;
	for (int i = 1; i < (int)tmp.m_month; ++i) {
		count += getMonthDay(tmp.m_year, i);
	}
	count += m_day;
	if (n >= count) {
		n -= count;
		tmp.m_month = 12;
		tmp.m_day = 31;
		--tmp.m_year;
		while ((int)n >= (365 + LeapYear(tmp.m_year))) {
			n -= (365 + LeapYear(tmp.m_year--));
		}
	}
	for (; n > 0; --n) {
		if (tmp.m_day == 1) {
			if (tmp.m_month == 1) {
				tmp.m_day = getMonthDay(--tmp.m_year, 12);
			}
			else {
				tmp.m_day = getMonthDay(tmp.m_year, --tmp.m_month);
			}
		}
		else {
			--tmp.m_day;
		}
	}
	return tmp;
}
Date& Date::operator-=(size_t n) {
	size_t count = 0;
	for (int i = 1; i < (int)m_month; ++i) {
		count += getMonthDay(m_year, i);
	}
	count += m_day;
	if (n >= count) {
		n -= count;
		m_month = 12;
		m_day = 31;
		--m_year;
		while ((int)n >= (365 + LeapYear(m_year))) {
			n -= (365 + LeapYear(m_year--));
		}
	}
	for (; n > 0; --n) {
		if (m_day == 1) {
			if (m_month == 1) {
				m_day = getMonthDay(--m_year, 12);
			}
			else {
				m_day = getMonthDay(m_year, --m_month);
			}
		}
		else {
			--m_day;
		}
	}
	return *this;
}
int Date::countLeapYear(int year)const {
	if (m_year == year) {
		return LeapYear(year);
	}
	int begin = m_year;
	int end = year - 1;
	if (m_year > year) {
		begin = year;
		end = m_year - 1;
	}
	while (!(LeapYear(begin))) {
		++begin;
	}
	while (!(LeapYear(end))) {
		--end;
	}
	int tmp = begin;
	int count = 0;
	if (begin <= end) {
		while (tmp <= end && tmp % 100) { 
			++tmp;;
		}
		for (; tmp <= end; !LeapYear(tmp) ? ++count : count, tmp += 100);
		return (end - begin) / 4 + 1 - count;
	}
	return 0;
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