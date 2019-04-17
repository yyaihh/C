#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[10];
	int max;
	printf("请依次输入十个整数\n");
	for (int j = 0; j < 10; j++)
		scanf("%d", &a[j]);
	max = a[0];
	for(int i=0;i<10;i++)
		max= (a[i] > max) ? a[i] : max;
	printf("最大的数为%d\n",max);
	system("pause");
	return 0;
}