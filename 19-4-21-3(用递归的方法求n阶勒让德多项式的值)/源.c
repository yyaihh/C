#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
double legendre(int n, int x) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return x;
	}
	return ((2 * n - 1)*x - legendre(n - 1, x) - (n - 1)*legendre(n - 2, x)) / n;
}
void main() {
	int n;
	int x;
	printf("请输入n的值和x的值\n");
	scanf("%d %d", &n, &x);
	printf("P%d(%d) = %f\n", n, x, legendre(n, x));
	system("pause");
}