#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Strcpy(char* str2, const char* str1, int L) {//L为str2的长度为了防止越界问题
	for (int i = 0; *str2 != '\0'; ++i, ++str1, ++str2) {
		if (i == L - 1) {
			*str2 = '\0';
			break;
		}
		*str2 = *str1;
	}
}
void main() {
	char str1[] = "Hello World";
	char str2[5];
	char str3[12];
	char str4[20];
	char str5[15];
	Strcpy(str2, str1, sizeof(str2));
	printf("用Strcpy函数将str1给str2赋值后str2为:\n%s\n", str2);
	Strcpy(str3, str1, sizeof(str3));
	printf("用Strcpy函数将str1给str3赋值后str3为:\n%s\n", str3);
	Strcpy(str4, str1, sizeof(str4));
	printf("用Strcpy函数将str1给str4赋值后str4为:\n%s\n", str4);
	Strcpy(str5, "hello", sizeof(str5));
	printf("用Strcpy函数将字符串常量\"hello\"给str4赋值后str4为:\n%s\n", str5);
	system("pause");
}