#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a;
	printf("请输入需要判断的数\n");
	scanf("%d", &a);
	if (a % 3 == 0 && a % 5 == 0)
		printf("%d可以同时被3和5整数\n",a);
	else
		printf("%d不可以同时被3和5整数\n",a);
	system("pause");

}