#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int leap_year(int year) {//判断是否为闰年
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
		return 1;//是闰年返回1
	}
	return 0;//不是返回0
}
int fun(int year, int month, int day) {
	int count = 0;
	int Month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };//12月各月天数
	Month[1] += leap_year(year);//如果这一年是闰年则二月+1为29天,不是闰年则+0还是28天
	for (int i = 0; i < month - 1; ++i) {//循环相加该天所在月份之前的所有月份天数之和
		count += Month[i];
	}
	count += day;//加上还不到整一月的天数
	return count;
}
void main() {
	int year, month, day;
	printf("请输入年份\n");
	while (1) {
		scanf("%d", &year);
		if (year >= 0) {
			break;
		}
		printf("年份必须非负,请重新输入年份\n");
	}
	printf("请输入月份\n");
	while (1) {
		scanf("%d", &month);
		if (month < 1){
			printf("月份必须大于0\n");
			continue;
		}
		if(month>12) {
		printf("月份必须小于等于12\n");
		continue;
		}
		break;
	}
	printf("请输入日\n");
	while (1) {
		scanf("%d", &day);
		if (day < 1) {
			printf("请输入大于0的天数\n");
			continue;
		}
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day > 31) {
				printf("您输入的天数大于%d月天数,请重新输入\n", month);
				continue;
			}
			break;
		}
		else if (month == 2) {
			if (leap_year(year) == 1 && day > 29) {
				printf("您输入的天数大于%d月天数,请重新输入\n", month);
				continue;
			}
			if (leap_year(year) == 0 && day > 28) {
				printf("您输入的天数大于%d月天数,请重新输入\n", month);
				continue;
			}
			break;
		}
		else {
			if (day > 30) {
				printf("您输入的天数大于%d月天数,请重新输入\n", month);
				continue;
			}
			break;
		}
	}
	printf("%d年%d月%d日是该年的第%d天\n", year, month, day, fun(year, month, day));
	system("pause");
}