#include"hpsort.h"
#include<time.h>
#define N 100000
int main() {
	srand((unsigned int)time(0));
	int src[N];
	for (int i = 0; i < N; ++i) {
		src[i] = rand() % N + 1;
	}

	//printf("ÅÅÐòÇ°\n");
	//PrintArray(src, N);
	printf("\nÅÅÐòºó\n");
	HeapSort(src, N);
	PrintArray(src, N);
	putchar('\n');
	system("pause");
	return 0;
}