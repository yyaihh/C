#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main() {
	double a, x0, x1;
	printf("请输入a的值\n");
	scanf("%lf", &a);
	x0 = a / 2;
	x1 = (x0 + a / x0) / 2;
	while (fabs(x0 - x1) >= 1e-5) {
		x0 = x1;
		x1 = (x0 + a / x0) / 2;
	}
	printf("算术平方根为:%f\n", x1);
	printf("sqrt()函数求得为:%f\n", sqrt(a));
	system("pause");
}