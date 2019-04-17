#pragma once
#include<stdio.h>
#include<time.h>
#define MAX_ROW 15
#define MAX_COL 15
char chessboard[MAX_ROW][MAX_COL];
int y, x;//玩家输入的坐标
int y1, x1;//电脑输入的坐标
int m, n;//检测连续棋子后坐标移动到的位置
int judge(int y, int x) {
	int min = -1;
	int max = 0;
	for (int i = y - 4; i <= y + 4; ++i) {//竖向判断
		if (i > 14) {
			break;
		}
		if (min == -1 && i >= 0) {
			min = i;
		}
		max = i;
	}
	if (max - min >= 5) {
		return 1;
	}
	for (int i = x - 4; i <= x + 4; ++i) {//横向判断
		if (i > 14) {
			break;
		}
		if (min == -1 && i >= 0) {
			min = i;
		}
		max = i;
	}
	if (max - min >= 5) {
		return 1;
	}
	return 0;
}
int CheckGameOver(int N, int y, int x, char ch) {
	int count = 0;
	for (int i = y - 4; i <= y + 4; ++i) {//竖向判断
		if (i < 0) {
			continue;
		}
		if (i > 14) {
			break;
		}
		if (chessboard[i][x] != ch) {
			count = 0;
			continue;
		}
		++count;
		if (count == N) {
			m = i;
			n = x;
			return 1;
		}
	}
	count = 0;
	for (int i = x - 4; i <= x + 4; ++i) {//横向判断
		if (i < 0) {
			continue;
		}
		if (i > 14) {
			break;
		}
		if (chessboard[y][i] != ch) {
			count = 0;
			continue;
		}
		++count;
		if (count == N) {
			m = y;
			n = i;
			return 2;
		}
	}
	count = 0;
	for (int i = y - 4, j = x - 4; i <= y + 4 && j <= x + 4; ++i, ++j) {//对角线判断(左上角到右下角)
		if (i < 0 || j < 0) {
			continue;
		}
		if (i > 14 || j > 14) {
			break;
		}
		if (chessboard[i][j] != ch) {
			count = 0;
			continue;
		}
		++count;
		if (count == N) {
			m = i;
			n = j;
			return 3;
		}
	}
	count = 0;
	for (int i = y - 4, j = x + 4; i <= y + 4 && j >= x - 4; ++i, --j) {//对角线判断(右上角到左下角)
		if (i < 0 || j > 14) {
			continue;
		}
		if (i > 14 || j < 0) {
			break;
		}
		if (chessboard[i][j] != ch) {
			count = 0;
			continue;
		}
		++count;
		if (count == N) {
			m = i;
			n = j;
			return 4;
		}
	}
	return 0;
}
int CheckGameOver1(int N, int y, int x, char ch) {
	int count = 0;
	int ret = 0;
	for (int i = y - 2; i <= y + 2; ++i) {//竖向判断
		if (i < 0 || i == y) {
			continue;
		}
		if (i > 14) {
			break;
		}
		if (chessboard[i][x] != ch) {
			count = 0;
			continue;
		}
		++count;
		if (count == N) {
			ret += 1;
			break;
		}
	}
	count = 0;
	for (int i = x - 2; i <= x + 2; ++i) {//横向判断
		if (i < 0 || i == x) {
			continue;
		}
		if (i > 14) {
			break;
		}
		if (chessboard[y][i] != ch) {
			count = 0;
			continue;
		}
		++count;
		if (count == N) {
			ret += 1;
			break;
		}
	}
	count = 0;
	for (int i = y - 2, j = x - 2; i <= y + 2 && j <= x + 2; ++i, ++j) {//对角线判断(左上角到右下角)
		if (i < 0 || j < 0 || (i == y && j == x)) {
			continue;
		}
		if (i > 14 || j > 14) {
			break;
		}
		if (chessboard[i][j] != ch) {
			count = 0;
			continue;
		}
		++count;
		if (count == N) {
			ret += 1;
			break;
		}
	}
	count = 0;
	for (int i = y - 2, j = x + 2; i <= y + 2 && j >= x - 2; ++i, --j) {//对角线判断(右上角到左下角)
		if (i < 0 || j > 14 || (i == y && j == x)) {
			continue;
		}
		if (i > 14 || j < 0) {
			break;
		}
		if (chessboard[i][j] != ch) {
			count = 0;
			continue;
		}
		++count;
		if (count == N) {
			ret += 1;
			break;
		}
	}
	return ret;
}
int AI_1(int N, int a) {//判断需要的棋子半径为N范围内的棋盘，再选择是否落子
	if (a == 1) {
		if (m - 5 >= 0 && chessboard[m - N][n] == ' ') {
			chessboard[m - N][n] = 'o';
			y1 = m - N;
			x1 = n;
			return 1;
		}
		if (m + 5 - N < MAX_ROW && chessboard[m + 1][n] == ' ') {
			chessboard[m + 1][n] = 'o';
			y1 = m + 1;
			x1 = n;
			return 1;
		}
	}
	else if (a == 2) {
		if (n - 5 >= 0 && chessboard[m][n - N] == ' ') {
			chessboard[m][n - N] = 'o';
			y1 = m;
			x1 = n - N;
			return 1;
		}
		if (n + 5 - N < MAX_COL && chessboard[m][n + 1] == ' ') {
			chessboard[m][n + 1] = 'o';
			y1 = m;
			x1 = n + 1;
			return 1;
		}
	}
	else if (a == 3) {
		if (n - 5 >= 0 && m - 5 > 0 && chessboard[m - N][n - N] == ' ') {
			chessboard[m - N][n - N] = 'o';
			y1 = m - N;
			x1 = n - N;
			return 1;
		}
		if (n + 5 - N < MAX_COL && m + 5 - N < MAX_ROW && chessboard[m + 1][n + 1] == ' ') {
			chessboard[m + 1][n + 1] = 'o';
			y1 = m + 1;
			x1 = n + 1;
			return 1;
		}
	}
	else if (a == 4) {
		if (n - 5 >= 0 && m + 5 - N < MAX_ROW && chessboard[m + 1][n - 1] == ' ') {
			chessboard[m + 1][n - 1] = 'o';
			y1 = m + 1;
			x1 = n - 1;
			return 1;
		}
		if (m - 5 >= 0 && n + 5 - N < MAX_COL && chessboard[m - N][n + N] == ' ') {
			chessboard[m - N][n + N] = 'o';
			y1 = m - N;
			x1 = n + N;
			return 1;
		}
	}
	return 0;
}

