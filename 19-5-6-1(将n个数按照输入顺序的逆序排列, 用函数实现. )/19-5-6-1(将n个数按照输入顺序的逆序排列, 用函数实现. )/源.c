#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void fun(int n) {
	int num;
	printf("请输入\n");
	scanf("%d", &num);
	if (n != 1) {
		fun(n - 1);
	}
	printf("%d\t", num);
}
void main() {
	int n;
	printf("请输入您需要输入的数字的个数n\n");
	scanf("%d", &n);
	fun(n);
	printf("\n");
	system("pause");
}