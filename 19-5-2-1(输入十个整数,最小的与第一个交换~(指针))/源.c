#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void input(int* p) {
	for (int i = 0; i < 10; ++i, ++p) {
		printf("请输入第%d个数的值\n", i + 1);
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
	printf("你输入的数组为:\n");
	print(p);
	fun(p);
	printf("转换后为:\n");
	print(p);
	system("pause");
}