#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void fun(int x,int y,int z)
	{
	if (x > y&&x > z)
		printf("������Ϊ%d\n", x);
	else if(y>x&&y>z)
		printf("������Ϊ%d\n", y);
	else
		printf("������Ϊ%d\n", z);
	}
int main()
{
	int a, b, c;
	printf("��������������ֵ");
	scanf("%d %d %d", &a ,&b, &c);
	fun(a, b, c);
	system("pause");
	return 0;
}
