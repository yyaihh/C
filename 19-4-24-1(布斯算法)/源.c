#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int a = 0;//x的位数
int b = 0;//y的位数
void print(char Y[]) {//输出乘数数组
	for (int i = 0; i < b + 1; ++i) {
		if (i == 1) {
			printf(".");
		}
		printf("%c", Y[i]);
	}
}
void complement(char x[], int m, int n) {//根据已求得的原码数组求补码码
	for (int i = n + 1; i < m + 1; ++i) {//取反码
		if (x[i] == '1') {
			x[i] = '0';
		}
		else {
			x[i] = '1';
		}
	}
	for (int j = m; j > n; --j) {//取补码
		if (x[j] == '1') {
			x[j] = '0';
			continue;
		}
		x[j] = '1';
		break;
	}
}
void complement1(int num, char x[], int m) {//求被乘数和负的被乘数的补码
	if (num >= 0) {
		x[0] = '0';
		x[1] = '0';
	}
	else {
		x[0] = '1';
		x[1] = '1';
		num = -num;

	}
	x[2] = '.';
	//求原码
	for (int i = 2 + m; i > 2; --i) {
		x[i] = num % 2 + '0';
		num /= 2;
	}
	if (x[0] == '1') {
		complement(x, m + 2, 2);//求补码
	}
	printf("%s\n", x);
}

void complement2(int num, char x[], int m) {//求乘数补码
	if (num >= 0) {
		x[0] = '0';
	}
	else {
		x[0] = '1';
		num = -num;

	}
	//求原码
	for (int i = m; i > 0; --i) {
		x[i] = num % 2 + '0';
		num /= 2;
	}
	if (x[0] == '1') {
		complement(x, m, 0);//求补码
	}
	print(x);
	printf("\n");
}
void print2(char x[], int m) {//输出结果的原码形式
	int xy = 0;
	if (x[0] == '1') {
		complement(x, m, 0);//求补码
		printf("-");
	}
	int i = 3;
	while (x[i] == '0') {
		++i;
	}
	int count = 0;
	for (int j = i; j < m + 1; ++j) {
		printf("%c", x[j]);
	}
	printf("\n");
	printf("转换为10进制为:");
	if (x[0] == '1') {
		printf("-");
	}
	for (int j = i; j < m + 1; ++j) {
		if (x[j] == '1') {
			xy += (int)pow(2, m - j);
		}
	}
	printf("%d\n", xy);
}
void Add(char Z[], char X[]) {//补码数组相加
	for (int i = a + 2; i >= 0; --i) {
		if (i == 2) {
			continue;
		}
		if (Z[i] + X[i] - '0' == '2') {
			Z[i] = '0';
			for (int j = i - 1; j >= 0; --j) {
				if (Z[j] == '0') {
					Z[j] = '1';
					break;
				}
				else if (Z[j] == '1') {
					Z[j] = '0';
				}
			}
		}
		else {
			Z[i] = Z[i] + X[i] - '0';
		}
	}
}
void Booth(int x, int y) {//
	char X[36] = { '\0' };
	char Y[34] = { '\0' };
	char _X[36] = { '\0' };
	char Z[36] = { '\0' };
	for (int i = 0; i < a + 3; ++i) {
		if (i == 2) {
			Z[i] = '.';
			continue;
		}
		Z[i] = '0';
	}
	printf("%d补码为:", x);
	complement1(x, X, a);
	printf("%d补码为:", y);
	complement2(y, Y, b);
	printf("%d补码为:", -x);
	complement1(-x, _X, a);
	char yb_1 = '0';
	printf("\n");
	for (int i = 0; i < b + 1; ++i) {
		if (Y[b] == yb_1) {
		}
		else if (Y[b] < yb_1) {
			Add(Z, X);
			printf("                    +X\n%s\n", X);
		}
		else {
			Add(Z, _X);
			printf("                   +_X\n%s\n", _X);
		}
		printf("%s  ", Z);
		print(Y);
		printf("  %c\n", yb_1);
		if (i < b) {//Y[]与Z[]右移
			printf("右移\n");
			yb_1 = Y[b];
			for (int i = b; i > 0; --i) {
				Y[i] = Y[i - 1];
			}
			Y[0] = Z[a + 2];
			for (int i = a + 2; i > 0; --i) {
				if (i == 3) {
					Z[i] = Z[i - 2];
					continue;
				}
				if (i == 2) {
					continue;
				}
				Z[i] = Z[i - 1];
			}
			printf("%s  ", Z);
			print(Y);
			printf("  %c\n", yb_1);
		}
	}
	char XY[70] = { '\0' };
	strcpy(XY, Z);
	for (int i = a + 3; i < a + 3 + b; ++i) {
		XY[i] = Y[i - a - 3];
	}
	printf("x*y的补码为%s\n", XY);
	print2(XY, a + b + 2);
}
void main() {
	int x, y, n;
	scanf("%d %d", &x, &y);
	n = x;
	while (n) {
		++a;
		n /= 2;
	}
	n = y;
	while (n) {
		++b;
		n /= 2;
	}
	Booth(x, y);
	system("pause");
}
