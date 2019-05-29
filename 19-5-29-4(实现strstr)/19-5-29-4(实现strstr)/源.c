#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* Strstr(const char* str1,const char* str2) {
	int n = strlen(str2);
	for (; *str1 != 0; ++str1) {
		if (strncmp(str1, str2, n) == 0) {
			return (char*)str1;
		}
	}
	return NULL;
}
int main() {
	char str1[20] = "abcdefghi";
	char str2[7] = "cdef";
	char str3[5] = "acfv";
	printf("str1:%s\n", str1);
	printf("str2:%s\n", str2);
	printf("str3:%s\n", str3);
	printf("%s\n", strstr(str1, str2));//¿âº¯Êı
	printf("%s\n", Strstr(str1, str2));
	printf("%s\n", strstr(str1, str3));//¿âº¯Êı
	printf("%s\n", Strstr(str1, str3));
	system("pause");
	return 0;
}