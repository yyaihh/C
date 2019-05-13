#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
void fun(char str[]) {
	int n = strlen(str);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 1 - i; ++j) {
			if (str[j] > str[j + 1]) { //从大到小只需换成<号
				str[j] = str[j] ^ str[j + 1];
				str[j + 1] = str[j] ^ str[j + 1];
				str[j] = str[j] ^ str[j + 1];
			}
		}
	}
}

void main() {
	char str[1024];
	printf("请输入十个字符\n");
	fgets(str, N, stdin);
	fun(str);
	printf("排序后的字符为:%s\n", str);
	system("pause");
}