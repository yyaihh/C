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
	printf("������str\n");
	Gets(str);
	printf("����ǰΪ:\n%s\n", str);
	printf("��Ҫ���������ַ�,������\n");
	scanf("%d", &m);
	fun(str, m);
	printf("����%d��Ϊ\n%s\n", m, str);
	system("pause");
}