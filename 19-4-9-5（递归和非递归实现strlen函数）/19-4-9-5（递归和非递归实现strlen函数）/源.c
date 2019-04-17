#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Strlen1(char* str) {
	if (*str == '\0') {
		return 0;
	}
	else {
		return Strlen1(str + 1) + 1;
	}
}
int Strlen2(char* str) {//·Çµİ¹é
	int n = 0;
	while (*str != '\0') {
		++str;
		++n;
	}
	return n;
}
void main() {
	char str[30] = { 0 };
	printf("ÇëÊäÈëÒ»´®×Ö·û\n");
	fgets(str, 30, stdin);
	str[strlen(str) - 1] = '\0';
	printf("µİ¹éÅĞ¶Ï×Ö·û´®³¤¶ÈÊÇ:%d\n", Strlen1(str));
	printf("·Çµİ¹éÅĞ¶Ï×Ö·û´®³¤¶ÈÊÇ:%d\n", Strlen2(str));
	system("pause");
}