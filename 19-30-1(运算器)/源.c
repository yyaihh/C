#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
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
void complement1(int num, char x[]) {//求补码
	printf("%d的补码为:\n", num);
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
	for (int i = 33; i > 2; --i) {
		x[i] = num % 2 + '0';
		num /= 2;
	}
	if (x[0] == '1') {
		complement(x, 33, 2);//求补码
	}
	printf("%s\n", x);
}
void print2(char x[], int m) {//输出结果的原码形式
	int xy = 0;
	if (x[0] == '1' && x[1] == '1') {
		complement(x, m, 2);//求原码
	}
	printf("原码为:\n%s\n", x);
	int i = 3;
	while (x[i] == '0') {
		++i;
	}
	printf("转换为10进制为:");
	if (x[0] == '1' && x[1] == '1') {
		printf("-");
	}
	for (int j = i; j < m + 1; ++j) {
		if (x[j] == '1') {
			xy += (int)pow(2, m - j);
		}
	}
	printf("%d\n", xy);
}
void Add(char X[], char Z[]) {//加法器
	for (int i = 33; i >= 0; --i) {
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
		if (i == 0 && Z[0] != Z[1]) {
			if (Z[0] < Z[1]) {
				printf("正溢出\n");
			}
			else {
				printf("负溢出\n");
			}
		}
	}
}
void Mul(char X[], char Y[],char _Y[], int x) {//乘法
	char Z[36];
	if (x < 0) {
		x = -x;
		strcpy(Z, _Y);
		for (int i = 0; i < x - 1; ++i) {
			Add(_Y, Z);
		}
	}
	else {
		strcpy(Z, Y);
		for (int i = 0; i < x - 1; ++i) {
			Add(Y, Z);
		}
	}
	printf("%s\n", Z);
	print2(Z, 33);
}

void yu(char X[], char Y[]) {
	char Z[36] = { '\0' };
	Z[2] = '.';
	for (int i = 0; i < 34; ++i) {
		if (i == 2) {
			continue;
		}
		if (X[i] == '1' && Y[i] == '1') {
			Z[i] = '1';
		}
		else {
			Z[i] = '0';
		}
	}
	printf("%s\n", Z);
	print2(Z, 33);
}
void huo(char X[], char Y[]) {
	char Z[36] = { '\0' };
	Z[2] = '.';
	for (int i = 0; i < 34; ++i) {
		if (i == 2) {
			continue;
		}
		if (X[i] == '0' && Y[i] == '0') {
			Z[i] = '0';
		}
		else {
			Z[i] = '1';
		}
	}
	printf("%s\n", Z);
	print2(Z, 33);
}
void main() {
	int x, y;
	char X[36] = { '\0' };
	char Y[36] = { '\0' };
	char _Y[36] = { '\0' };
	char Z[36];
	scanf("%d %d", &x, &y);
	complement1(x, X);
	complement1(y, Y);
	complement1(-y, _Y);
	printf("加法运算: %d + %d =\n", x, y);
	strcpy(Z, Y);
	Add(X, Z);
	printf("%s\n", Z);
	print2(Z, 33);
	printf("减法运算: %d - %d =\n", x, y);
	strcpy(Z, _Y);
	Add(X, Z);
	printf("%s\n", Z);
	print2(Z, 33);
	printf("乘法运算: %d * %d =\n", x, y);
	Mul(X, Y, _Y, x);
	printf("与运算: %d & %d =\n", x, y);
	yu(X, Y);
	printf("或运算: %d | %d =\n", x, y);
	huo(X, Y);
	system("pause");
}
