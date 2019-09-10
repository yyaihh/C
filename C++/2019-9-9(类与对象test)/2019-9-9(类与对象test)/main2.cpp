//#include<iostream>
//using namespace std;
//class B {
//public:
//	int m_c;
//	B(int c = 0) :m_c(c) { 
//	
//	}
//};
//class A {
//	int m_a = 10;
//	B m_b = 20;
//	int* m_p = (int*)malloc(4);
//	static int m_s_n;
//public:
//	void PrintA();
//};
//int A::m_s_n = 0;
//void A::PrintA() {
//	cout << m_a << endl;
//	cout << m_b.m_c << endl;
//	cout << m_p << endl;
//	cout << m_s_n << endl;
//}
//int main() {
//	A a;
//	a.PrintA();
//	system("pause");
//	return 0;
//}
#include<iostream>
using namespace std;
class Time{
	int m_hour;
	int m_minute;
	int m_second;
public:
	class Date {
		int m_year;
		int m_month;
		int m_day;
	public:
		Date(int year = 1900, int month = 1, int day = 1)
			: m_year(year)
			, m_month(month)
			, m_day(day)
		{}
		void SetTimeOfDate(Time& t, int hour, int minute, int second);
		void PrintDate(const Time& t);
	};
	Time(int hour = 12, int minute = 1, int second = 1)
		: m_hour(hour)
		, m_minute(minute)
		, m_second(second)
	{}
	void PrintTime(const Time& t)const;
};
void Time::PrintTime(const Time& t) const {
	cout << m_hour << "时" << m_minute << "分" << m_second << "秒\n";
}
void Time::Date::SetTimeOfDate(Time& t, int hour, int minute, int second) {
	// 直接访问时间类私有的成员变量
	t.m_hour = hour;
	t.m_minute = minute;
	t.m_second = second;
}
void Time::Date::PrintDate(const Time& t) {
	cout << m_year << "年" << m_month << "月" << m_day << "日";
	t.PrintTime(t);
}
int main() {
	Time::Date d(2019, 10, 1);
	Time t;
	d.SetTimeOfDate(t, 11, 11, 11);
	d.PrintDate(t);
	system("pause");
	return 0;
}