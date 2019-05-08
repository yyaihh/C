#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void sort(int** arr, int n) {
	int tepm;
	for (int i = 0; i < n; ++i) {
		int min = i;
		for (int j = i + 1; j < n; ++j) {//a[i]依次和a[i]之后的元素作比较，记录较小的下标
			if (**(arr + j) < **(arr + min)) {
				min = j;
			}
		}
		//当min等于i时，说明a[i]就是a[i]之后所有元素中最小的
		// min不等于i时说明a[i]不是a[i]之后所有元素中最小的，最小的为a[mid]，将他们的值交换
		if (min != i) {
			tepm = **(arr + i);
			**(arr + i) = **(arr + min);
			**(arr + min) = tepm;
		}
	}
	printf("排序后\n");
	for (int i = 0; i <n ; ++i) {
		printf("%d  ", **(arr + i));
	}
	printf("\n");
}
void main() {
	int n;
	printf("请输入n的值\n");
	scanf("%d",&n);
	int* a = (int*)malloc(n * sizeof(int));
	int** arr= (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; ++i) {
		*(arr + i) = a + i;
	}
	for (int i = 0; i < n; ++i) {
		printf("请输入数组的第%d个数\n", i + 1);
		scanf("%d", *(arr + i));
	}
	printf("你输入的数组为：\n");
	for (int i = 0; i < n; ++i) {
		printf("%d  ", **(arr + i));
	}
	printf("\n");
	sort(arr, n);
	system("pause");
}