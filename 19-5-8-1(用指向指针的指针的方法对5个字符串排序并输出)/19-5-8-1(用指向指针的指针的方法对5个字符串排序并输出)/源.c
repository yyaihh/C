#include<stdio.h>
#include<stdlib.h>
#define N 20
int Strcmp(char* p1, char* p2) {
	for (int i = 0; i < N; ++i) {
		if (p1[i] != p2[i]) {
			return p1[i] - p2[i];
		}
		else if (p1[i] == '\0' && p2[i] == '\0') {
			return 0;
		}
	}
	return 0;
}
void fun(char** str) {
	char* temp;
	for (int i = 0; i < 5; ++i) {
		for (int j = i + 1; j < 5; ++j) {
			if (Strcmp(*(str + i), *(str + j)) > 0) {
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}
}
void main() {
	char str1[N] = { '\0' };
	char str2[N] = { '\0' };
	char str3[N] = { '\0' };
	char str4[N] = { '\0' };
	char str5[N] = { '\0' };
	//����ָ������str, ��5��ָ��char�����ݵ�ָ��Ԫ�����, ��5��ָ��Ԫ�طֱ���ָ������ַ������ָ��
	char* str[5] = { str1,str2,str3,str4,str5};
	char** p = str;
	for (int i = 0; i < 5; ++i) {
		printf("�������%d���ַ���\n", i + 1);
		fgets(*(p + i), N, stdin);
	}
	system("cls");
	//������fgets���������ַ������ַ���ĩβ�Ļ��з�'\n'
	for (int i = 0; i < 5; ++i) {
		for (char* q = *(p + i); *q; ++q) {
			if (*q == '\n') {
				*q = '\0';
				break;
			}
		}
	}
	printf("����ǰ:\n");
	for (int i = 0; i < 5; ++i) {
		printf("%s\n\n", *(p + i));
	}
	fun(p);
	printf("�����:\n");
	for (int i = 0; i < 5; ++i) {
		printf("%s\n\n", *(p + i));
	}
	system("pause");
}