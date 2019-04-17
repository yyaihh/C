#include<stdio.h>
#include<stdlib.h>
#define M 11
#define N 11
void main() {
	int a[M][N];
	int num = 0;
	int row, col;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			a[i][j] = num++;
		}
	}
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	row = M / 2;
	col = N / 2;
	for (int i = 0; i <= M / 2; ++i) {
		for (int j = 0; j < 2 * i - 1; ++j) {
			printf("%d ", a[row][col++]);
		}
		for (int j = 0; j < 2 * i; ++j) {
			printf("%d ", a[row++][col]);
		}
		for (int j = 0; j < 2 * i; ++j) {
			printf("%d ", a[row][col--]);
		}
		for (int j = 0; j < 2 * i + 1; ++j) {
			printf("%d ", a[row--][col]);
		}
		printf("\n");
	}
	system("pause");
}