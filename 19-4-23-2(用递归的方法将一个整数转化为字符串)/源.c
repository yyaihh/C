#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i = 0;
void int_string(int n, char* str) {
	if (n > 9) {
		int_string(n / 10, str);
	}
	str[i++] = n % 10 + '0';
}
void main() {
	int n;
	char str[12] = { '\0' };
	printf("请输入一个整数\n");
	scanf("%d", &n);
	if (n < 0) {
		n = -n;
		str[i++] = '-';
	}
	int_string(n, str);
	printf("字符串为:%s\n", str);
	system("pause");
}