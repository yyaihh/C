#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Strncmp(const char* str1, const char* str2 ,int size) {
	for (int i = 0; i < size; ++i) {
		if (*(str1 + i) > *(str2 + i)) {
			return 1;
		}
		else if (*(str1 + i) < *(str2 + i)) {
			return -1;
		}
		if (*(str1 + i) == 0 || *(str2 + i) == 0) {
			break;
		}
	}
	return 0;
}
int main() {
	char str1[] = "abcdef";
	char str2[] = "abcd";
	printf("%d\n", Strncmp(str1, str2, 4));
	printf("%d\n", Strncmp(str1, str2, 5));
	printf("%d\n", Strncmp(str1, str2, 100));
	printf("%d\n", Strncmp(str2, str1, 4));
	printf("%d\n", Strncmp(str2, str1, 5));
	printf("%d\n\n", Strncmp(str2, str1, 100));
	printf("%d\n", strncmp(str1, str2, 4));
	printf("%d\n", strncmp(str1, str2, 5));
	printf("%d\n", strncmp(str1, str2, 100));
	printf("%d\n", strncmp(str2, str1, 4));
	printf("%d\n", strncmp(str2, str1, 5));
	printf("%d\n", strncmp(str2, str1, 100));
	system("pause");
	return 0;
}