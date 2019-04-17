#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void sort(int a[]) {
	int tepm;
	for (int i = 0; i < 10; ++i) {
		int min = i;
		for (int j = i + 1; j < 10; ++j) {//a[i]依次和a[i]之后的元素作比较，记录较小的下标
			if (a[j] < a[min]) {
				min = j;
			}
		}
		//当min等于i时，说明a[i]就是a[i]之后所有元素中最小的
		// min不等于i时说明a[i]不是a[i]之后所有元素中最小的，最小的为a[mid]，将他们的值交换
		if (min != i) {
			tepm = a[i];
			a[i] = a[min];
			a[min] = tepm;
		}
	}
	for (int i = 0; i < 10; ++i) {
		printf("%d  ", a[i]);
	}
	printf("\n");
}
void main() {
	int arr[10];
	for (int i = 0; i < 10; ++i) {
		printf("请输入数组arr的第%d个数\n", i + 1);
		scanf("%d", &arr[i]);
		system("cls");
	}
	printf("数组arr为：\n");
	for (int i = 0; i < 10; ++i) {
		printf("%d  ", arr[i]);
	}
	printf("\n");
	sort(arr);
	system("pause");
}