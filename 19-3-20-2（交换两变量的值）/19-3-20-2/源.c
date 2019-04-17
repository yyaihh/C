#include<stdio.h>
#include<stdlib.h>
void fun1(int x,int y)//创建临时变量法
{
	int z;
	z = x;
	x = y;
	y = z;
	printf("创建临时变量交换后a=%d，b=%d\n", x, y);
}
void fun2(int x, int y)//加减法
{
	x = x + y;
	y = x - y;
	x = x - y;
	printf("利用加减法交换后a=%d，b=%d\n", x, y);
}
void fun3(int x, int y)//异或法
{
	x = x ^ y; 
	y = x ^ y;
	x = x ^ y;
	printf("利用异或运算后a=%d，b=%d\n", x, y);
}
void main()
{
	int a = 10;
	int b = 20;
	printf("未交换之前a=%d，b=%d\n", a, b);
	fun1(a,b);
	fun2(a,b);
	fun3(a,b);
	system("pause");
}