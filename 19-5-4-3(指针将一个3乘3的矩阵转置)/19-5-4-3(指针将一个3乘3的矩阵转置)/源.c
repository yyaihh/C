#include<stdio.h>
#include<stdlib.h>
#define N 5
void fun(int(* p)[N]) {
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			*(*(p + i) + j) = *(*(p + j) + i) ^ *(*(p + i) + j);
			*(*(p + j) + i) = *(*(p + j) + i) ^ *(*(p + i) + j);
			*(*(p + i) + j) = *(*(p + j) + i) ^ *(*(p + i) + j);
		}
	}
}
int main() {
	int arr[N][N];
	int num = 0;
	int (*p)[N] = arr;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			*(*(p + i) + j) = num++;
		}
	}
	printf("原数组为:\n");
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%d\t", *(*(p + i) + j));
		}
		printf("\n");
	}
	fun(p);
	printf("转换后数组为:\n");
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%d\t", *(*(p + i) + j));
		}
		printf("\n");
	}
	system("pause");
}