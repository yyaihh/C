#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_ROW 9
#define MAX_COL 9
char show_map[MAX_ROW][MAX_COL];
char mine_map[MAX_ROW][MAX_ROW];
int y, x;
int mine;
int num = 0;
int Menu() {
	printf("1.开始游戏\n");
	printf("0.退出游戏\n");
	printf("请输入您的选择\n");
	int choic;
	scanf("%d", &choic);
	while (choic != 0 && choic != 1) {
		printf("您的输入非法，请重新输入！\n");
		scanf("%d", &choic);
	}
	return choic;
}

void Init() {//初始化两个棋盘
	int m, n;
	srand((unsigned int)time(0));
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_ROW; ++j) {
			show_map[i][j] = '*';
			mine_map[i][j] = ' ';
		}
	}
	for (int i = 0; i < mine; ++i) {
		while (1) {
			m = rand() % MAX_ROW;
			n = rand() % MAX_COL;
			if (mine_map[m][n] == ' ') {
				mine_map[m][n] = '#';
				break;
			}
		}
	}
}

void Print(char map[MAX_ROW][MAX_COL]) {//打印棋盘
	printf("  0  1  2  3  4  5  6  7  8 \n");
	printf(" ＿ ＿ ＿ ＿ ＿ ＿ ＿ ＿ ＿\n");
	for (int row = 0; row < MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			printf("| %c", map[row][col]);
		}
		printf("|\n|＿|＿|＿|＿|＿|＿|＿|＿|＿|");
		printf("%d\n", row);
	}
}
int PlayerMove() {//选择无雷或者有雷的位置
	int choic;
	printf("请输入您的选项\n1.输入您认为没有地雷的坐标\n2.输入您认为有雷的坐标\n3.翻看\n");
	scanf("%d", &choic);
	while (choic < 1 && choic > 3) {
		printf("您的输入非法，请重新输入\n");
		scanf("%d %d", &y, &x);
	}
	switch (choic) {
	case 1:
		printf("请输入您认为没有地雷的坐标\n");
		while(1) {
			scanf("%d %d", &y, &x);
			if (y < 0 || y > (MAX_ROW - 1) || x < 0 || x > (MAX_COL - 1)) {
				printf("您的输入非法，请重新输入认为没有地雷的坐标\n");
				continue;
			}
			if (show_map[y][x] >= '0' && show_map[y][x] < '9' && show_map[y][x] == ' ') {
				printf("您输入的位置您已经判断过了，请重新输入认为没有地雷的坐标\n");
				continue;
			}
			break;
		}
		if (mine_map[y][x] == '#') {//如果是雷返回-1，游戏结束
			return -1;
		}
		else {
			return -2;
		}
		break;
	case 2:
		printf("请输入您的坐标\n");
		while (1) {
			scanf("%d %d", &y, &x);
			if (show_map[y][x] == '@'|| show_map[y][x] >= '0' && show_map[y][x] < '9') {
				printf("您输入的位置您已经判断过了，请重新输入您认为有雷的坐标\n");
				continue;
			}
			show_map[y][x] = '@';
			break;
		}
		if (mine_map[y][x] == '#') {
			++num;
			return num;
		}
		return num;
		break;
	case 3:
		Print(mine_map);
		system("pause");
		return -3;
		break;
	}
	return 3;
}

