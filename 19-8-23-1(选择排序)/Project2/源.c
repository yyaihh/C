#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100000
void Swap(int* a,int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void SelectionSort(int* src, int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size; ++j) { 
			if (src[i] > src[j]) {
				Swap(src + i, src + j);
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
	SelectionSort(src, N);
	printf("ÅÅÐòºó:\n");
	PrintArray(src, N);
	system("pause");
	return 0;
}