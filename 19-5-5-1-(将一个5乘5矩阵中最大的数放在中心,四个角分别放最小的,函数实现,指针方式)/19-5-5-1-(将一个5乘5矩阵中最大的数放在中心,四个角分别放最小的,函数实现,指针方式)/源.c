#include<stdio.h>
#include<stdlib.h>
#define N 5
void swop(int* a, int* b) {//����������,�����β�Ϊָ��
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
void fun(int(*p)[N]){
	int* max = (int*)p;//���ֵ
	int* min1 = (int*)p;//��Сֵ
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (*max < *(*(p + i) + j)) {
				max = *(p + i) + j;
			}
			if (*min1 > *(*(p + i) + j)) {
				min1 = *(p + i) + j;
			}
		}
	}
	int* min2 = *(p + 2) + 2;//��Сֵ
	int* min3 = *(p + 2) + 2; //��������Сֵ
	int* min4 = *(p + 2) + 2;//��������Сֵ

	swop(max, *(p + 2) + 2);//���ֵ���м��ֵ����
	swop(min1, *p);//��Сֵ�����Ͻǵ�ֵ����
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (*(p + i) + j == *p) {
				continue;
			}
			if (*min2 > *(*(p + i) + j)) {
				min2 = *(p + i) + j;
			}
		}
	}
	swop(min2, *(p)+N - 1);//��Сֵ�����Ͻǵ�ֵ����
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (*(p + i) + j == *p || *(p + i) + j ==*(p)+N - 1) {
				continue;
			}
			if (*min3 > *(*(p + i) + j)) {
				min3 = *(p + i) + j;
			}
		}
	}
	swop(min3, *(p + N - 1));//��������Сֵ�����½ǵ�ֵ����
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (*(p + i) + j == *p || *(p + i) + j == *(p)+N - 1 || *(p + i) + j == *(p + N - 1)) {
				continue;
			}
			if (*min4 > *(*(p + i) + j)) {
				min4 = *(p + i) + j;
			}
		}
	}
	swop(min4, *(p + N - 1) + N - 1); //��������Сֵ���½ǵ�ֵ����
}
void main() {
	int arr[N][N];
	int(*p)[N] = arr;//����ָ���ά�����ָ��p
	int count = 25;
	for (int i = 0; i < N; ++i) {//��ʼ����ά����
		for (int j = 0; j < N; ++j) {
			*(*(p + i) + j) = count;
			count -= 1;
		}
	}
	printf("ԭ����Ϊ\n");
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%d\t", *(*(p + i) + j));
		}
		printf("\n");
	}
	printf("\n\nת���������Ϊ\n");
	fun(p);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%d\t", *(*(p + i) + j));
		}
		printf("\n");
	}
	system("pause");
}
