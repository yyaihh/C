#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void sort(int a[],int L,int x) {
	int tepm;
	for (int i = 0; i < L; ++i) {
		int m = i;
		for (int j = i + 1; j < L; ++j) {//a[i]依次和a[i]之后的元素作比较，记录较小的下标
			switch (x) {
				case 0:
					if (a[j] > a[m]) {
						m = j;
					}break;
				case 1:
					if (a[j] < a[m]) {
						m = j;
					}break;
			}
		}
		if (m != i) {
			tepm = a[i];
			a[i] = a[m];
			a[m] = tepm;
		}
	}
}
void main() {
	//int arr[11] = { 0,8,36,45,89,185,234,250,290,300 };
	int arr[11] = { 300,290,250,234,185,89,45,36,8,0 };
	int length = sizeof(arr) / sizeof(arr[0]);
	int X;
	for (int i = 0; i < 10; ++i) {
		printf("%d  ", arr[i]);
	}
	printf("\n请输入需要插入的数\n");
	scanf("%d", &arr[10]);
	if (arr[0] < arr[9]) {//从小到大
		X = 1;
	}
	else if (arr[0] > arr[10]) {//从大到小
		X = 0;
	}
	sort(arr, length, X);
	printf("插入新元素后数组为;\n");
	for (int i = 0; i < 11; ++i) {
		printf("%d  ", arr[i]);
	}
	printf("\n");
	system("pause");
}
