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
		printf("�������%d��ѧ������Ϣ\n", i + 1);
		printf("������num\n");
		scanf("%d", &(p + i)->num);
		printf("����������\n");
		scanf("%s", &(p + i)->name);
		for (int j = 0; j < 3; ++j) {
			printf("������score%d\n", j + 1);
			scanf("%d", &(p + i)->score[j]);
		}
	}
}
void print(stu* p) {
	printf("ѧ��\t����\t�ɼ�1\t�ɼ�2\t�ɼ�3\n");
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
	//����
	input(p);
	//���
	print(p);
	system("pause");
}
