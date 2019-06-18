#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	FILE* fp;
	if ((fp = fopen("test1.txt", "r")) == NULL) {
		printf("error\n");
		system("pause");
		return 0;
	}
	fgetc(fp);
	if (feof(fp)) {
		printf("test1.txt为空\n");
	}
	else {
		printf("test1.txt不为空\n");
	}
	system("pause");
	return 0;
}
#endif
#if 1
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	FILE* fp;
	char c;
	if ((fp = fopen("test2.txt", "r")) == NULL) {
		printf("error\n");
		system("pause");
		return 0;
	}
	c = fgetc(fp);
	while (! feof(fp)) {
		printf("%c %d\n", c, c);
		c = fgetc(fp);
	}
	system("pause");
	return 0;
}
#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	FILE* fp;
	int count = 0;
	if ((fp = fopen("test2.txt", "r")) == NULL) {
		printf("error\n");
		system("pause");
		return 0;
	}
	while (fgetc(fp) != EOF) {
		count++;
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}
#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	FILE* fp;
	int i;
	char str1[4];
	char str2[4];
	char str3[4];
	char str4[4];
	char* str[4] = { str1,str2,str3,str4 };
	if ((fp = fopen("test2.txt", "r")) == NULL) {
		printf("error\n");
		system("pause");
		return 0;
	}
	for (i = 0; fgets(str[i], 4, fp) != NULL; ++i) { 
		printf("str%d : %s\n", i + 1, str[i]);
	}
	printf("i = %d\n", i);
	system("pause");
	return 0;
}
#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	FILE* fp;
	int n;
	char str[12] = { 0 };
	if ((fp = fopen("test2.txt", "r")) == NULL) {
		printf("error\n");
		system("pause");
		return 0;
	}
	//
	fseek(fp, 0, 2);//fp到文件末尾
	n = ftell(fp);//fp到文件开头的偏移量, 这里就是文件长度
	rewind(fp);//fp重新指向文件开头
	//
	for (int i = 0; ftell(fp) != n; ++i) {
		str[i] = fgetc(fp);
	}
	printf("str : %s\n", str);
	system("pause");
	return 0;
}
#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int main() {
	FILE* fp;
	double arr[SIZE] = { 1.1,2.2,3.3,4.4,5.5 };
	double num;
	if ((fp = fopen("test3.txt", "wb")) == NULL) {
		printf("error\n");
		system("pause");
		return 0;
	}
	fwrite(arr, sizeof(arr[0]), SIZE, fp);
	fclose(fp);
	fp = NULL;
	if ((fp = fopen("test3.txt", "rb")) == NULL) {
		printf("error\n");
		system("pause");
		return 0;
	}
	while (fread(&num, sizeof(arr[0]), 1, fp)) {
		printf("%.1f\n", num);
	}
	fclose(fp);
	system("pause");
	return 0;
}
#endif