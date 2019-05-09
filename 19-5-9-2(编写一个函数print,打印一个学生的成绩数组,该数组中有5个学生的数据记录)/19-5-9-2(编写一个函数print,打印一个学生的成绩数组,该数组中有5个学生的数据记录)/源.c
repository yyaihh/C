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
void print(stu* p) {
	for (int i = 0; i < N; ++i) {
		printf("num:%d\n", (p + i)->num);
		printf("name:%s\n", (p + i)->name);
		for (int j = 0; j < 3; ++j) {
			printf("score%d: %d\n", j + 1, (p + i)->score[j]);
		}
	}
}
void main() {
	stu arr[N];
	stu* p = arr;
	//输入
	for (int i = 0; i < N; ++i) {
		printf("请输入num\n");
		scanf("%d", &(p + i)->num);
		printf("请输入姓名\n");
		scanf("%s", &(p + i)->name);
		for (int j = 0; j < 3; ++j) {
			printf("请输入score%d\n", j + 1);
			scanf("%d", &(p + i)->score[j]);
		}
	}
	//输出
	print(p);
	system("pause");
}