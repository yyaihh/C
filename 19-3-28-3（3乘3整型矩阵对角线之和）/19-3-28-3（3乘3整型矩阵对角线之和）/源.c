#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main() {
	int arr[3][3];
	int sum = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
				printf("������arr[%d][%d]\n", i, j);
				scanf("%d", &arr[i][j]);
		}
	}
	system("cls");
	printf("�õ��ľ���Ϊ:\n");
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
				printf("%d  ", arr[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < 3; ++i) {
		sum += arr[i][i];
	}
	printf("3��3���;���Խ���֮��Ϊ��%d\n", sum);
	system("pause");
}