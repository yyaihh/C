#include<stdio.h>
#include<stdlib.h>
#define N 8
int fun(char str1[], char str2[]) {
	int count = 0;
	for (int i = 0; i < N - 1 ; ++i) {
		for (int j = i, k = 0; k < N - 1; ++j, ++k) {
			if (str1[j] != str2[k]) {
				break;
			}
			if (j == N - 2) {
				j = -1;
			}
			if (k == N - 2) {
				return i;
			}
		}
	}
	return -1;
}
void main() {
	char str1[N] = "AABCDEF";
	char str2[N];
	//�����ַ���str2
	char ch;
	printf("str1Ϊ:\n%s\n", str1);
	printf("������str2\n");
	for (int i = 0; i < N; ++i) {
		ch = getchar();
		if (ch == '\n' || i == N - 1) {
			str2[i] = '\0';
			break;
		}
		str2[i] = ch;
	}
	int n = fun(str1, str2);
	if (n==0) {
		printf("str2��str1���,��δ��������ѡ\n");
	}
	else if (n > 0) {
		printf("str2��str1����%d��������%d�õ���\n", n, N - 1 - n);
	}
	else {
		printf("str2��str1���޹�ϵ\n");
	}
	system("pause");
}