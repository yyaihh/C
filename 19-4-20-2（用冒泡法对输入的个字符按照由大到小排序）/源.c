#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
void fun(char str[]) {
	for (int i = 0; i < (int)strlen(str); ++i) {
		for (int j = i + 1; j < (int)strlen(str); ++j) {
			if (str[i] > str[j]) { //从大到小只需换成<号
				str[i] = str[i] ^ str[j];
				str[j] = str[i] ^ str[j];
				str[i] = str[i] ^ str[j];
			}
		}
	}
}

void main() {
	char str[1024];
	printf("请输入十个字符\n");
	fgets(str, N + 1, stdin);
	fun(str);
	printf("排序后的字符为:%s\n", str);
	system("pause");
}