#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main() {
	double a, x0, x1;
	printf("������a��ֵ\n");
	scanf("%lf", &a);
	x0 = a / 2;
	x1 = (x0 + a / x0) / 2;
	while (fabs(x0 - x1) >= 1e-5) {
		x0 = x1;
		x1 = (x0 + a / x0) / 2;
	}
	printf("����ƽ����Ϊ:%f\n", x1);
	printf("sqrt()�������Ϊ:%f\n", sqrt(a));
	system("pause");
}