#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* Strncat(char* str1, const char* str2, int size) {
	int n = strlen(str1);
	for (int i = 0; ; ++i) {
		if (i == size || *(str2 + i) == '\0') {
			*(str1 + n + i) = '\0';
			break;
		}
		*(str1 + n + i) = *(str2 + i);
	}
	return str1;
}
int main() {
	char str1[12] = "abcde";
	char str2[] = "fghijk";
	printf("str1Ϊ:\n%s\n", str1);
	printf("str2Ϊ:\n%s\n", str2);
	Strncat(str1, str2, 6);
	printf("str1����str2��Ϊ:\n%s\n", str1);
	system("pause");
	return 0;
}