int AI_2(int a, int b, char ch) {//判断 oo o 或  o oo类型的落子(判断 ooo o 或  o ooo类型的落子)
	if (a == 1) {
		if (m + b < MAX_ROW && chessboard[m + 1][n] == ' ' && chessboard[m + b][n] == ch) {
			chessboard[m + 1][n] = 'o';
			y1 = m + 1;
			x1 = n;
			return 1;
		}
		else if (m - b - 1 >= 0 && chessboard[m - b][n] == ' ' && chessboard[m - b - 1][n] == ch) {
			chessboard[m - b][n] = 'o';
			y1 = m - b;
			x1 = n;
			return 1;
		}
	}
	else if (a == 2) {
		if (n + b < MAX_COL && chessboard[m][n + 1] == ' ' && chessboard[m][n + b] == ch) {
			chessboard[m][n + 1] = 'o';
			y1 = m;
			x1 = n + 1;
			return 1;
		}
		if (n - b - 1 >= 0 && chessboard[m][n - b] == ' ' && chessboard[m][n - b - 1] == ch) {
			chessboard[m][n - b] = 'o';
			y1 = m;
			x1 = n - b;
			return 1;
		}
	}
	else if (a == 3) {
		if (n + b < MAX_COL && m + b < MAX_ROW && chessboard[m + 1][n + 1] == ' ' && chessboard[m + b][n + b] == ch) {
			chessboard[m + 1][n + 1] = 'o';
			y1 = m + 1;
			x1 = n + 1;
			return 1;
		}
		if (n - b - 1 >= 0 && m - b - 1 >= 0 && chessboard[m - b][n - b] == ' ' && chessboard[m - b - 1][n - b - 1] == ch) {
			chessboard[m - b][n - b] = 'o';
			y1 = m - b;
			x1 = n - b;
			return 1;
		}
	}
	else if (a == 4) {
		if (m + b < MAX_ROW && n - b >= 0 && chessboard[m + 1][n - 1] == ' ' && chessboard[m + b][n - b] == ch) {
			chessboard[m + 1][n - 1] = 'o';
			y1 = m + 1;
			x1 = n - 1;
			return 1;
		}
		if (n + b - 1 < MAX_COL && m - b - 1 >= 0 && chessboard[m - b][n + b] == ' ' && chessboard[m - b - 1][n + b - 1] == ch) {
			chessboard[m - b][n + b] = 'o';
			y1 = m - b;
			x1 = n + b;
			return 1;
		}
	}
	return 0;
}

