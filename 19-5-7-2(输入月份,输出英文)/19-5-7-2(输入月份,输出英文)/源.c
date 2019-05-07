#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main() {
	int month;
	char* Month[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	printf("请输入月份\n");
	scanf("%d", &month);
	for (; month < 1 || month > 12; printf("您的输入有误,请重新输入\n"), scanf("%d", &month));
	printf("%d月的英文名为:%s\n", month, *(Month + month - 1));
	system("pause");
}