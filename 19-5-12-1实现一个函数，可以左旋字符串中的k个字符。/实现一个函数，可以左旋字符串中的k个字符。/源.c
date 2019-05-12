#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1024
void Gets(char str[]) {
	char ch;
	for (int i = 0; i < N; ++i) {
		ch = getchar();
		if (ch == '\n' || i == N - 1) {
			str[i] = '\0';
			break;
		}
		str[i] = ch;
	}
}
void fun(char str[], int m) {
	int num = strlen(str);
	for (int i = 0; i < m; ++i) {
		for (char* p = str + num - 1; str < p; --p) {
			*p = *p^*str;
			*str = *p^*str;
			*p = *p^*str;
		}
	}
}
void main() {
	char str[N];
	int m;
	printf("请输入str\n");
	Gets(str);
	printf("左旋前为:\n%s\n", str);
	printf("需要左旋几个字符,请输入\n");
	scanf("%d", &m);
	fun(str, m);
	printf("左旋%d后为\n%s\n", m, str);
	system("pause");
}