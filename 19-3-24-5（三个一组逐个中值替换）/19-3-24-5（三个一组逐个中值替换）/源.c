#include <stdio.h>
#include <stdlib.h>
void main() {
	int arr[10] = { 6,5,7,23,18,5,8,21,45,38 };
	for (int i = 1; i < 9; ++i) {
		int a = arr[i - 1];
		int b = arr[i];
		int c = arr[i + 1];
		arr[i] = (a > b) ? (b > c ? b : (a > c ? c : a)) : ((a > c) ?a: ((b > c) ? c : b));
	}
	for (int j = 0; j < 10; ++j) {
		printf("%d\t", arr[j]);
	}
	system("pause");
}