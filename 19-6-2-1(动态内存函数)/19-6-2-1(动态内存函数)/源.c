#if 1
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int *p = NULL;
	int *q = NULL;
	int n = 5;
	//scanf("%d", &n);
	p = (int*)calloc(n, sizeof(int));
	if (p == NULL) {
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", p + i);
	}
	for (int i = 0; i < n; ++i) {
		printf("%d\n", *(p + i));
	}
	q = (int*)realloc(p, 10);
	if (q == NULL) {
		exit(EXIT_FAILURE);
	}
	//scanf("%d", q + 5);
	for (int i = 0; i < 5; ++i) {
		printf("%d\n", *(q + i));
	}
	free(q);
	system("pause");
	return 0;
}
#endif