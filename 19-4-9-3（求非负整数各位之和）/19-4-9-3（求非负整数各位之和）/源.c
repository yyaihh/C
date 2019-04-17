#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int sum = 0;
int DigitSum(int n){
	if (n == 0) {
		return 0;
	}
	else {
		return n % 10 + DigitSum(n / 10);
	}
}
void main() {
	int n;
	printf("请输入非负整数\n");
	scanf("%d", &n);
	while (n < 0) {
		printf("您的输入非法\n");
		scanf("%d", &n);
	}
	printf("%d\n", DigitSum(n));
	system("pause");
}