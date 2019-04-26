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
	int e;//ָ��
	int js;//����
	int count = 0;
	if (num >= 0) {
		x[0] = 0;
	}
	else {
		x[0] = 1;
		num = -num;

	}
	//��ԭ��
	int n = (int)num;
	float m = num - (int)num;
	do {
		++count;
		n /= 2;
	} while (n);
	e = count - 1;
	js = 127 + e;
	for (int j = 8; j > 0; --j) {//������ŵ�������
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
		for (int i = 1; i < 32; ++i) {//ȡ����
			if (x[i] == 1) {
				x[i] = 0;
			}
			else {
				x[i] = 1;
			}
		}
		for (int j = 31; j > 0; --j) {//ȡ����
			if (x[j] == 1) {
				x[j] = 0;
				continue;
			}
			x[j] = 1;
			break;
		}
	}

}
float complement_float(int XY[]) {//������ת��Ϊʮ����
	int js = 0;//����
	int e;//ָ��
	float xy = 0;
	float xs = 1;
	for (int j = 31; j > 0; --j) {//����
		if (XY[j] == 0) {
			XY[j] = 1;
			continue;
		}
		XY[j] = 0;
		break;
	}
	for (int i = 1; i < 32; ++i) {//��ԭ��
		if (XY[i] == 1) {
			XY[i] = 0;
		}
		else {
			XY[i] = 1;
		}
	}
	//��ʮ����
	for (int i = 1; i < 9; ++i) {
		if (XY[i] == 1) {
			js += (int)pow(2, 8 - i);
		}
	}
	e = js - 127;
	int count = e - 1;
	//��������
	if (e != 0) {
		xy += (int)pow(2, e);
	}
	for (int i = 9; i < 9 + e; ++i) {
		if (XY[i] == 1) {
			xy += (int)pow(2, count);
		}
		--count;
	}
	for (int k = N - 1; k >= 9 + e; --k) {//С������
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
void Booth(int X[], int Y[], int _X[]) {//Y�ǳ������� X�Ǳ��������� _X�Ǹ��ı������Ĳ���
	int XY[N] = { 0 };
	int y_ = 0;
	for (int i = N - 1; i >= 0;--i) {
		if (Y[i] == X[i]) {//00��11
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
							printf("���\n");
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
							printf("���\n");
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
	printf("x����Ϊ:\n");
	print(X);
	float_complement(y, Y);
	printf("y����Ϊ:\n");
	print(Y);
	float_complement(-x, _X);
	printf("-x����Ϊ:\n");
	print(_X);
	Booth(X, Y, _X);
	system("pause");
}
