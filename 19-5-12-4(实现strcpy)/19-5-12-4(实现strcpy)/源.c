#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Strcpy(char* str2, const char* str1, int L) {//LΪstr2�ĳ���Ϊ�˷�ֹԽ������
	for (int i = 0; *str2 != '\0'; ++i, ++str1, ++str2) {
		if (i == L - 1) {
			*str2 = '\0';
			break;
		}
		*str2 = *str1;
	}
}
void main() {
	char str1[] = "Hello World";
	char str2[5];
	char str3[12];
	char str4[20];
	char str5[15];
	Strcpy(str2, str1, sizeof(str2));
	printf("��Strcpy������str1��str2��ֵ��str2Ϊ:\n%s\n", str2);
	Strcpy(str3, str1, sizeof(str3));
	printf("��Strcpy������str1��str3��ֵ��str3Ϊ:\n%s\n", str3);
	Strcpy(str4, str1, sizeof(str4));
	printf("��Strcpy������str1��str4��ֵ��str4Ϊ:\n%s\n", str4);
	Strcpy(str5, "hello", sizeof(str5));
	printf("��Strcpy�������ַ�������\"hello\"��str4��ֵ��str4Ϊ:\n%s\n", str5);
	system("pause");
}