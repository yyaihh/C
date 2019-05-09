#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct day {
	int year;
	int month;
	int day;
};
typedef struct day day;
int leap_year(int year) {//判断是否为闰年
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
		return 1;//是闰年返回1
	}
	return 0;//不是返回0
}
int fun(day* p) {
	int count = 0;
	int Month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };//12月各月天数
	Month[1] += leap_year(p->year);//如果这一年是闰年则二月+1为29天,不是闰年则+0还是28天
	for (int i = 0; i < p->month - 1; ++i) {//循环相加该天所在月份之前的所有月份天数之和
		count += Month[i];
	}
	count += p->day;//加上还不到整一月的天数
	return count;
}
void main() {
	day d;
	day* p = &d;
	printf("请输入年份\n");
	while (1) {
		scanf("%d", &d.year);
		if (d.year >= 0) {
			break;
		}
		printf("年份必须非负,请重新输入年份\n");
	}
	printf("请输入月份\n");
	while (1) {
		scanf("%d", &d.month);
		if (d.month < 1) {
			printf("月份必须大于0\n");
			continue;
		}
		if (d.month > 12) {
			printf("月份必须小于等于12\n");
			continue;
		}
		break;
	}
	printf("请输入日\n");
	while (1) {
		scanf("%d", &d.day);
		if (d.day < 1) {
			printf("请输入大于0的天数\n");
			continue;
		}
		if (d.month == 1 || d.month == 3 || d.month == 5 || d.month == 7 || d.month == 8 || d.month == 10 || d.month == 12) {
			if (d.day > 31) {
				printf("您输入的天数大于%d月天数,请重新输入\n", d.month);
				continue;
			}
			break;
		}
		else if (d.month == 2) {
			if (leap_year(d.year) == 1 && d.day > 29) {
				printf("您输入的天数大于%d月天数,请重新输入\n", d.month);
				continue;
			}
			if (leap_year(d.year) == 0 && d.day > 28) {
				printf("您输入的天数大于%d月天数,请重新输入\n", d.month);
				continue;
			}
			break;
		}
		else {
			if (d.day > 30) {
				printf("您输入的天数大于%d月天数,请重新输入\n", d.month);
				continue;
			}
			break;
		}
	}
	printf("%d年%d月%d日是该年的第%d天\n", d.year, d.month, d.day, fun(p));
	system("pause");
}
