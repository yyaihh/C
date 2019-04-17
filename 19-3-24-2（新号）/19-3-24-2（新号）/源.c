#include<stdio.h>
#include<stdlib.h>
#define M 13
int main() {
	for (int i = 1; i <= 2 * M; i += 2) {
		for (int j = 0; j < i && i < M; ++j) {
			printf("*");
		}
		for (int m = 2 * M; m > i && i >= M; --m) {
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}