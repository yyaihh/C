#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Menu() {
	int n;
	printf("**********************\n");
	printf("*******1.登录*********\n");
	printf("*******0.退出*********\n");
	printf("**********************\n");
	printf("请输入您的选项\n");
	scanf("%d", &n);
	system("cls");
	return n;
}
void fun(int x) {
	int i;
	char secret[16];
	char M[] = "123abc";//密码
	if (x == 1) {
		for (i = 1; i <= 3; ++i) {
			printf("第%d次输入您的密码\n",i);
			scanf("%s", secret);
			if (strcmp(M,secret)==0) {
				printf("登陆成功！\n");
				break;
			}
		}
		if (i == 4) {
			printf("错误次数达上限\n");
		}
	}
	else {
		printf("退出程序\n");
	}
}
void main() {
	fun(Menu());
	system("pause");
}