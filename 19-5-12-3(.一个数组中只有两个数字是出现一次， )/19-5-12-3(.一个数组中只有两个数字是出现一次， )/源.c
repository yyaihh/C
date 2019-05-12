#include<stdio.h>
#include<stdlib.h>
int fun(int* p, int L) {
	int m;
	int count = 0;
	for (int i = 0; i < L; ++i) {
		for (int j = 0; j < L; ++j) {
			if (j == i) {
				continue;
			}
			for (m = 0; m < 32; ++m) {
				if (((p[i] >> m) & 1) ^ ((p[j] >> m) & 1)) {
					break;
				}
			}
			if (m == 32) {//说明有一个数和啊arr[i]相同,则跳出循环，再判断下一个数
				break;
			}
			if (j == L - 1) {
				++count;
				printf("%d\t", p[i]);
			}
		}
	}
	return count;
}
void main() {
	int arr[] = { 1,2,3,4,1,9,11,2,3,4,5,5 };
	int L = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < L; ++i) {
		printf("%d  ", arr[i]);
	}
	printf("\n");
	printf("\n只出现一次的数有%d个\n",fun(arr, L));
	system("pause");
}
