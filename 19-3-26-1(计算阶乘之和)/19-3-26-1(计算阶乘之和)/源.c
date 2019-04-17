#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int fun(int x) {
	int Sn = 0;
	int S;
	for (int i = 1; i <= x; ++i) {
		S = 1;
		for (int j = 1; j <= i; ++j) {
			S *= j;
		}
		Sn += S;
	}
	return Sn;
}
void main() {
	int n;
	printf("您需要1到多少的阶乘之和，请输入（此值请小于26）\n");
	scanf("%d", &n);
	printf("数字1到数字%d各阶乘之和为%d\n", n, fun(n));
	system("pause");
}