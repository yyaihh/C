#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	FILE* fp;
	char str1[20];
	char str2[20];
	printf("������str1\n");
	scanf("%s", str1);
	fp = fopen("er.txt", "ab+");
	if (fp == NULL) {
		perror("������");
		system("pause");
		return 0;
	}
	//�����ļ��ֽ���
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
	fseek(fp, 0, 2);//���ļ���־λ��ָ���ļ�ĩβ
	n = ftell(fp);//���������ļ���־λ��������ļ���ͷλ�õ�ƫ����
	rewind(fp);//�ٽ��ļ�λ�ñ�־ָ���ļ���ͷ
	//
	printf("test.txtΪ%d�ֽ�\n", n);
	fclose(fp);
	system("pause");
	return 0;
}
#endif