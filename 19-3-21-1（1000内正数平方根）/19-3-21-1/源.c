#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main() {
	double num ;
	printf("������С��1000������\n");
	scanf("%lf", &num);
	for (; num >=1000||num<0;) {
		printf("����������������������\n");
		scanf("%lf", &num);
	}
	printf("%lf��ƽ������%d\n", num, (int)sqrt(num));
		system("pause");
}