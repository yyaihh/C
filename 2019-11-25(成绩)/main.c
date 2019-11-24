#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
void stu_aver(double(*a)[6]) {//计算学生平均成绩
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
void score_aver(double(*a)[6]) {//科目平均成绩
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
void top_score(char(*c)[20], char(*s)[20], double(*a)[6]) {//科目最高
	int row, col, i, j, flag;
	double top;
	printf("单科最高分\n");
	printf("科目\t分数\t学生\n");
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
double viriance(double(*a)[6]) {//方差
	double x1 = 0;
	double x2 = 0;
	int i;
	for (i = 0; i < 10; ++i) {
		x1 += a[i][6];
		x2 += pow(a[i][6], 2);
	}
	return x2 / 10 - pow(x1 / 10, 2);
}
void input(char(*c)[20], char(*s)[20], double(*a)[6]) {//输入
	int i, j;
	for (i = 0; i < 5; ++i) {
		printf("请输入第%d门课的课程名\n", i + 1);
		scanf("%s", c[i]);
	}
	for (i = 0; i < 10; ++i) {
		printf("请输入第%d名学生的姓名\n", i + 1);
		scanf("%s", s[i]);
		for (j = 0; j < 5; ++j) {
			printf("请输入这名学生的成绩\n");
			scanf("%lf", &a[i][j]);
		}
	}
	system("cls");
}
void print(char(*c)[20], char(*s)[20], double(*a)[6]) {//打印
	int i, j;
	putchar('\t');
	for (i = 0; i < 5; ++i) {
		printf("%s\t", c[i]);
	}
	printf("平均成绩");
	for (i = 0; i < 10; ++i) {
		printf("\n%s\t", s[i]);
		for (j = 0; j < 6; ++j) {
			printf("%.2f\t", a[i][j]);
		}
	}
	printf("\n课程\n平均分\t");
	for (j = 0; j < 5; ++j) {
		printf("%.2f\t", a[i][j]);
	}
	putchar('\n');
}
int main() {
	char c[5][20];//课程名字
	char s[10][20];//学生姓名
	double a[11][6];//学生成绩
	input(c, s, a);//输入
	stu_aver(a);//学生平均成绩
	score_aver(a);//课程平均成绩
	print(c, s, a);//打印
	top_score(c, s, a);//课程最高分
	printf("方差为:%f\n", viriance(a));//方差
	return 0;
}
