#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* Strcat(char str1[], char str2[]) {
	char* str = malloc(20);
	for (int i = 0; i < (int)strlen(str1); ++i) {
		str[i] = str1[i];
	}
	for (int j = (int)strlen(str1); j < (int)(strlen(str1) + strlen(str2) + 1); ++j)  {
		str[j] = str2[j- 4];
	}
	return str;
}
void main() {
	char str1[] = "abcd";
	char str2[] = "efgh";
	printf("ԭ���������ַ����ֱ�Ϊ\n%s\n%s\n���Ӻ�Ϊ:%s\n", str1, str2, Strcat(str1, str2));
	system("pause");
}