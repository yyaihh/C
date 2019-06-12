#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void Output(int n, int* p) {
	int a = n / 2;
	int b = (n*n + 1) / 2;
	int sum = pow(2, n + 1) - 1;
	*(p + a) = 1;
	*(p + n * a + a) = b;



}
int main() {
	int n = 0;
	printf("请输入您想要的奇数n:\n");
	for (scanf("%d", &n); n % 2 != 1; printf("请输入大于0的奇数\n"),scanf("%d", &n));
	int* p = (int*)calloc(n*n, sizeof(int));
	Output(n, p);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%3d", *(p + i*n + j));
		}
		printf("\n");
	}
	system("pause");
	return 0;
}