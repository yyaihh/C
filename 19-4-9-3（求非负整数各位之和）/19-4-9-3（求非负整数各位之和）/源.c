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
	printf("������Ǹ�����\n");
	scanf("%d", &n);
	while (n < 0) {
		printf("��������Ƿ�\n");
		scanf("%d", &n);
	}
	printf("%d\n", DigitSum(n));
	system("pause");
}