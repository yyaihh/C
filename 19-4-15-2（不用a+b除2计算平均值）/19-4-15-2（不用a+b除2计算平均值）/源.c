#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main() {
	int a, b;
	printf("������a��b��ֵ\n");
	scanf("%d %d", &a, &b);
	printf("����һ:(a + b) / 2 = %d\n", (a + b) >> 1);//�����������
	printf("������:(a + b) / 2 = %d\n", ((a - b) >> 1) + b);//(b����b��a��Ĳ��ֵ�һ��)(a-b)/2+b=>((a-b)>>1)+b���������������
	printf("������:(a + b) / 2 = %d\n", (a & b) + ((a ^ b) >> 1));//�뷽�������ƣ��ҳ�a��b����ͬ�Ĳ��֣�a & b�����ټ��ϲ�ͬ���ֵ�һ�루a ^ b��>>1(���������)
	system("pause");
}