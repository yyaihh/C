#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void input(int* p) {
	for (int i = 0; i < 10; ++i, ++p) {
		printf("�������%d������ֵ\n", i + 1);
		scanf("%d", p);
	}
}
void print(int* p) {
	for (int i = 0; i < 10; ++i, ++p) {
		printf("%d ", *p);
	}
	printf("\n");
}
void fun(int* q) {
	int* p = q;
	int* minp = p;
	int* maxp = p;
	int temp;
	for (int i = 1; i < 10; ++i, ++p) {
		if (*maxp < *p) {
			maxp = p;
		}
		if (*minp > *p) {
			minp = p;
		}
	}
	temp = *maxp;
	*maxp = *p;
	*p = temp;

	temp = *minp;
	*minp = *q;
	*q = temp;
}
void main() {
	int arr[10];
	int* p = arr;
	input(p);
	printf("�����������Ϊ:\n");
	print(p);
	fun(p);
	printf("ת����Ϊ:\n");
	print(p);
	system("pause");
}