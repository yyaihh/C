#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define M 10
#define N 5
double stu_aver(int i, int a[M][N]) {//计算学生平均成绩
	double sum = 0;
	for (int j = 0; j < N; ++j) {
		sum += a[i][j];
	}
	return sum / N;
}
void score_aver(int a[M][N]) {//科目平均成绩
	double sum;
	for (int i = 0; i < N; ++i) {
		sum = 0;
		printf("第%d门课的平均分为:\n", i + 1);
		for (int j = 0; j < M; ++j) {
			sum += a[j][i];
		}
		printf("%f\n", sum / M);
	}
}
void top_score(int a[M][N]) {//最高分
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
	printf("第%d个学生的第%d门成绩最高,为%d分\n",row + 1,col + 1, top);
}
double viriance(int a[M][N] ) {//方差
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
		printf("请输入第%d个学生的五门成绩\n", i + 1);
		for (int j = 0; j < N; ++j) {
			printf("第%d门成绩\n", j + 1);
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
								{50,60,50,90,67} };*///调试用
	for (int i = 0; i < M; ++i) {
		printf("student%d:\n", i + 1);
		for (int j = 0; j < N; ++j) {
			printf("%d\t", stu_score[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < M; ++i) {
		printf("第%d位学生的平均成绩为:\n%f\n", i + 1, stu_aver(i, stu_score));
	}
	score_aver(stu_score);
	top_score(stu_score);
	printf("方差为:%f\n", viriance(stu_score));
	system("pause");
}
