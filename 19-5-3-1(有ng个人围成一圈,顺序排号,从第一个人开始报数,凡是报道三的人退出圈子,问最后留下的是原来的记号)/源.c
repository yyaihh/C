#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void fun(int n) {
	int m = n;
	int* p = malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i) {
		*(p + i) = i + 1;
		printf("%d\t", *(p + i));
	}
	printf("\n报数:\n");
	for (int i = 0, k = 1;m > 1; ++i) {
		if (*(p + i) != 0) {
			printf("%d\t", k);
			k += 1;
			if (k == 4) {
				k = 1;
				*(p + i) = 0;
				m -= 1;
			}
		}
	
		if (i == n - 1) {
			printf("\n报到3的退出\n");
			for (int j = 0; j < n; ++j) {
				if (*(p + j) != 0) {
					printf("%d\t", *(p + j));
				}
			}
			printf("\n报数:\n");
			i = -1;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (*(p + i) != 0) {
			printf("\n最后留下的是原来的%d号\n", *(p + i));
		}
	}
}
void main() {
	int n;
	printf("请输入人数n\n");
	scanf("%d", &n);
	fun(n);
	system("pause");
}