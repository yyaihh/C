#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define N 10
#if 0
void main() {
	char str1[N];
	printf("�������ַ���str1\n");
	scanf("%s", str1);
	//gets(str1);
	printf("str1Ϊ:\n%s\n",str1);
	system("pause");
}
#endif
#if 0
#include<string.h>
void main() {
	char str[N];
	char str1[N];
	char str2[N];
	printf("�������ַ���str\n");
	fgets(str, N, stdin);
	printf("�������ַ���str1\n");
	fgets(str1, N, stdin);
	printf("�������ַ���str2\n");
	fgets(str2, N, stdin);
	printf("strΪ:\n%s\n", str);
	printf("str1Ϊ:\n%s\n", str1);
	printf("str2Ϊ:\n%s\n", str2);
	system("pause");
}
#endif
#if 0
void main() {
	char str1[N];
	printf("�������ַ���str1\n");
	for (int i = 0, ch;; ++i) {
		ch = getchar();
		if (i == N - 1 || ch == '\n') {
			str1[i] = '\0';
			break;
		}
		str1[i] = ch;
	}
	printf("str1Ϊ:\n%s\n", str1);
	system("pause");
}
#endif
#if 1
void fun(char* str) {
	for (int i = 0, ch = '\0'; ch != '\n'; ++i) {
		ch = getchar();
		if (i >= N) {//�������ַ�������ʱ, �������ܼ���������ַ�,ֱ������\nΪֹ
			//����Ϊ�˷�ֹ�ַ���������ɺ�������ַ��ᱻ��һ����Ҫ��������ݽ���
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
	printf("�������ַ���str\n");
	fun(str);
	printf("�������ַ���str1\n");
	fun(str1);
	printf("�������ַ���str2\n");
	fun(str2);
	printf("strΪ:\n%s\n", str);
	printf("str1Ϊ:\n%s\n", str1);
	printf("str2Ϊ:\n%s\n", str2);
	system("pause");
}
#endif