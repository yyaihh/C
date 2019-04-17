#pragma once
#include<stdio.h>
#include<time.h>
#define MAX_ROW 15
#define MAX_COL 15
char chessboard[MAX_ROW][MAX_COL];
int y, x;//������������
int y1, x1;//�������������
int m, n;//����������Ӻ������ƶ�����λ��
int judge(int y, int x) {
	int min = -1;
	int max = 0;
	for (int i = y - 4; i <= y + 4; ++i) {//�����ж�
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
	for (int i = x - 4; i <= x + 4; ++i) {//�����ж�
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
	for (int i = y - 4; i <= y + 4; ++i) {//�����ж�
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
	for (int i = x - 4; i <= x + 4; ++i) {//�����ж�
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
	for (int i = y - 4, j = x - 4; i <= y + 4 && j <= x + 4; ++i, ++j) {//�Խ����ж�(���Ͻǵ����½�)
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
	for (int i = y - 4, j = x + 4; i <= y + 4 && j >= x - 4; ++i, --j) {//�Խ����ж�(���Ͻǵ����½�)
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
	for (int i = y - 2; i <= y + 2; ++i) {//�����ж�
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
	for (int i = x - 2; i <= x + 2; ++i) {//�����ж�
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
	for (int i = y - 2, j = x - 2; i <= y + 2 && j <= x + 2; ++i, ++j) {//�Խ����ж�(���Ͻǵ����½�)
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
	for (int i = y - 2, j = x + 2; i <= y + 2 && j >= x - 2; ++i, --j) {//�Խ����ж�(���Ͻǵ����½�)
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
int AI_1(int N, int a) {//�ж���Ҫ�����Ӱ뾶ΪN��Χ�ڵ����̣���ѡ���Ƿ�����
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

int AI_2(int a, int b, char ch) {//�ж� oo o ��  o oo���͵�����(�ж� ooo o ��  o ooo���͵�����)
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

int AI_3(int a, int b) {//�ж�  ooo  ��������
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
int AI_5(int i, int j, char ch) {//�ж� x/o  x/o ���ӵ��м�
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
int AI_4() {//���������ҳ��ʺ����ӵ�λ������
	srand((unsigned int)time(0));
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (chessboard[i][j] == 'o' && AI_1(4, CheckGameOver(4, i, j, 'o')) == 1) {//�����4������һ���o�����ӵ�5��o
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (chessboard[i][j] == 'o' && AI_3(CheckGameOver(3, i, j, 'o'), 3) == 1) {//����  ooo  ���ӵ��ĸ�o
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (chessboard[i][j] == 'o' && AI_2(CheckGameOver(2, i, j, 'o'), 2, 'o') == 1) {//����oo oʱ�ڿմ�����
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (chessboard[i][j] == 'x' && AI_2(CheckGameOver(2, i, j, 'x'), 2, 'x') == 1) {//����xx xʱ�ڿմ�����
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (chessboard[i][j] == 'x' && AI_3(CheckGameOver(3, i, j, 'x'), 3) == 1) {//����  xxx  ���ӵ��ĸ�o
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (chessboard[i][j] == 'o' && AI_1(3, CheckGameOver(3, i, j, 'o')) == 1) {//�����3������һ���o�����ӵ�4��o
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (chessboard[i][j] == 'x' && AI_1(3, CheckGameOver(3, i, j, 'x')) == 1) {//�����3������һ���x�����ӵ�4��o
				return 1;
			}
		}
	}
	if (AI_6('o') == 1) {//��ֹ��������������ӶԽ�
		return 1;
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (AI_5(i, j, 'x') == 1) {//������x x������o���м�
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (AI_3(CheckGameOver(2, i, j, 'o'), 2) == 1) {//����� oo ������
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (AI_5(i, j, 'o') == 1) {//������o o������o���м�
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (chessboard[i][j] == 'o' && AI_1(2, CheckGameOver(2, i, j, 'o')) == 1) {// �����2������һ���o�����ӵ�3��o
				return 1;
			}
		}
	}
	int row = MAX_ROW / 2;
	int col = MAX_COL / 2;
	for (int i = 0; i <= 7; ++i) {
		for (int j = 0; j < 2 * i - 1; ++j) {
			if (chessboard[row][col++] == 'o') {// �����1��o�����ӵ�2��o
				m = row;
				n = col - 1;
				if (AI_1(1, 4) == 1) {//���������ߺ�����߶Խ�������
					return 1;
				}
			}
		}
		for (int j = 0; j < 2 * i; ++j) {
			if (chessboard[row++][col] == 'o') {// �����1��o�����ӵ�2��o
				m = row - 1;
				n = col;
				if (AI_1(1, 4) == 1) {//���������ߺ�����߶Խ�������
					return 1;
				}
			}
		}
		for (int j = 0; j < 2 * i; ++j) {
			if (chessboard[row][col--] == 'o') {// �����1��o�����ӵ�2��o
				m = row;
				n = col + 1;
				if (AI_1(1, rand() % 4 + 1) == 1) {//���������ߺ�����߶Խ�������
					return 1;
				}
			}
		}
		for (int j = 0; j < 2 * i + 1; ++j) {
			if (chessboard[row--][col] == 'o') {// �����1��o�����ӵ�2��o
				m = row + 1;
				n = col;
				if (AI_1(1, rand() % 4 + 1) == 1) {//���������ߺ�����߶Խ�������
					return 1;
				}
			}
		}
	}
	return 0;
}