int Count(int y1, int x1) {//计算该位置周围8个位置上的雷数
	int count = 0;
	if (mine_map[y1][x1] == '#' || show_map[y1][x1] > '0' && show_map[y1][x1] < '9') {
		return -1;
	}
	if (y1 + 1 < MAX_ROW && mine_map[y1 + 1][x1] == '#') {
		++count;
	}
	if (y1 - 1 >= 0 && mine_map[y1 - 1][x1] == '#') {
		++count;
	}
	if (x1 + 1 < MAX_COL && mine_map[y1][x1 + 1] == '#') {
		++count;
	}
	if (x1 - 1 >= 0 && mine_map[y1][x1 - 1] == '#') {
		++count;
	}	
	if (y1 + 1 < MAX_ROW && x1 + 1 < MAX_COL && mine_map[y1 + 1][x1 + 1] == '#') {
		++count;		}
	if (x1 - 1 >= 0 && y1 - 1 >= 0 && mine_map[y1 - 1][x1 - 1] == '#') {
		++count;
	}
	if (x1 - 1 >= 0 && y1 + 1 < MAX_ROW && mine_map[y1 + 1][x1 - 1] == '#') {
		++count;
	}
	if (y1 - 1 >= 0 && x1 + 1 < MAX_COL && mine_map[y1 - 1][x1 + 1] == '#') {
		++count;
	}
	return count;
}
void play(int y1, int x1) {//应用递归排除周围没有雷的区域
	int ret;
	ret = Count(y1, x1);
	if (ret == -1) {
		return;
	}
	if (ret == 0) {
		show_map[y1][x1] = ' ';
		if (y1 - 1 >= 0 && y1 - 1 < MAX_ROW && x1 >= 0 && x1 < MAX_COL && (show_map[y1 - 1][x1] == '*'))
			play(y1 - 1, x1);
		if (y1 >= 0 && y1 < MAX_ROW && x1 - 1 >= 0 && x1 - 1 < MAX_COL && (show_map[y1][x1 - 1] == '*'))
			play(y1, x1 - 1);
		if (y1 >= 0 && y1 < MAX_ROW && x1 + 1 >= 0 && x1 + 1 < MAX_COL && (show_map[y1][x1 + 1] == '*'))
			play(y1, x1 + 1);
		if (y1 + 1 >= 0 && y1 + 1 < MAX_ROW && x1 >= 0 && x1 < MAX_COL && (show_map[y1 + 1][x1] == '*'))
			play(y1 + 1, x1);
	}
	else if (ret != 0 && ret != -1) {
		show_map[y1][x1] = ret + '0';
		if (y1 == y && x1 == x) {
			if (y1 - 1 >= 0 && y1 - 1 < MAX_ROW && x1 >= 0 && x1 < MAX_COL && (show_map[y1 - 1][x1] == '*'))
				play(y1 - 1, x1);
			if (y1 >= 0 && y1 < MAX_ROW && x1 - 1 >= 0 && x1 - 1 < MAX_COL && (show_map[y1][x1 - 1] == '*'))
				play(y1, x1 - 1);
			if (y1 >= 0 && y1 < MAX_ROW && x1 + 1 >= 0 && x1 + 1 < MAX_COL && (show_map[y1][x1 + 1] == '*'))
				play(y1, x1 + 1);
			if (y1 + 1 >= 0 && y1 + 1 < MAX_ROW && x1 >= 0 && x1 < MAX_COL && (show_map[y1 + 1][x1] == '*'))
				play(y1 + 1, x1);
		}
	}
}

void Game(){
	int n;
	printf("请输入雷的数量，小于75\n");
	scanf("%d", &mine);
	system("cls");
	while (mine <= 0 || mine > 75) {
		printf("您的输入非法\n");
		scanf("%d", &mine);
	}
	Init();
	while (1) {
		Print(show_map);
		printf("剩余雷数%d\n", mine - num);
		n = PlayerMove(show_map, mine_map);
		if (n == -1) {
			printf("您踩雷了！\n");
			Print(mine_map);
			break;
		}
		if (n == mine) {
			system("cls");
			Print(show_map);
			printf("你赢了，雷已经被全部标记\n");
			Print(mine_map);
			break;
		}
		if (n == -2) {
			play(y, x);
		}
		system("cls");
	}
}
void main() {
	if (Menu() == 1) {
		system("cls");
		Game();
	}
	else {
		printf("再见！\n");
	}
	system("pause");
}