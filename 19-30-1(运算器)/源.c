#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void complement(char x[], int m, int n) {//��������õ�ԭ������������
	for (int i = n + 1; i < m + 1; ++i) {//ȡ����
		if (x[i] == '1') {
			x[i] = '0';
		}
		else {
			x[i] = '1';
		}
	}
	for (int j = m; j > n; --j) {//ȡ����
		if (x[j] == '1') {
			x[j] = '0';
			continue;
		}
		x[j] = '1';
		break;
	}
}
void complement1(int num, char x[]) {//����
	printf("%d�Ĳ���Ϊ:\n", num);
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
	//��ԭ��
	for (int i = 33; i > 2; --i) {
		x[i] = num % 2 + '0';
		num /= 2;
	}
	if (x[0] == '1') {
		complement(x, 33, 2);//����
	}
	printf("%s\n", x);
}
void print2(char x[], int m) {//��������ԭ����ʽ
	int xy = 0;
	if (x[0] == '1' && x[1] == '1') {
		complement(x, m, 2);//��ԭ��
	}
	printf("ԭ��Ϊ:\n%s\n", x);
	int i = 3;
	while (x[i] == '0') {
		++i;
	}
	printf("ת��Ϊ10����Ϊ:");
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
void Add(char X[], char Z[]) {//�ӷ���
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
				printf("�����\n");
			}
			else {
				printf("�����\n");
			}
		}
	}
}
void Mul(char X[], char Y[],char _Y[], int x) {//�˷�
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
	printf("�ӷ�����: %d + %d =\n", x, y);
	strcpy(Z, Y);
	Add(X, Z);
	printf("%s\n", Z);
	print2(Z, 33);
	printf("��������: %d - %d =\n", x, y);
	strcpy(Z, _Y);
	Add(X, Z);
	printf("%s\n", Z);
	print2(Z, 33);
	printf("�˷�����: %d * %d =\n", x, y);
	Mul(X, Y, _Y, x);
	printf("������: %d & %d =\n", x, y);
	yu(X, Y);
	printf("������: %d | %d =\n", x, y);
	huo(X, Y);
	system("pause");
}
