#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Menu() {
	int n;
	printf("**********************\n");
	printf("*******1.��¼*********\n");
	printf("*******0.�˳�*********\n");
	printf("**********************\n");
	printf("����������ѡ��\n");
	scanf("%d", &n);
	system("cls");
	return n;
}
void fun(int x) {
	int i;
	char secret[16];
	char M[] = "123abc";//����
	if (x == 1) {
		for (i = 1; i <= 3; ++i) {
			printf("��%d��������������\n",i);
			scanf("%s", secret);
			if (strcmp(M,secret)==0) {
				printf("��½�ɹ���\n");
				break;
			}
		}
		if (i == 4) {
			printf("�������������\n");
		}
	}
	else {
		printf("�˳�����\n");
	}
}
void main() {
	fun(Menu());
	system("pause");
}