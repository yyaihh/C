#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define N 10
#if 0
void main() {
	char str1[N];
	printf("请输入字符串str1\n");
	scanf("%s", str1);
	//gets(str1);
	printf("str1为:\n%s\n",str1);
	system("pause");
}
#endif
#if 0
#include<string.h>
void main() {
	char str[N];
	char str1[N];
	char str2[N];
	printf("请输入字符串str\n");
	fgets(str, N, stdin);
	printf("请输入字符串str1\n");
	fgets(str1, N, stdin);
	printf("请输入字符串str2\n");
	fgets(str2, N, stdin);
	printf("str为:\n%s\n", str);
	printf("str1为:\n%s\n", str1);
	printf("str2为:\n%s\n", str2);
	system("pause");
}
#endif
#if 0
void main() {
	char str1[N];
	printf("请输入字符串str1\n");
	for (int i = 0, ch;; ++i) {
		ch = getchar();
		if (i == N - 1 || ch == '\n') {
			str1[i] = '\0';
			break;
		}
		str1[i] = ch;
	}
	printf("str1为:\n%s\n", str1);
	system("pause");
}
#endif
#if 1
void fun(char* str) {
	for (int i = 0, ch = '\0'; ch != '\n'; ++i) {
		ch = getchar();
		if (i >= N) {//当超出字符串长度时, 继续接受键盘输入的字符,直到输入\n为止
			//这是为了防止字符串输入完成后输入的字符会被下一个需要输入的数据接收
			continue;
		}
		if (ch == '\n' || i == N - 1) {
			str[i] = '\0';
			continue;
		}
		str[i] = ch;
	}
}
void main() {
	char str[N];
	char str1[N];
	char str2[N];
	printf("请输入字符串str\n");
	fun(str);
	printf("请输入字符串str1\n");
	fun(str1);
	printf("请输入字符串str2\n");
	fun(str2);
	printf("str为:\n%s\n", str);
	printf("str1为:\n%s\n", str1);
	printf("str2为:\n%s\n", str2);
	system("pause");
}
#endif