#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main() {
	int month;
	char* Month[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	printf("�������·�\n");
	scanf("%d", &month);
	for (; month < 1 || month > 12; printf("������������,����������\n"), scanf("%d", &month));
	printf("%d�µ�Ӣ����Ϊ:%s\n", month, *(Month + month - 1));
	system("pause");
}