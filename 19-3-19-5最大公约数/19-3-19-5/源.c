#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int fun1(int x, int y)//շת�����
{
	int z;
	while (z = x % y )
	{
		x = y;
		y = z;
	}
	return y;
}
void fun2(int x, int y)//���������
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
		printf("��������������Լ��Ϊ%d\n", 2*z*x);
	}
	else {
		printf("��������������Լ��Ϊ%d\n", x);
	}
}
//��С������
int fun3(int x, int y, int z) {
	return x * y / z;
}
void main()
{
	int a, b;
	printf("��������������\n");
	scanf("%d %d", &a, &b);
	printf("շת����������Լ����%d\n", fun1(a,b));
	fun2(a, b);//���������
	printf("��С��������%d\n", fun3(a, b, fun1(a, b)));
	system("pause");
}
