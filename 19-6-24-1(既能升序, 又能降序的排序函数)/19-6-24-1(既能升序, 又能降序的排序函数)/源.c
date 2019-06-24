#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#define N 4//N个学生
#define M 6//M - 1门课程
void print0() {
	printf("学号\t");
	for (int i = 0; i < M - 1; ++i) {
		printf("成绩%d\t", i + 1);
	}
}
void print(int i, double(*p)[M]) {
	printf("\n");
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
			print0();
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
			print0();
			print(i, p);
			printf("\n平均成绩为%.3f\n", sum / (M - 1));
		}
		else if (sum / (M - 1) >= 90) {
			printf("如下该学生有所有成绩平均分超过90分\n");
			print0();
			print(i, p);
			printf("\n平均成绩为%.3f\n", sum / (M - 1));
		}
	}
}
void swap(double(*a)[M], double(*b)[M]) {
	double tmp;
	for (int i = 0; i < M; ++i) {
		tmp = *(*a + i);
		*(*a + i) = *(*b + i);
		*(*b + i) = tmp;
	}
}
void sort(int m, double(*p)[M]) {
	int choic, n;
	printf("0.按学号排序\n");
	printf("1.按成绩1排序\n2.按成绩2排序\n");
	printf("3.按成绩3排序\n4.按成绩4排序\n");
	printf("5.按成绩5排序\n请输入您的选项\n");
	n = scanf("%d", &choic);
	while (n != 1 || choic < 0 || choic > 5) {
		printf("您的输入有误,请重新输入\n");
		while (getchar() != '\n');
		n = scanf("%d", &choic);
	}
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < N - i - 1; ++j) {//冒泡法
			if ((m && *(*(p + j) + choic) > *(*(p + j + 1) + choic)) || (!m && *(*(p + j) + choic) < *(*(p + j + 1) + choic))) {
				if (choic == 1) {
					swap(p + j, p + j + 1);
				}
				else if (choic == 2) {
					swap(p + j, p + j + 1);
				}
				else if (choic == 3) {
					swap(p + j, p + j + 1);
				}
				else if (choic == 4) {
					swap(p + j, p + j + 1);
				}
				else if (choic == 5) {
					swap(p + j, p + j + 1);
				}
			}
		}
	}
}
void main() {
	int choic = 0;
	int n = 0;
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
					if (*(*(p + i) + j) != *(*(p + i - 1) + j)) {
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
	printf("请选择排序种类\n0.升序 1.降序\n请输入您的选择\n");
	n = scanf("%d", &choic);
	while (n != 1 || choic < 0 || choic > 1) {
		printf("您的输入有误,请重新输入\n");
		while (getchar() != '\n');
		n = scanf("%d", &choic);
	}
	sort(choic, p);
	print0();
	for (int i = 0; i < N; ++i) {
		print(i, p);
	}
	printf("\n第一门课程的平均分为:\n%.3f\n\n", class1_aver(1, p));
	fail(p);
	excellent(p);
	system("pause");
}
