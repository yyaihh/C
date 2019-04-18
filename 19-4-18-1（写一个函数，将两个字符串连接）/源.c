#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* Strcat(char* str1, char* str2 ) {
	int i;
	static char str[1024];
	for (i = 0; i < (int)strlen(str1); ++i) {
		str[i] = str1[i];
	}
	for (int j = i; j < (int)strlen(str1) + (int)strlen(str2); ++j) {
		str[j] = str2[j - i];
	}
	return str;
}
void main() {
	char str1[] = "abcd";
	char str2[] = "efgh";
	printf("×Ö·û´®1:%s\n", str1);
	printf("×Ö·û´®2:%s\n", str2);
	printf("Á¬½Óºó×Ö·û´®:%s\n", Strcat(str1, str2));
	system("pause");
}