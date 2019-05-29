#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* Strchr(char* str, int c) {
	for (; *str != 0; ++str) {
		if (*str == c) {
			return str;
		}
	}
	return NULL;
}
int main() {
	char str[] = "abcdefg";
	char a = 'd';
	char b = 'z';
	printf("%s\n", strchr(str, a));//¿âº¯Êý
	printf("%s\n", Strchr(str, a));
	printf("%s\n", strchr(str, b));//¿âº¯Êý
	printf("%s\n", Strchr(str, b));
	system("pause");
	return 0;
}