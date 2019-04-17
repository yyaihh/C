#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main() {
	double num ;
	printf("请输入小于1000的正数\n");
	scanf("%lf", &num);
	for (; num >=1000||num<0;) {
		printf("您的输入有误，请重新输入\n");
		scanf("%lf", &num);
	}
	printf("%lf的平方根是%d\n", num, (int)sqrt(num));
		system("pause");
}