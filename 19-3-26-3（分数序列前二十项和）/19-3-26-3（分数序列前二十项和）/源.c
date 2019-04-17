#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main() {
	int M;
	double sum = 0;
	double m = 2;
	double n = 1;
	sum =  m / n;
	printf("您需要前几项的和，请输入\n");
	scanf("%d", &M);
	printf("前%d项：\n%d/%d\n",M, (int)m, (int)n);
	for (int i = 1; i < M; ++i) {
		/*交换m与n的值*/
		m = m + n;
		n = m - n;
		m = m - n;
		/**************/
		m += n;
		sum += m / n;
		printf("%d/%d\n", (int) m, (int) n);
	}
	printf("之和等于:\n%lf\n", sum);
	system("pause");
}