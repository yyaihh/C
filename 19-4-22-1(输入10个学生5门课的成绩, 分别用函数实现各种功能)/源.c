#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define M 10
#define N 5
double stu_aver(int i, int a[M][N]) {//����ѧ��ƽ���ɼ�
	double sum = 0;
	for (int j = 0; j < N; ++j) {
		sum += a[i][j];
	}
	return sum / N;
}
void score_aver(int a[M][N]) {//��Ŀƽ���ɼ�
	double sum;
	for (int i = 0; i < N; ++i) {
		sum = 0;
		printf("��%d�ſε�ƽ����Ϊ:\n", i + 1);
		for (int j = 0; j < M; ++j) {
			sum += a[j][i];
		}
		printf("%f\n", sum / M);
	}
}
void top_score(int a[M][N]) {//��߷�
	int top = a[0][0];
	int row = 0;
	int col = 0;
	int i, j;
	for (i = 0; i < M; ++i) {
		for (j = 0; j < N; ++j) {
			if (a[i][j] > top) {
				top = a[i][j];
				row = i;
				col = j;
			}
		}
	}
	printf("��%d��ѧ���ĵ�%d�ųɼ����,Ϊ%d��\n",row + 1,col + 1, top);
}
double viriance(int a[M][N] ) {//����
	double x1 = 0;
	double x2 = 0;
	for (int i = 0; i < M; ++i)
	{
		x1 += stu_aver(i, a);
		x2 += pow(stu_aver(i, a), 2);
	}
	return x2 / M - pow(x1 / M, 2);
}
void main() {
	int stu_score[M][N] = { 0 };
	for (int i = 0; i < M; ++i) {
		printf("�������%d��ѧ�������ųɼ�\n", i + 1);
		for (int j = 0; j < N; ++j) {
			printf("��%d�ųɼ�\n", j + 1);
			scanf("%d", &stu_score[i][j]);
			stu_score[i][j] = 1;
		}
		system("cls");
	}
	/*int stu_score[10][5] = { {70,80,90,40,50},
								{60,70,80,30,50},
								{90,80,90,93,94},
								{100,80,96,95,94},
								{50,60,70,90,67},
								{71,83,90,40,50},
								{67,70,88,30,50},
								{90,86,90,93,94},
								{100,80,93,95,94},
								{50,60,50,90,67} };*///������
	for (int i = 0; i < M; ++i) {
		printf("student%d:\n", i + 1);
		for (int j = 0; j < N; ++j) {
			printf("%d\t", stu_score[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < M; ++i) {
		printf("��%dλѧ����ƽ���ɼ�Ϊ:\n%f\n", i + 1, stu_aver(i, stu_score));
	}
	score_aver(stu_score);
	top_score(stu_score);
	printf("����Ϊ:%f\n", viriance(stu_score));
	system("pause");
}
