#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void HEX_DEC(int num, int N) {
	if (num > N - 1) {
		HEX_DEC(num / N, N);
	}
	printf("%d", num % N);
}
void main() {
	int num;
	printf("输入一个十六进制的数\n");
	scanf("%x", &num);
	printf("直接用%%d输出:%d\n", num);
	printf("用函数输出:");
	HEX_DEC(num, 10);//转换成几进制就把第二个参数换成几
	printf("\n");
	system("pause");
}