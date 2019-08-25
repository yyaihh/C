#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100
void ShellSort(int* src, int size) {
	int j;
	int gap, tmp;
	gap = size / 3;//n/3是最快的
	for (int k = 0; gap; ++k) {
		if (k == gap) {
			gap /= 2;
			k = -1;
			continue;
		}
		for (int i = gap + k; i < size; i += gap) {
			tmp = src[i];
			for (j = i; j >= gap && src[j - gap] > tmp; j -= gap) {
				src[j] = src[j - gap];
			}
			src[j] = tmp;
		}
	}
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
	ShellSort(src, N);
	ShellSort(src1, 10);
	PrintArray(src1, 10);
	//printf("排序后:\n");
	PrintArray(src, N);
	system("pause");
	return 0;
}
