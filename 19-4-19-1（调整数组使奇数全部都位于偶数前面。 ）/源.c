#include<stdio.h>
#include<stdlib.h>
void fun(int arr[], int L) {
	int temp;
	for (int i = 0; i < L; ++i) {
		for (int j = i; j < L; ++j) {
			if (j == i && arr[i] % 2 == 1) {
				break;
			}
			if (arr[j] % 2 == 1) {
				temp = arr[j];
				for (int k = j; k > i;--k) {
					arr[k] = arr[k - 1];
				}
				arr[i] = temp;
				break;
			}
		}
	}
}
int main() {
	int arr[10] = { 1,2,3,4,5,8,9,6,7,10 };
	printf("原数组为:\n");
	for (int i = 0; i < 10; ++i) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
	printf("转换后数组为:\n");
	fun(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < 10; ++i) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}