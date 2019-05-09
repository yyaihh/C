#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define N 13
struct arr {
	int num;
	struct arr* next;
};
typedef struct arr arr;
arr* fun(arr* p) {
	for (int i = 0; i < N; ++i) {
		(p + i)->num = i + 1;
		printf("%d\t", (p + i)->num);
	}
	printf("\n报数:\n");
	for (int i = 0, k = 1; m > 1; ++i) {
		if ((p + i)->num != 0) {
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
	arr a;
	arr* p = &a;
	fun(p);
	system("pause");
}
