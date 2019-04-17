#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main() {
	int sum;
	int arr[20] = { 0 };
	int n;
	for (int i = 1; i < 1000; ++i) {
		sum = 0;
		n = 0;
		for (int j = 1; j < i; ++j) {
			if (i % j == 0) {
				sum += j;//统计因子只和
				arr[n] = j;
				++n;
			}
		}
		if (i == sum) {//如果因子之和等于这个数
			printf("%d its factors are ", i);
			for (int m = 0; m < n; ++m) {
				printf("%d", arr[m]);
				if (m < n - 1) {
					printf(",");
				}
			}
			printf("\n");
		}
	}
	system("pause");
}