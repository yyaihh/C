#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int fun1(int x, int y)//辗转相除法
{
	int z;
	while (z = x % y )
	{
		x = y;
		y = z;
	}
	return y;
}
void fun2(int x, int y)//更相减损术
{
	int z = 0;
	while (x!=y)
	{
		while (x % 2 == 0 && y % 2 == 0)
		{
			x = x / 2;
			y = y / 2;
			z++;
		}
		if (x > y)
			x = x - y;
		if (x < y)
			y = y - x;
	}
	if (z != 0) {
		printf("更相减损术：最大公约数为%d\n", 2*z*x);
	}
	else {
		printf("更相减损术：最大公约数为%d\n", x);
	}
}
//最小公倍数
int fun3(int x, int y, int z) {
	return x * y / z;
}
void main()
{
	int a, b;
	printf("请输入两个整数\n");
	scanf("%d %d", &a, &b);
	printf("辗转相除法：最大公约数是%d\n", fun1(a,b));
	fun2(a, b);//更相减损术
	printf("最小公倍数是%d\n", fun3(a, b, fun1(a, b)));
	system("pause");
}
