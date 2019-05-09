#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define N 5
struct student {
	int num;
	char name[1024];
	int score[3];
};
typedef struct student stu;
void input(stu* p) {
	for (int i = 0; i < N; ++i) {
		printf("请输入第%d个学生的信息\n", i + 1);
		printf("请输入num\n");
		scanf("%d", &(p + i)->num);
		printf("请输入姓名\n");
		scanf("%s", &(p + i)->name);
		for (int j = 0; j < 3; ++j) {
			printf("请输入score%d\n", j + 1);
			scanf("%d", &(p + i)->score[j]);
		}
	}
}
void print(stu* p) {
	printf("学号\t姓名\t成绩1\t成绩2\t成绩3\n");
	for (int i = 0; i < N; ++i) {
		printf("%d\t", (p + i)->num);
		printf("%s\t", (p + i)->name);
		for (int j = 0; j < 3; ++j) {
			printf("%d\t", (p + i)->score[j]);
		}
		printf("\n");
	}
}
void main() {
	stu arr[N];
	stu* p = arr;
	//输入
	input(p);
	//输出
	print(p);
	system("pause");
}
