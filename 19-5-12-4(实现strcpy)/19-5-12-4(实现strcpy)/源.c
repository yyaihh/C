#include<stdio.h>
#include<stdlib.h>
char* Strcpy(char* str2, const char* str1) {//���ܻ�Խ��
	for (int i = 0; *(str2 + i) != '\0'; ++i) {
		*(str2 + i) = *(str1 + i);
	}
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