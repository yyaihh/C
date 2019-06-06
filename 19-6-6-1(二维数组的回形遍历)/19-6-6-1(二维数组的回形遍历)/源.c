#include<stdio.h>
#include<stdlib.h>
#define M 1
#define N 6
void fun(int(*p)[N], int size) {
	int m = sizeof(*p) / 4;//列边界
	int n = size / (4 * m);//行边界
	int num = n < m ? n : m;
	int i = 0, j = 0, k;
	for (k = 0; k < num / 2; ++k) { 
		i = k, j = k;
		printf("第%d圈:\n", k + 1);
		for (; i < n - k; ++i) {//
			printf("%d\t", p[i][j]);
		}
		for (--i, ++j; j < m - k; ++j) {//
			printf("%d\t", p[i][j]);
		}
		for (--j, --i; i > k; --i) {//
			printf("%d\t", p[i][j]);
		}
		for (; j > k; --j) {//
			printf("%d\t", p[i][j]);
		}
		printf("\n");
	}
	if (n <= m) {
		for (++i,++j; j < m - k; ++j) {//
			printf("%d\t", p[i][j]);
		}
		printf("\n");
	}
	else {
		for (++i, ++j; i < n - k; ++i) {//
			printf("%d\t", p[i][j]);
		}
		printf("\n");
	}
	
}
int main() {
	int a[M][N] = { 0 };
	int n = 1;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			a[i][j] = n++;
		}
	}
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");
	fun(a, sizeof(a));
	system("pause");
	return 0;
}
