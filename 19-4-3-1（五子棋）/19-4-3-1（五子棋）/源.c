#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include"func.h"

void Menu() {
	printf("1.开始游戏\n");
	printf("0.退出游戏\n");
	printf("请输入您的选择\n");
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
	printf(" ＿ ＿ ＿ ＿ ＿ ＿ ＿ ＿ ＿ ＿ ＿ ＿ ＿ ＿ ＿ \n");
	for (int row = 0; row < MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			printf("| %c", chessboard[row][col]);
		}
		printf("|\n|＿|＿|＿|＿|＿|＿|＿|＿|＿|＿|＿|＿|＿|＿|＿|");
		printf("%d\n", row);
	}
}
void PlayerMove() {
	printf("请输入您落子位置的坐标值\n");
	while (1) {
		scanf("%d %d", &y, &x);
		if (y > MAX_ROW - 1 || y < 0 || x > MAX_COL - 1 || x < 0) {
			printf("输入非法,请重新输入！\n");
			continue;
		}
		if (chessboard[y][x] != ' ') {
			printf("此位置已有棋子\n");
			continue;
		}
		break;
	}
	chessboard[y][x] = 'x';
}

void ComputerMove() {
	srand((unsigned int)time(0));
	if (AI_1(4, CheckGameOver(4, y1, x1, 'o')) == 1) {//如果有4个连在一起的o则连接第5个o
		return;
	}
	if (AI_2(CheckGameOver(2, y, x, 'x'), 3, 'x') == 1) {//3子连结堵截(出现xxx x或x xxx时在空处落子)
		return;
	}
	if (AI_1(4, CheckGameOver(4, y, x, 'x')) == 1) {//四子连结堵截
		return;
	}
	if (AI_2(CheckGameOver(2, y, x, 'x'), 2, 'x') == 1) {//二子连结堵截(出现xx x时在空处落子)
		return;
	}
	if (AI_6('x') == 1) {//。。。
		return;
	}
	if (AI_3(CheckGameOver(3, y1, x1, 'o'),3) == 1) {//出现  ooo  连接第四个o
		return;
	}
	if (AI_1(3, CheckGameOver(3, y1, x1, 'o')) == 1) {//如果有3个连在一起的o则连接第4个o
		return;
	}
	if (AI_1(3, CheckGameOver(3, y, x, 'x')) == 1) {//三子连结堵截
		return;
	}
	if (AI_2(CheckGameOver(2, y1, x1, 'o'), 2, 'o') == 1) {//出现oo o时在空处落子
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
	printf("1.玩家先落子\n2.电脑先落子\n请输入您的选择\n");
	scanf("%d", &choic);
	while (choic != 2 && choic != 1) {
		printf("您的输入非法，请重新输入！\n");
		scanf("%d", &choic);
	}
	system("cls");
	Init();//初始化棋盘
	if (choic == 1) {
		while (1) {
			++num;
			Print();//打印棋盘
			PlayerMove();//玩家落子,玩家落子用x表示
			Print();
			system("cls");
			if (CheckGameOver(5, y, x, 'x') != 0) {//检测游戏是否结束
				Print();
				printf("\n你赢了！\n");
				break;
			}
			ComputerMove();//电脑落子
			Print();
			system("cls");
			if (CheckGameOver(5, y1, x1, 'o') != 0) {//检测游戏是否结束
				Print();
				printf("\n电脑赢了！\n");
				break;
			}
			if (num == 225) {
				printf("和棋\n");
				break;
			}
		}
	}
	else {
		while (1) {
			++num;
			ComputerMove();//电脑落子
			Print();//打印棋盘
			if (CheckGameOver(5, y1, x1, 'o') != 0) {//检测游戏是否结束
				Print();
				printf("\n电脑赢了！\n");
				break;
			}
			PlayerMove();//玩家落子
			Print();
			system("cls");
			if (CheckGameOver(5, y, x, 'x') != 0) {//检测游戏是否结束
				Print();
				printf("\n你赢了！\n");
				break;
			}
			if (num == 225) {
				printf("和棋\n");
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
		printf("您的输入非法，请重新输入！\n");
		scanf("%d", &choic);
	}
	if (choic == 1) {
		system("cls");
		Game();
	}
	else {
		printf("再见！\n");
	}
	system("pause");
}