int AI_3(int a, int b) {//判断  ooo  类型落子
	if (a == 1) {
		if (m + 1 < 15 && m - b >= 0 && chessboard[m + 1][n] == ' ' && chessboard[m - b][n] == ' ') {
			if (m + 5 - b < 15) {
				chessboard[m + 1][n] = 'o';
				y1 = m + 1;
				x1 = n;
				return 1;
			}
			else if (m - b >= 0) {
				chessboard[m - b][n] = 'o';
				y1 = m - b;
				x1 = n;
				return 1;
			}
		}

	}
	else if (a == 2) {
		if (n + 1 < 15 && n - b >= 0 && chessboard[m][n + 1] == ' ' && chessboard[m][n - b] == ' ') {
			if (n + 5 - b < 15) {
				chessboard[m][n + 1] = 'o';
				y1 = m;
				x1 = n + 1;
				return 1;
			}
			else if (n - b >= 0) {
				chessboard[m][n - b] = 'o';
				y1 = m;
				x1 = n - b;
				return 1;
			}
		}
	}
	else if (a == 3) {
		if (n + 1 < 15 && m + 1 < 15 && n - b >= 0 && m - b > 0 && chessboard[m + 1][n + 1] == ' ' && chessboard[m - b][n - b] == ' ') {
			if (n + 5 - b < MAX_COL && m + 5 - b < 15) {
				chessboard[m + 1][n + 1] = 'o';
				y1 = m + 1;
				x1 = n + 1;
				return 1;
			}
			if (n - b >= 0 && m - b >= 0) {
				chessboard[m - b][n - b] = 'o';
				y1 = m - b;
				x1 = n - b;
				return 1;
			}
			if (judge(m, n) == 1) {
				if (m + 1 < MAX_ROW && n + 1 < MAX_COL) {
					chessboard[m + 1][n] = 'o';
					y1 = m + 1;
					x1 = n + 1;
					return 1;
				}
				if (m - b >= 0 && n - b >= 0) {
					chessboard[m - b][n] = 'o';
					y1 = m - b;
					x1 = n - b;
					return 1;
				}
			}
		}
	}
	else if (a == 4) {
		if (n + b < 15 && m - b >= 0 && chessboard[m + 1][n - 1] == ' ' && chessboard[m - b][n + b] == ' ') {
			if (m + 5 - b < MAX_ROW && n - 1 >= 0) {
				chessboard[m + 1][n - 1] = 'o';
				y1 = m + 1;
				x1 = n - 1;
				return 1;
			}
			if (n + 5 - b < MAX_COL && m - b >= 0) {
				chessboard[m - b][n + b] = 'o';
				y1 = m - b;
				x1 = n + b;
				return 1;
			}
			if (judge(m, n) == 1) {
				if (m + 1 < MAX_ROW && n - 1 >= 0) {
					chessboard[m + 1][n - 1] = 'o';
					y1 = m + 1;
					x1 = n - 1;
					return 1;
				}
				if (m - b >= 0 && n + b < MAX_COL) {
					chessboard[m - b][n + b] = 'o';
					y1 = m - b;
					x1 = n + b;
					return 1;
				}
			}
		}
	}
	return 0;
}
int AI_5(int i, int j, char ch) {//判断 x/o  x/o 落子到中间
	if (i + 2 < MAX_ROW && chessboard[i][j] == ch && chessboard[i + 1][j] == ' ' && chessboard[i + 2][j] == ch) {
		chessboard[i + 1][j] = 'o';
		y1 = i + 1;
		x1 = j;
		return 1;
	}
	if (j + 2 < MAX_COL && chessboard[i][j] == ch && chessboard[i][j + 1] == ' ' && chessboard[i][j + 2] == ch) {
		chessboard[i][j + 1] = 'o';
		y1 = i;
		x1 = j + 1;
		return 1;
	}
	if (j + 2 < MAX_COL && i + 2 < MAX_ROW && chessboard[i][j] == ch && chessboard[i + 1][j + 1] == ' ' && chessboard[i + 2][j + 2] == ch) {
		chessboard[i + 1][j + 1] = 'o';
		y1 = i + 1;
		x1 = j + 1;
		return 1;
	}
	if (j - 2 >= 0 && i + 2 < MAX_ROW && chessboard[i][j] == ch && chessboard[i + 1][j - 1] == ' ' && chessboard[i + 2][j - 2] == ch) {
		chessboard[i + 1][j - 1] = 'o';
		y1 = i + 1;
		x1 = j - 1;
		return 1;
	}
	return 0;
}
int AI_6(char ch) {
	for (int i = 2; i < MAX_ROW; ++i) {
		for (int j = 2; j < MAX_COL; ++j) {
			if (chessboard[i][j] == ' ' && CheckGameOver1(2, i, j, ch) > 1) {
				chessboard[i][j] = 'o';
				return 1;
			}
		}
	}
	return 0;
}
int AI_4() {//便利棋盘找出适合落子的位置落子
	srand((unsigned int)time(0));
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (chessboard[i][j] == 'o' && AI_1(4, CheckGameOver(4, i, j, 'o')) == 1) {//如果有4个连在一起的o则连接第5个o
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (chessboard[i][j] == 'o' && AI_3(CheckGameOver(3, i, j, 'o'), 3) == 1) {//出现  ooo  连接第四个o
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (chessboard[i][j] == 'o' && AI_2(CheckGameOver(2, i, j, 'o'), 2, 'o') == 1) {//出现oo o时在空处落子
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (chessboard[i][j] == 'x' && AI_2(CheckGameOver(2, i, j, 'x'), 2, 'x') == 1) {//出现xx x时在空处落子
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (chessboard[i][j] == 'x' && AI_3(CheckGameOver(3, i, j, 'x'), 3) == 1) {//出现  xxx  连接第四个o
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (chessboard[i][j] == 'o' && AI_1(3, CheckGameOver(3, i, j, 'o')) == 1) {//如果有3个连在一起的o则连接第4个o
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (chessboard[i][j] == 'x' && AI_1(3, CheckGameOver(3, i, j, 'x')) == 1) {//如果有3个连在一起的x则连接第4个o
				return 1;
			}
		}
	}
	if (AI_6('o') == 1) {//防止玩家连成两个三子对角
		return 1;
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (AI_5(i, j, 'x') == 1) {//若出现x x则落子o在中间
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (AI_3(CheckGameOver(2, i, j, 'o'), 2) == 1) {//如果有 oo 则落子
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (AI_5(i, j, 'o') == 1) {//若出现o o则落子o在中间
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (chessboard[i][j] == 'o' && AI_1(2, CheckGameOver(2, i, j, 'o')) == 1) {// 如果有2个连在一起的o则连接第3个o
				return 1;
			}
		}
	}
	int row = MAX_ROW / 2;
	int col = MAX_COL / 2;
	for (int i = 0; i <= 7; ++i) {
		for (int j = 0; j < 2 * i - 1; ++j) {
			if (chessboard[row][col++] == 'o') {// 如果有1个o则连接第2个o
				m = row;
				n = col - 1;
				if (AI_1(1, 4) == 1) {//随机竖向或者横向或者对角线落子
					return 1;
				}
			}
		}
		for (int j = 0; j < 2 * i; ++j) {
			if (chessboard[row++][col] == 'o') {// 如果有1个o则连接第2个o
				m = row - 1;
				n = col;
				if (AI_1(1, 4) == 1) {//随机竖向或者横向或者对角线落子
					return 1;
				}
			}
		}
		for (int j = 0; j < 2 * i; ++j) {
			if (chessboard[row][col--] == 'o') {// 如果有1个o则连接第2个o
				m = row;
				n = col + 1;
				if (AI_1(1, rand() % 4 + 1) == 1) {//随机竖向或者横向或者对角线落子
					return 1;
				}
			}
		}
		for (int j = 0; j < 2 * i + 1; ++j) {
			if (chessboard[row--][col] == 'o') {// 如果有1个o则连接第2个o
				m = row + 1;
				n = col;
				if (AI_1(1, rand() % 4 + 1) == 1) {//随机竖向或者横向或者对角线落子
					return 1;
				}
			}
		}
	}
	return 0;
}
