#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
void stu_aver(double(*a)[6]) {//����ѧ��ƽ���ɼ�
	double sum;
	int i, j;
	for (i = 0; i < 10; ++i) {
		sum = 0.0;
		for (j = 0; j < 5; ++j) {
			sum += a[i][j];
		}
		a[i][5] = sum / 5;
	}
}
void score_aver(double(*a)[6]) {//��Ŀƽ���ɼ�
	double sum;
	int i, j;
	for (i = 0; i < 5; ++i) {
		sum = 0.0;
		for (j = 0; j < 10; ++j) {
			sum += a[j][i];
		}
		a[10][i] = sum / 10;
	}
}
void top_score(char(*c)[20], char(*s)[20], double(*a)[6]) {//��Ŀ���
	int row, col, i, j, flag;
	double top;
	printf("������߷�\n");
	printf("��Ŀ\t����\tѧ��\n");
	for (i = 0; i < 5; ++i) {
		row = 0;
		col = i;
		top = a[0][i];
		flag = 0;
		for (j = 0; j < 10; ++j) {
			if (a[j][i] > top) {
				top = a[j][i];
				row = j;
			}
		}
		printf("%s\t%.2f\t%s\t", c[i], top, s[row]);
		for (j = 0; j < 10; ++j) {
			if (a[j][i] == top) {
				if (flag > 1) {
					printf("%s\t", s[j]);
				}
				++flag;
			}
		}
		putchar('\n');
	}
}
double viriance(double(*a)[6]) {//����
	double x1 = 0;
	double x2 = 0;
	int i;
	for (i = 0; i < 10; ++i) {
		x1 += a[i][6];
		x2 += pow(a[i][6], 2);
	}
	return x2 / 10 - pow(x1 / 10, 2);
}
void input(char(*c)[20], char(*s)[20], double(*a)[6]) {//����
	int i, j;
	for (i = 0; i < 5; ++i) {
		printf("�������%d�ſεĿγ���\n", i + 1);
		scanf("%s", c[i]);
	}
	for (i = 0; i < 10; ++i) {
		printf("�������%d��ѧ��������\n", i + 1);
		scanf("%s", s[i]);
		for (j = 0; j < 5; ++j) {
			printf("����������ѧ���ĳɼ�\n");
			scanf("%lf", &a[i][j]);
		}
	}
	system("cls");
}
void print(char(*c)[20], char(*s)[20], double(*a)[6]) {//��ӡ
	int i, j;
	putchar('\t');
	for (i = 0; i < 5; ++i) {
		printf("%s\t", c[i]);
	}
	printf("ƽ���ɼ�");
	for (i = 0; i < 10; ++i) {
		printf("\n%s\t", s[i]);
		for (j = 0; j < 6; ++j) {
			printf("%.2f\t", a[i][j]);
		}
	}
	printf("\n�γ�\nƽ����\t");
	for (j = 0; j < 5; ++j) {
		printf("%.2f\t", a[i][j]);
	}
	putchar('\n');
}
int main() {
	char c[5][20];//�γ�����
	char s[10][20];//ѧ������
	double a[11][6];//ѧ���ɼ�
	input(c, s, a);//����
	stu_aver(a);//ѧ��ƽ���ɼ�
	score_aver(a);//�γ�ƽ���ɼ�
	print(c, s, a);//��ӡ
	top_score(c, s, a);//�γ���߷�
	printf("����Ϊ:%f\n", viriance(a));//����
	return 0;
}
