#include"hpsort.h"

int main() {
	int a[10] = { 3,56,23,45,3,67,32,78,45,-1 };
	int n = sizeof(a) / 4;
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
	printf("ÅÅÐòºó\n");
	HeapSort(a, n);
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
	putchar('\n');
	system("pause");
	return 0;
}