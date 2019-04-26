#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 32
void print(int x[]) {
	for (int i = 0; i < N; ++i) {
		printf("%d", x[i]);
	}
	printf("\n");
}
void float_complement(float num, int x[]) {
	int e;//指数
	int js;//阶码
	int count = 0;
	if (num >= 0) {
		x[0] = 0;
	}
	else {
		x[0] = 1;
		num = -num;

	}
	//求原码
	int n = (int)num;
	float m = num - (int)num;
	do {
		++count;
		n /= 2;
	} while (n);
	e = count - 1;
	js = 127 + e;
	for (int j = 8; j > 0; --j) {//将阶码放到数组中
		x[j] = js % 2;
		js /= 2;
	}
	n = (int)num;
	for (int j = 8 + e; j > 8; --j) {//
		x[j] = n % 2;
		n /= 2;
	}
	for (int j = 8 + count; j < 32; ++j) {
		m = m * 2;
		x[j] = (int)m;
		m = m - (int)m;
	}
	if (x[0] == 1) {
		for (int i = 1; i < 32; ++i) {//取反码
			if (x[i] == 1) {
				x[i] = 0;
			}
			else {
				x[i] = 1;
			}
		}
		for (int j = 31; j > 0; --j) {//取补码
			if (x[j] == 1) {
				x[j] = 0;
				continue;
			}
			x[j] = 1;
			break;
		}
	}

}
float complement_float(int XY[]) {//将补码转化为十进制
	int js = 0;//阶码
	int e;//指数
	float xy = 0;
	float xs = 1;
	for (int j = 31; j > 0; --j) {//求反码
		if (XY[j] == 0) {
			XY[j] = 1;
			continue;
		}
		XY[j] = 0;
		break;
	}
	for (int i = 1; i < 32; ++i) {//求原码
		if (XY[i] == 1) {
			XY[i] = 0;
		}
		else {
			XY[i] = 1;
		}
	}
	//求十进制
	for (int i = 1; i < 9; ++i) {
		if (XY[i] == 1) {
			js += (int)pow(2, 8 - i);
		}
	}
	e = js - 127;
	int count = e - 1;
	//整数部分
	if (e != 0) {
		xy += (int)pow(2, e);
	}
	for (int i = 9; i < 9 + e; ++i) {
		if (XY[i] == 1) {
			xy += (int)pow(2, count);
		}
		--count;
	}
	for (int k = N - 1; k >= 9 + e; --k) {//小数部分
		if (XY[k] == 1) {
			for (int j = k; j >= 9 + e; --j) {
				if (XY[j] == 1) {
					xs /= 2;
					if (j != 9 + e && XY[j - 1] == 1) {
						xs += 1;
					}
				}
				else {
					xs /= 2;
					if (j != 9 + e && XY[j - 1] == 1) {
						xs += 1;
					}
				}
			}
			break;
		}
	}
	if (XY[0] == 1) {
		return -(xy + xs);
	}
	return xy + xs;
}
inline  dextroposition(int y_, int Y[], int XY[]) {
	for (int k = N - 1; k > 0; --k) {
		y_ = XY[k];
		XY[k] = XY[k - 1];
		Y[k] = Y[k - 1];
	}
}
void Booth(int X[], int Y[], int _X[]) {//Y是乘数数组 X是被乘数补码 _X是负的被乘数的补码
	int XY[N] = { 0 };
	int y_ = 0;
	for (int i = N - 1; i >= 0;--i) {
		if (Y[i] == X[i]) {//00或11
		}
		else if (Y[i] - y_ == 1) {//10
			for (int k = 0; k < N; ++k) {
				if (XY[k] + _X[k] == 2) {
					XY[k] = 0;
					for (int j = k + 1; k < N; ++j) {
						if (XY[j] == 0) {
							XY[j] = 1;
							break;
						}
						if (j == N - 1) {
							printf("溢出\n");
							return;
						}
					}
					continue;
				}
				XY[k] = XY[k] + _X[k];
			}
		}
		else {//01
			for (int k = 0; k < N; ++k) {
				if (XY[k] + X[k] == 2) {
					XY[k] = 0;
					for (int j = k + 1; k < N; ++j) {
						if (XY[j] == 0) {
							XY[j] = 1;
							break;
						}
						if (j == N - 1) {
							printf("溢出\n");
							return;
						}
					}
					break;
				}
				XY[k] = XY[k] + X[k];
			}
		}
		if (i != 0) {
			dextroposition(y_, Y, XY);
		}
	}
	print(XY);
	printf("%f\n", complement_float(XY));
}
void main() {
	float x, y;
	int X[N], Y[N], _X[N];
	scanf("%f %f", &x, &y);
	float_complement(x, X);
	printf("x补码为:\n");
	print(X);
	float_complement(y, Y);
	printf("y补码为:\n");
	print(Y);
	float_complement(-x, _X);
	printf("-x补码为:\n");
	print(_X);
	Booth(X, Y, _X);
	system("pause");
}
