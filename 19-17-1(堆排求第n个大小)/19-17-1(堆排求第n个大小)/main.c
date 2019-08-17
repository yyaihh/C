#include"hpsort.h"
#define M 4
int main() {
	int a[10] = { 3,56,23,45,3,67,32,78,45,-1 };
	int n = sizeof(a) / 4;
	printf("≈≈–Ú«∞\n");
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
	if (M <= n) {
		printf("\n%d\n", HeapSort(a, n, M));
	}
	system("pause");
	return 0;
}