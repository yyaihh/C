#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void fun(int n) {
	int num;
	printf("������\n");
	scanf("%d", &num);
	if (n != 1) {
		fun(n - 1);
	}
	printf("%d\t", num);
}
void main() {
	int n;
	printf("����������Ҫ��������ֵĸ���n\n");
	scanf("%d", &n);
	fun(n);
	printf("\n");
	system("pause");
}