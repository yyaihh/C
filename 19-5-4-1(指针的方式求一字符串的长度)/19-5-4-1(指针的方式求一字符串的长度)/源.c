#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int Strlen(char* str) {
	int count = 0;
	while (*str != '\0') {
		count += 1;
		++str;
	}
	return count;
}
void main() {
	char str[1024];
	char* p = str;
	printf("请输入一个字符串\n");
	scanf("%s", p);
	printf("这个字符串为:%s\n", p);
	printf("这个字符串的长度为:%d\n", Strlen(p));
	system("pause");
}