#include<stdio.h>
#include<stdlib.h>
#define N 10
void main() {
	int sum = 1;
	for (int i = 1; i < N; ++i) {
		sum = 2 * (sum + 1);
	}
	printf("��һ�칲ժ��%d������\n", sum);
	system("pause");
}