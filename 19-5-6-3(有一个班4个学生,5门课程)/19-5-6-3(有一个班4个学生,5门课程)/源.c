#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#define N 4//N个学生
#define M 6//M - 1门课程
void print(int i, double(*p)[M]) {
	printf("学号\t");
	for (int k = 0; k < M - 1; ++k) {
		printf("成绩%d\t", k + 1);
	}
	printf("\n");
	for (int j = 0; j < M; ++j) {
		if (j == 0) {
			printf("%.0f\t", *(*(p + i) + j));
		}
		else {
			printf("%.3f\t", *(*(p + i) + j));
		}
	}
}
double class1_aver(int n, double(*p)[M]) {//计算第n门课的成绩
	double sum = 0;
	for (int i = 0; i < N; ++i) {
		sum += *(*(p + i) + n);
	}
	return sum / N;
}
void fail(double(*p)[M]) {
	int count = 0;
	double sum = 0;
	for (int i = 0; i < N; ++i) {
		count = 0;
		sum = 0;
		for (int j = 1; j < M; ++j) {
			if (*(*(p + i) + j) < 60.0) {
				count += 1;
			}
		}
		if (count >= 2) {
			for (int j = 1; j < M; ++j) {
				sum += *(*(p + i) + j);
			}
			printf("如下该学生有超过两门课程成绩不及格\n");
			print(i, p);
			printf("\n平均成绩为%.3f\n\n", sum / (M - 1));
		}
	}
}
void excellent(double(*p)[M]) {
	int count = 0;
	double sum = 0;
	for (int i = 0; i < N; ++i) {
		count = 0;
		sum = 0;
		for (int j = 1; j < M; ++j) {
			sum += *(*(p + i) + j);
			if (*(*(p + i) + j) >= 85) {
				count += 1;
			}
		}
		if (count == M - 1) {
			printf("如下该学生有所有成绩均超过85分\n");
			print(i, p);
			printf("\n平均成绩为%.3f\n", sum / (M - 1));
		}
		else if (sum / (M - 1) >= 90) {
			printf("如下该学生有所有成绩平均分超过90分\n");
			print(i, p);
			printf("\n平均成绩为%.3f\n", sum / (M - 1));
		}
	}
}
void main() {
	double stu[N][M];
	double(*p)[M] = stu;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (j == 0) {
				printf("请输入第%d名学生的学号\n", i + 1);
				while (1) {
					scanf("%lf", *(p + i) + j);
					if (i == 0) {
						break;
					}
					if (*(*(p + i) + j) != *(*(p + i - 1) + j)){
						break;
					}
					printf("您的输入的学号与第%d名学生学号相同都为%.0f,请重新输入\n", i, *(*(p + i - 1) + j));
				}
				continue;
			}
			printf("请输入该学生的第%d门成绩\n", j);
			scanf("%lf", *(p + i) + j);
		}
		system("cls");
	}
	printf("学号\t");
	for (int i = 0; i < M - 1; ++i) {
		printf("成绩%d\t", i + 1);
	}
	printf("\n");
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (j == 0) {
				printf("%.0f\t", *(*(p + i) + j));
			}
			else {
				printf("%.3f\t", *(*(p + i) + j));
			}
		}
		printf("\n");
	}
	printf("\n第一门课程的平均分为:\n%.3f\n\n", class1_aver(1, p));
	fail(p);
	excellent(p);
	system("pause");
}