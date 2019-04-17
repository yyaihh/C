#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void fun(int x,int y,int z)
	{
	if (x > y&&x > z)
		printf("最大的数为%d\n", x);
	else if(y>x&&y>z)
		printf("最大的数为%d\n", y);
	else
		printf("最大的数为%d\n", z);
	}
int main()
{
	int a, b, c;
	printf("请输入三个整数值");
	scanf("%d %d %d", &a ,&b, &c);
	fun(a, b, c);
	system("pause");
	return 0;
}
