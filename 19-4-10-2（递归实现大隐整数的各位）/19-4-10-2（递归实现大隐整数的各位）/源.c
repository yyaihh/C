#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void print(int n) {
	if (n > 9) {
		print(n / 10);
	}
	printf("%d  ", n % 10);
}
void main() {
	int n;
	printf("��������������ֵ\n");
	scanf("%d", &n);
	print(n);
	printf("\n");
	system("pause");
}