#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main() {
	int M;
	double sum = 0;
	double m = 2;
	double n = 1;
	sum =  m / n;
	printf("����Ҫǰ����ĺͣ�������\n");
	scanf("%d", &M);
	printf("ǰ%d�\n%d/%d\n",M, (int)m, (int)n);
	for (int i = 1; i < M; ++i) {
		/*����m��n��ֵ*/
		m = m + n;
		n = m - n;
		m = m - n;
		/**************/
		m += n;
		sum += m / n;
		printf("%d/%d\n", (int) m, (int) n);
	}
	printf("֮�͵���:\n%lf\n", sum);
	system("pause");
}