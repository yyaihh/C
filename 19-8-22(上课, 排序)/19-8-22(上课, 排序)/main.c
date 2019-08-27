#include"sort.h"
#define N 10000
void PrintArray(int* src, int size) {
	for (int i = 0; i < size; ++i) {
		printf("%d ", *(src + i));
	}
	putchar('\n');
}
int main() {
#if 0
	int src[10] = { 3,1,6,7,9,2,4,8,10,5 };
	int src1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int src2[10] = { 1,5,8,2,3,4,9,10,7,6 };
	int src3[10] = { 5,6,7,8,1,2,3,4,9,10 };
	//InsertSort(src, 10);
	//ShellSort(src, 10);
	//MergeSort(src, 10);
	/*QuickSort(src, 10);
	PrintArray(src, 10);
	QuickSort(src1, 10);
	PrintArray(src1, 10);
	QuickSort(src2, 10);
	PrintArray(src2, 10);*/
	QuickSort(src, 10);
	//QuickSortNoR(src, 10);
	PrintArray(src, 10);
#else
	srand(time(0));
	int src[N];
	for (int i = 0; i < N; ++i) {
		src[i] = rand() % 10000 + 1;
	}
	//InsertSort(src, N);
	//ShellSort(src, N);
	QuickSort(src, N);
	//QuickSortNoR(src, N);
	PrintArray(src, N);
#endif

	system("pause");
	return 0;
}