#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 32
void print(int x[]) {
	for (int i = 0; i < N; ++i) {
		if (i == 9) {
			printf(".");
		}
		printf("%d", x[i]);
	}
	printf("\n");
}
void float_complement(float num, int x[]) {
	//��ԭ��
	if (num < 0) {
		x[0] = 1;
		num = -num;
	}
	else {
		x[0] = 0;
	}
	int n = (int)num;
	double m = num - (int)num;
	for (int j = 8; j > 0; --j) {
		x[j] = n % 2;
		n /= 2;
	}
	for (int j = 9; j < 32; ++j) {
		m = m * 2;
		x[j] = (int)m;
		m = m - (int)m;
	}
	//ȡ����
	for (int i = 1; i < 32; ++i) {
		if (x[i] == 1) {
			x[i] = 0;
		}
		else {
			x[i] = 1;
		}
	}
	//ȡ����
	for (int j = 31; j > 0; --j) {
		if (x[j] == 1) {
			x[j] = 0;
		}
		else {
			x[j] = 1;
			break;
		}
	}
}

void Booth(int X[], int Y[], int _X[]) {//Y�ǳ�������ָ�� X�Ǳ���������ָ�� _X�Ǹ��ı������Ĳ���ָ��
	int XY[2 * N];


}
void main() {
	float x, y;
	int X[N], Y[N], _X[N];
	scanf("%f %f", &x, &y);
	float_complement(x, X);
	printf("x����Ϊ:\n");
	print(X);
	float_complement(-x, _X);
	printf("-x����Ϊ:\n");
	print(_X);
	float_complement(y, Y);
	printf("y����Ϊ:\n");
	print(Y);
	//Booth(X, Y, _X);
	system("pause");
}