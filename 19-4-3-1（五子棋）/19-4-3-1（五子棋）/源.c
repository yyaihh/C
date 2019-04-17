#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include"func.h"

void Menu() {
	printf("1.��ʼ��Ϸ\n");
	printf("0.�˳���Ϸ\n");
	printf("����������ѡ��\n");
}
void Init() {
	for (int row = 0; row < MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			chessboard[row][col] = ' ';
		}
	}
}
void Print() {
	printf("  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 \n");
	printf(" �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� \n");
	for (int row = 0; row < MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			printf("| %c", chessboard[row][col]);
		}
		printf("|\n|��|��|��|��|��|��|��|��|��|��|��|��|��|��|��|");
		printf("%d\n", row);
	}
}
void PlayerMove() {
	printf("������������λ�õ�����ֵ\n");
	while (1) {
		scanf("%d %d", &y, &x);
		if (y > MAX_ROW - 1 || y < 0 || x > MAX_COL - 1 || x < 0) {
			printf("����Ƿ�,���������룡\n");
			continue;
		}
		if (chessboard[y][x] != ' ') {
			printf("��λ����������\n");
			continue;
		}
		break;
	}
	chessboard[y][x] = 'x';
}

void ComputerMove() {
	srand((unsigned int)time(0));
	if (AI_1(4, CheckGameOver(4, y1, x1, 'o')) == 1) {//�����4������һ���o�����ӵ�5��o
		return;
	}
	if (AI_2(CheckGameOver(2, y, x, 'x'), 3, 'x') == 1) {//3������½�(����xxx x��x xxxʱ�ڿմ�����)
		return;
	}
	if (AI_1(4, CheckGameOver(4, y, x, 'x')) == 1) {//��������½�
		return;
	}
	if (AI_2(CheckGameOver(2, y, x, 'x'), 2, 'x') == 1) {//��������½�(����xx xʱ�ڿմ�����)
		return;
	}
	if (AI_6('x') == 1) {//������
		return;
	}
	if (AI_3(CheckGameOver(3, y1, x1, 'o'),3) == 1) {//����  ooo  ���ӵ��ĸ�o
		return;
	}
	if (AI_1(3, CheckGameOver(3, y1, x1, 'o')) == 1) {//�����3������һ���o�����ӵ�4��o
		return;
	}
	if (AI_1(3, CheckGameOver(3, y, x, 'x')) == 1) {//��������½�
		return;
	}
	if (AI_2(CheckGameOver(2, y1, x1, 'o'), 2, 'o') == 1) {//����oo oʱ�ڿմ�����
		return;
	}
	if (AI_4() == 1) {
		return;
	}
	y1 = rand() % 5 + 5;
	x1 = rand() % 5 + 5;
	if (chessboard[y1][x1] == ' ') {
		chessboard[y1][x1] = 'o';
		return;
	}
}

void Game() {
	int num = 0;
	int choic;
	printf("1.���������\n2.����������\n����������ѡ��\n");
	scanf("%d", &choic);
	while (choic != 2 && choic != 1) {
		printf("��������Ƿ������������룡\n");
		scanf("%d", &choic);
	}
	system("cls");
	Init();//��ʼ������
	if (choic == 1) {
		while (1) {
			++num;
			Print();//��ӡ����
			PlayerMove();//�������,���������x��ʾ
			Print();
			system("cls");
			if (CheckGameOver(5, y, x, 'x') != 0) {//�����Ϸ�Ƿ����
				Print();
				printf("\n��Ӯ�ˣ�\n");
				break;
			}
			ComputerMove();//��������
			Print();
			system("cls");
			if (CheckGameOver(5, y1, x1, 'o') != 0) {//�����Ϸ�Ƿ����
				Print();
				printf("\n����Ӯ�ˣ�\n");
				break;
			}
			if (num == 225) {
				printf("����\n");
				break;
			}
		}
	}
	else {
		while (1) {
			++num;
			ComputerMove();//��������
			Print();//��ӡ����
			if (CheckGameOver(5, y1, x1, 'o') != 0) {//�����Ϸ�Ƿ����
				Print();
				printf("\n����Ӯ�ˣ�\n");
				break;
			}
			PlayerMove();//�������
			Print();
			system("cls");
			if (CheckGameOver(5, y, x, 'x') != 0) {//�����Ϸ�Ƿ����
				Print();
				printf("\n��Ӯ�ˣ�\n");
				break;
			}
			if (num == 225) {
				printf("����\n");
				break;
			}
		}
	}
}
void main() {
	int choic;
	Menu();
	scanf("%d", &choic);
	while (choic != 0 && choic != 1) {
		printf("��������Ƿ������������룡\n");
		scanf("%d", &choic);
	}
	if (choic == 1) {
		system("cls");
		Game();
	}
	else {
		printf("�ټ���\n");
	}
	system("pause");
}