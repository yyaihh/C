#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void fun(int* p, int n) {
	for (int i = n - 1; i >= 0; --i) {
		printf("%d\t", p[i]);
	}
}
void main() {
	int n = 0;
	printf("����������Ҫ��������ֵĸ���n\n");
	scanf("%d", &n);
	int* p = malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i) {
		printf("�������%d����\n", i + 1);
		scanf("%d", p + i);
	}
	printf("�����\n");
	fun(p, n);
	printf("\n");
	system("pause");
}