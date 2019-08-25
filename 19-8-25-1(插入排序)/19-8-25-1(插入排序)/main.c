#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100000
void InsertSort(int* src, int size) {
	int tmp, j;
	for (int i = 1; i < size; ++i) {
		tmp = src[i];
		for (j = i; j > 0 && src[j - 1] > tmp; --j) {
			src[j] = src[j - 1];
		}
		src[j] = tmp;
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
	for (int i = 0; i < N; ++i) {
		src[i] = rand() % N + 1;
	}
	//printf("ÅÅÐòÇ°:\n");
	//PrintArray(src, N);
	InsertSort(src, N);
	printf("ÅÅÐòºó:\n");
	PrintArray(src, N);
	system("pause");
	return 0;
}