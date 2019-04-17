#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int factorial_1(int n) {
	if (n == 1) {
		return 1;
	}
	return n * factorial_1(n - 1);
}
int factorial_2(int n) {
	int num = 1;
	for (int i = 1; i <= n; ++i) {
		num *= i;
	}
	return num;
}
void main() {
	int n;
	printf("请输入n的值\n");
	scanf("%d", &n);
	printf("递归求得阶乘为:%d\n", factorial_1(n));
	printf("非递归求得阶乘为:%d\n", factorial_2(n));
	system("pause");
}