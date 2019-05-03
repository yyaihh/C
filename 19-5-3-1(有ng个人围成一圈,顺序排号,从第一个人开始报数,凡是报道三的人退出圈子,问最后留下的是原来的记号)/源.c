#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void fun(int n) {
	int m = n;
	int* p = malloc(n * sizeof(int));
	for (int i = 0, k = 1;m > 1; ++i) {
		if (*(p + i) != 0) {
			*(p + i) = k;
			k += 1;
			if (k == 4) {
				k = 1;
			}
		}
		if (*(p + i) == 3) {
			*(p + i) = 0;
			m -= 1;
		}
		if (i == n - 1) {
			i = -1;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (*(p + i) != 0) {
			printf("最后留下的是原来的%d号\n", i + 1);
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