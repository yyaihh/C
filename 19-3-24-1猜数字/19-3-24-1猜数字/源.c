#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void Menu() {
	printf("**************************\n");
	printf("   1.��ʼ��Ϸ\n");
	printf("   0.�˳���Ϸ\n");
	printf("**************************\n");
	printf("����������ѡ��\n");
}
void fun() {
	int x;
	srand((unsigned int)time(0));//��ʱ������ı�ÿ�β��������������
	int to_guess = rand() % 100;//����0��99���������
	while (1) {
		printf("���������µ�����\n");
		scanf("%d", &x);
		if (x > to_guess) {
			printf("����\n");
		}
		else if (x < to_guess) {
			printf("����\n");
		}
		else {
			printf("�¶���\n");
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
		printf("�ټ���\n");
	}
	system("pause");
	return 0;
}
