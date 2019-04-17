#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main() {
	int arr[3][3];
	int sum = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
				printf("请输入arr[%d][%d]\n", i, j);
				scanf("%d", &arr[i][j]);
		}
	}
	system("cls");
	printf("得到的矩阵为:\n");
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
				printf("%d  ", arr[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < 3; ++i) {
		sum += arr[i][i];
	}
	printf("3×3整型矩阵对角线之和为：%d\n", sum);
	system("pause");
}