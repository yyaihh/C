#include<stdio.h>
#include<stdlib.h>
void saddle_point(int a[][4]) {
	int min, max, p, q;
	int count = 0;
	for (int i = 0; i < 3; ++i) {
		p = 0;
		q = 0;
		max = a[i][0];
		for (int j = 1; j < 4; ++j) {
			if (max < a[i][j]) {
				max = a[i][j];
				p = j;
			}
		}
		min = a[0][p];
		for (int k = 1; k < 3; ++k) {
			if (min > a[k][p]) {
				min = a[k][p];
				q = k;
			}
		}
		if (min == max) {
			printf("鞍点为arr[%d][%d]=%d\n", q, p, min);
		}
		else {
			count++;
		}
	}
	if (count == 3) {
		printf("二唯数组arr无鞍点\n");
	}
}
void main() {
	int arr[3][4] = { {9,6,8,70}, {10,23,55,66}, {15,67,4,69} };
	printf("二维数组arr为:\n");
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
	saddle_point(arr);
	system("pause");
}