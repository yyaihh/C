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
	printf("������һ���ַ���\n");
	scanf("%s", p);
	printf("����ַ���Ϊ:%s\n", p);
	printf("����ַ����ĳ���Ϊ:%d\n", Strlen(p));
	system("pause");
}