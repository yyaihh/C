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
	printf("请输入您需要输入的数字的个数n\n");
	scanf("%d", &n);
	int* p = malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i) {
		printf("请输入第%d个数\n", i + 1);
		scanf("%d", p + i);
	}
	printf("逆序后\n");
	fun(p, n);
	printf("\n");
	system("pause");
}