#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* Strncat(char* str1, const char* str2, int size) {
	int n = strlen(str1);
	int i = 0;
	while (*(str1++ + n + i) = *(str2++ + i)) {
		if (i == size) {
			*(str1 + n + i) = 0;
			break;
		}
	}
	return str1;
}
int main() {
	char str1[12] = "abcde";
	char str2[] = "fghijk";
	printf("str1为:\n%s\n", str1);
	printf("str2为:\n%s\n", str2);
	Strncat(str1, str2, 6);
	printf("str1连接str2后为:\n%s\n", str1);
	system("pause");
	return 0;
}
