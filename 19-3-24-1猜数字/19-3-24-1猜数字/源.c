#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void Menu() {
	printf("**************************\n");
	printf("   1.开始游戏\n");
	printf("   0.退出游戏\n");
	printf("**************************\n");
	printf("请输入您的选择\n");
}
void fun() {
	int x;
	srand((unsigned int)time(0));//用时间戳来改变每次产生的随机数序列
	int to_guess = rand() % 100;//产生0到99的随机整数
	while (1) {
		printf("请输入您猜的数字\n");
		scanf("%d", &x);
		if (x > to_guess) {
			printf("高了\n");
		}
		else if (x < to_guess) {
			printf("低了\n");
		}
		else {
			printf("猜对了\n");
			break;
		}
	}
}
int main() {
	int num;
	Menu();
	scanf("%d", &num);
	system("cls");
	if (num == 1) {
		fun();
	}
	if (num == 0) {
		printf("再见！\n");
	}
	system("pause");
	return 0;
}
