#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h> 
#define M 5
#define N 6
int find(int arr[M][N], int num) {
	int i;
	int k = 0;
	for (int j = M - 1; j >=0; --j) {
		for (; k < N; ++k) {
			if (arr[j][k] == num) {
				return 1;
			}
			if (arr[j][k] > num) {
				break;
			}
		}
	}
	return 0;
}
int main() {
	int arr[M][N] = { {1,2,3,4,5,30},{3,5,6,7,8,31}, {7,9,10,13,15,32}, {10,12,14,17,19,33}, {13,15,17,20,26,34} };
	int num;
	printf("请输入需要判断的数\n");
	scanf("%d", &num);
	if (find(arr, num) == 1) {
		printf("找到了\n");
	}
	else {
		printf("没找到\n");
	}
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}