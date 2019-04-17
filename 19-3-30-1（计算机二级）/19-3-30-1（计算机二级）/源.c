#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
double fun(int n) {
	int i;
	double sum = 0;
	for (i = 1; i <= n; i++) {
		if (i % 5 == 0 || i % 9 == 0) {
			sum += 1 / (double)i;
		}
	}
	return sum;
}
void _main() {
	int n;
	printf("请输入n的值\n");
	scanf("%d", &n);
	while (n < 0 || n>100) {
		printf("请重新输入\n");
		scanf("%d", &n);
	}
	printf("%lf", fun(n));
	system("pause");
}