#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a;
	printf("��������Ҫ�жϵ���\n");
	scanf("%d", &a);
	if (a % 3 == 0 && a % 5 == 0)
		printf("%d����ͬʱ��3��5����\n",a);
	else
		printf("%d������ͬʱ��3��5����\n",a);
	system("pause");

}