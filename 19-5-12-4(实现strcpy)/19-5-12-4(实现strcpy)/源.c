#include<stdio.h>
#include<stdlib.h>
char* Strcpy(char* str2, const char* str1) {//���ܻ�Խ��
	while (*(str2++) = *(str1++));
	return str2;
}
void main() {
	char str1[] = "Hello World";
	char str2[20];
	char str3[20];
	Strcpy(str2, str1);
	printf("��Strcpy������str1��str2��ֵ��str2Ϊ:\n%s\n", str2);
	Strcpy(str3, "hello");
	printf("��Strcpy�������ַ�������\"hello\"��str3��ֵ��str3Ϊ:\n%s\n", str3);
	system("pause");
}