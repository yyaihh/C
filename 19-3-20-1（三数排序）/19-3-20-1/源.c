#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a[3];
	int t;
	printf("请输入三个整数\n");
	for(int i=0;i<3;i++)
	scanf("%d",&a[i]);
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < 2; i++)
		{
			if (a[i] <= a[i + 1])
			{
				t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	printf("%d\n", a[i]);
	system("pause");
}
	