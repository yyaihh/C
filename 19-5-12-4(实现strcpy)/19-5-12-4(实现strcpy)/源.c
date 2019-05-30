#include<stdio.h>
#include<stdlib.h>
char* Strcpy(char* str2, const char* str1) {//可能会越界
	while (*(str2++) = *(str1++));
	return str2;
}
void main() {
	char str1[] = "Hello World";
	char str2[20];
	char str3[20];
	Strcpy(str2, str1);
	printf("用Strcpy函数将str1给str2赋值后str2为:\n%s\n", str2);
	Strcpy(str3, "hello");
	printf("用Strcpy函数将字符串常量\"hello\"给str3赋值后str3为:\n%s\n", str3);
	system("pause");
}