#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
void fun(char str[]) {
	for (int i = 0; i < (int)strlen(str); ++i) {
		for (int j = i + 1; j < (int)strlen(str); ++j) {
			if (str[i] > str[j]) { //�Ӵ�Сֻ�軻��<��
				str[i] = str[i] ^ str[j];
				str[j] = str[i] ^ str[j];
				str[i] = str[i] ^ str[j];
			}
		}
	}
}

void main() {
	char str[1024];
	printf("������ʮ���ַ�\n");
	fgets(str, N + 1, stdin);
	fun(str);
	printf("�������ַ�Ϊ:%s\n", str);
	system("pause");
}