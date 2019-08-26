#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100
void dealMergeSort(int* src, int* tmp, int start, int end) {
	if (start >= end) {//前后指针交替, 已经二分完毕
		return;
	}
	int mid = (start + end) / 2;
	dealMergeSort(src, tmp, start, mid);
	dealMergeSort(src, tmp, mid + 1, end);
	int a = start;//分后前一部分数组的起始坐标
	int b = mid + 1;//分后后一部分数组的起始坐标
	int c = start;//临时数组起始坐标, 将存储前后两个有序数组归并后的有序数组
	while (a <= mid && b <= end) {
		if(src[a]<src[b]){
			tmp[c] = src[a];
			++a;
		}
		else {
			tmp[c] = src[b];
			++b;
		}
		++c;
	}
	//循环跳出时不一定左右两个有序数组同时遍历结束 , 但未遍历完的一个数组盛夏的肯定是比另一个遍历完的数组最大值还大的有序数列
	//直接给临时数组tmp
	//以下两个for循环只进一个
	for (; a <= mid; ++a,++c) {
		tmp[c] = src[a];
	}
	for (; b <= end; ++b, ++c) {
		tmp[c] = src[b];
	}
	//将存在临时数组中的合并的有序数列再给待排序数组src
	for (int i = start; i <= end; ++i) {
		src[i] = tmp[i];
	}
}
void MergeSort(int* src, int size) {
	int* tmp = (int*)malloc(size * sizeof(src[0]));
	dealMergeSort(src, tmp, 0, size - 1);
	free(tmp);
}
void PrintArray(int* src, int size) {
	for (int i = 0; i < size; ++i) {
		printf("%d ", src[i]);
	}
	putchar('\n');
}
int main() {
	srand((unsigned int)time(0));
	int src[N];
	int src1[10] = { 8,7,10,2,3,5,6,1,4,9 };
	for (int i = 0; i < N; ++i) {
		src[i] = rand() % N + 1;
	}
	//printf("排序前:\n");
	//PrintArray(src, N);
	MergeSort(src, N);
	MergeSort(src1, 10);
	PrintArray(src1, 10);
	//printf("排序后:\n");
	PrintArray(src, N);
	system("pause");
	return 0;
}
