#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* Strcat(char* str1, const char* str2 ) {
	int n = strlen(str1);
	for (int i = n; i < n + (int)strlen(str2); ++i) {
		str1[i] = str2[i - n];
	}
	return str1;
}
void main() {
	char str1[256] = "abcd";
	char str2[256] = "efgh";
	printf("字符串1:%s\n", str1);
	printf("字符串2:%s\n", str2);
	Strcat(str1, str2);
	printf("将str2连接到str1后str1为:%s\n", str1);
	system("pause");
}