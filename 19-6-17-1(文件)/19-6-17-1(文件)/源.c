#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	FILE* fp;
	char str1[20];
	char str2[20];
	printf("请输入str1\n");
	scanf("%s", str1);
	fp = fopen("er.txt", "ab+");
	if (fp == NULL) {
		perror("错误是");
		system("pause");
		return 0;
	}
	//计算文件字节数
	int n = printf("abc%d\n", 123);
	printf("%d\n", n);
	fprintf(fp, "%s ", str1);
	//fscanf(fp, "%s", str2);
	printf("str1:%s\n", str1);
	//printf("str2:%s\n", str2);
	fclose(fp);
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
	int n;
	if ((fp = fopen("test.txt","r"))==NULL){
		printf("error\n");
		system("pause");
		return 0;
	}
	//
	fseek(fp, 0, 2);//将文件标志位置指向文件末尾
	n = ftell(fp);//函数返回文件标志位置相对于文件开头位置的偏移量
	rewind(fp);//再将文件位置标志指向文件开头
	//
	printf("test.txt为%d字节\n", n);
	fclose(fp);
	system("pause");
	return 0;
}
#endif