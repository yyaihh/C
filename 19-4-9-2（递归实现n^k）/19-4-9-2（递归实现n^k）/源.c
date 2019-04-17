#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int fun(int n, int k) {
	if (k == 0) {
		return 1;
	}
	if (k == 1) {
		return n;
	}
	return n * fun(n,k - 1);
}
void main() {
	int n, k;
	printf("«Î ‰»În£¨kµƒ÷µ\n");
	scanf("%d %d", &n, &k);
	printf("%d^%d = %d\n", n, k, fun(n, k));
	system("pause");
}