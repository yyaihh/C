#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//char* Strtok(char* str, const char* sep) {
//	static char* p;
//	int i;
//	if (str != NULL) {
//		p = str;
//	}
//	else {
//		++p;
//	}
//	while (p) {
//		for (i = 0; *(sep + i) != 0; ++i) {
//			if (*p == *(sep + i)) {
//				break;
//			}
//		}
//		if (*(sep + i) != 0) {
//			*p = 0;
//		}
//	}
//}
int main() {
	char str1[] = "I am,a. ,/' student";
	char str2[] = "I am,a. ,/' student";
	/*for (char* p = Strtok(str1, ". ,/,"); p != NULL; p = Strtok(NULL, ". ,/'")) {
		printf("%s ", p);
	}*/
	char str3[] = "abcedf";
	char str4[] = "z";
	int n = strncmp(str4, str3, 3);
	printf("%d\n", n);
	printf("\n");;
	system("pause");
	return 0;
}
