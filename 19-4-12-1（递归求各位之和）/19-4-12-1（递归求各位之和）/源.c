#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int count(int n) {
	if (n == 0) {
		return 0;
	}
	return n % 10 + count(n / 10);
}

void main() {
	int n;
	printf("������һ��������\n");
	scanf("%d", &n);
	printf("%d�ĸ�λ֮����:%d\n", n, count(n));
	system("pause");
}