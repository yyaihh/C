#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define N 10
struct student {
	int num;
	char name[1024];
	int score[3];
};
typedef struct student stu;
void input(stu* p) {//����
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
void print(stu* p) {//���
	printf("%d\t", p->num);
	printf("%s\t", p->name);
	for (int j = 0; j < 3; ++j) {
		printf("%d\t", p->score[j]);
	}
}
double aver(stu* p) {//����ƽ����
	double sum = 0;
	for (int i = 0; i < 3; ++i) {
		sum += p->score[i];
	}
	return sum / N;
}
int excellect(stu* p) {//�ж���߷�,�����±�
	double sum = 0;
	double max = 0;
	int record = 0;
	for (int i = 0; i < N; ++i) {
		sum = 0;
		for (int j = 0; j < 3; ++j) {
			sum += (p + i)->score[j];
		}
		if (max < sum) {
			max = sum;
			record = i;
		}
	}
	return record;
}
void main() {
	stu a[N];
	stu* p = a;
	input(p);
	printf("ѧ��\t����\t�ɼ�1\t�ɼ�2\t�ɼ�3\tƽ��\n");
	for (int i = 0; i < N; i++) {
		print(p + i);
		printf("%f\n", aver(p + i));
	}
	printf("��߷ֵ�ѧ����������\nѧ��\t����\t�ɼ�1\t�ɼ�2\t�ɼ�3\tƽ��\n");
	int n = excellect(p);
	print(p + n);
	printf("%f\n", aver(p + n));
	system("pause");
}