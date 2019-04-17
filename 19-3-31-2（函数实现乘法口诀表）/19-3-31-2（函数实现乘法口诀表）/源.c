#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void fun(int x) {
	for (int i = 1; i <= x; ++i) {
		for (int j = 1; j <= i; ++j) {
			printf("%d*%d=%d\t", j, i, i*j);
		}
		printf("\n");
	}
}
void main() {
	int n;
	printf("ÇëÊäÈënµÄÖµ\n");
	scanf("%d", &n);
	fun(n); 
	system("pause");
}