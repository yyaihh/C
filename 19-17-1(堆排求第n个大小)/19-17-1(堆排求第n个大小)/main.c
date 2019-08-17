#include"hpsort.h"
#define M 2
int main() {
	int a[10] = { 29,72,48,53,45,30,18,36,15,35};
	int n = sizeof(a) / 4;
	printf("≈≈–Ú«∞\n");
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
	if (M <= n) {
		printf("\n%d\n", HeapSort(a, n, M));
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}