#include<stdio.h>
#include<stdlib.h>
#define N 5
void swop(int* a, int* b) {//交换两个数,两个形参为指针
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
void fun(int(*p)[N]){
	int* max = (int*)p;//最大值
	int* min1 = (int*)p;//最小值
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (*max < *(*(p + i) + j)) {
				max = *(p + i) + j;
			}
			if (*min1 > *(*(p + i) + j)) {
				min1 = *(p + i) + j;
			}
		}
	}
	int* min2 = *(p + 2) + 2;//次小值
	int* min3 = *(p + 2) + 2; //倒数第三小值
	int* min4 = *(p + 2) + 2;//倒数第四小值

	swop(max, *(p + 2) + 2);//最大值与中间的值交换
	swop(min1, *p);//最小值与左上角的值交换
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (*(p + i) + j == *p) {
				continue;
			}
			if (*min2 > *(*(p + i) + j)) {
				min2 = *(p + i) + j;
			}
		}
	}
	swop(min2, *(p)+N - 1);//次小值与右上角的值交换
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (*(p + i) + j == *p || *(p + i) + j ==*(p)+N - 1) {
				continue;
			}
			if (*min3 > *(*(p + i) + j)) {
				min3 = *(p + i) + j;
			}
		}
	}
	swop(min3, *(p + N - 1));//倒数第三小值与左下角的值交换
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (*(p + i) + j == *p || *(p + i) + j == *(p)+N - 1 || *(p + i) + j == *(p + N - 1)) {
				continue;
			}
			if (*min4 > *(*(p + i) + j)) {
				min4 = *(p + i) + j;
			}
		}
	}
	swop(min4, *(p + N - 1) + N - 1); //倒数第四小值右下角的值交换
}
void main() {
	int arr[N][N];
	int(*p)[N] = arr;//定义指向二维数组的指针p
	int count = 25;
	for (int i = 0; i < N; ++i) {//初始化二维数组
		for (int j = 0; j < N; ++j) {
			*(*(p + i) + j) = count;
			count -= 1;
		}
	}
	printf("原数组为\n");
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%d\t", *(*(p + i) + j));
		}
		printf("\n");
	}
	printf("\n\n转换后的数组为\n");
	fun(p);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%d\t", *(*(p + i) + j));
		}
		printf("\n");
	}
	system("pause");
}
