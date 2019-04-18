#include<stdio.h>
#include<stdlib.h>
#define N 5
void fun(int arr[][N]) {
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			arr[i][j] = arr[j][i] ^ arr[i][j];
			arr[j][i] = arr[j][i] ^ arr[i][j];
			arr[i][j] = arr[j][i] ^ arr[i][j];
		}
	}
}

int main() {
	int arr[N][N];
	int num = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			arr[i][j] = num++;
		}
	}
	printf("原数组为:\n");
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
	fun(arr);
	printf("转换后数组为:\n");
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}