#include<stdio.h>
#include<stdlib.h>
void fun1(int x,int y)//������ʱ������
{
	int z;
	z = x;
	x = y;
	y = z;
	printf("������ʱ����������a=%d��b=%d\n", x, y);
}
void fun2(int x, int y)//�Ӽ���
{
	x = x + y;
	y = x - y;
	x = x - y;
	printf("���üӼ���������a=%d��b=%d\n", x, y);
}
void fun3(int x, int y)//���
{
	x = x ^ y; 
	y = x ^ y;
	x = x ^ y;
	printf("������������a=%d��b=%d\n", x, y);
}
void main()
{
	int a = 10;
	int b = 20;
	printf("δ����֮ǰa=%d��b=%d\n", a, b);
	fun1(a,b);
	fun2(a,b);
	fun3(a,b);
	system("pause");
}