#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#define N 4//N��ѧ��
#define M 6//M - 1�ſγ�
void print0() {
	printf("ѧ��\t");
	for (int i = 0; i < M - 1; ++i) {
		printf("�ɼ�%d\t", i + 1);
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
double class1_aver(int n, double(*p)[M]) {//�����n�ſεĳɼ�
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
			printf("���¸�ѧ���г������ſγ̳ɼ�������\n");
			print0();
			print(i, p);
			printf("\nƽ���ɼ�Ϊ%.3f\n\n", sum / (M - 1));
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
			printf("���¸�ѧ�������гɼ�������85��\n");
			print0();
			print(i, p);
			printf("\nƽ���ɼ�Ϊ%.3f\n", sum / (M - 1));
		}
		else if (sum / (M - 1) >= 90) {
			printf("���¸�ѧ�������гɼ�ƽ���ֳ���90��\n");
			print0();
			print(i, p);
			printf("\nƽ���ɼ�Ϊ%.3f\n", sum / (M - 1));
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
	printf("0.��ѧ������\n");
	printf("1.���ɼ�1����\n2.���ɼ�2����\n");
	printf("3.���ɼ�3����\n4.���ɼ�4����\n");
	printf("5.���ɼ�5����\n����������ѡ��\n");
	n = scanf("%d", &choic);
	while (n != 1 || choic < 0 || choic > 5) {
		printf("������������,����������\n");
		while (getchar() != '\n');
		n = scanf("%d", &choic);
	}
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < N - i - 1; ++j) {//ð�ݷ�
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
				printf("�������%d��ѧ����ѧ��\n", i + 1);
				while (1) {
					scanf("%lf", *(p + i) + j);
					if (i == 0) {
						break;
					}
					if (*(*(p + i) + j) != *(*(p + i - 1) + j)) {
						break;
					}
					printf("���������ѧ�����%d��ѧ��ѧ����ͬ��Ϊ%.0f,����������\n", i, *(*(p + i - 1) + j));
				}
				continue;
			}
			printf("�������ѧ���ĵ�%d�ųɼ�\n", j);
			scanf("%lf", *(p + i) + j);
		}
		system("cls");
	}
	printf("��ѡ����������\n0.���� 1.����\n����������ѡ��\n");
	n = scanf("%d", &choic);
	while (n != 1 || choic < 0 || choic > 1) {
		printf("������������,����������\n");
		while (getchar() != '\n');
		n = scanf("%d", &choic);
	}
	sort(choic, p);
	print0();
	for (int i = 0; i < N; ++i) {
		print(i, p);
	}
	printf("\n��һ�ſγ̵�ƽ����Ϊ:\n%.3f\n\n", class1_aver(1, p));
	fail(p);
	excellent(p);
	system("pause");
}
