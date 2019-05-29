#include<stdio.h>
#include<stdlib.h>
char* Strncpy(char* str1, const char* str2, int size) {
	for (int i = 0; *(str1 + i) != '\0'; ++i) {
		if (i == size - 1) {
			*(str1 + i) = '\0';
			break;
		}
		*(str1 + i) = *(str2 + i);
	}
	return str1;
}
int main() {
	char str1[] = "Hello World";
	char str2[5];
	char str3[12];
	char str4[20];
	char str5[15];
	printf("str1为:\n%s\n", str1);
	Strncpy(str2, str1, sizeof(str2));
	printf("用Strcpy函数将str1给str2赋值后str2为:\n%s\n", str2);
	Strncpy(str3, str1, sizeof(str3));
	printf("用Strcpy函数将str1给str3赋值后str3为:\n%s\n", str3);
	Strncpy(str4, str1, sizeof(str4));
	printf("用Strcpy函数将str1给str4赋值后str4为:\n%s\n", str4);
	Strncpy(str5, "hello", sizeof(str5));
	printf("用Strncpy函数将字符串常量\"hello\"给str4赋值后str4为:\n%s\n", str5);
	system("pause");
	return 0;
}