
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void BubbleSort(int* src, int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (src[j] > src[j + 1]) {
				Swap(src + j, src + j + 1);
			}
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
	for (int i = 0; i < N; ++i) {
		src[i] = rand() % N + 1;
	}
	printf("ÅÅÐòÇ°:\n");
	//PrintArray(src, N);
	BubbleSort(src, N);
	printf("ÅÅÐòºó:\n");
	PrintArray(src, N);
	system("pause");
	return 0;
}