#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main() {
	int m;
	int p, q;
	printf("��Ҫ��������е���������Σ�������(����������33�м�����)\n");
	scanf("%d", &m);
	while (m <= 0 || m > 33) {
		printf("������������������\n");
		scanf("%d", &m);
	} 
	int* Arr = (int*)malloc(m * sizeof(int));
	printf("����Ϊ%d�����������Ϊ\n",m);
	for (int i = 0; i < m; ++i) {  
		 p = 0;
		for (int j = 0; j <= i; ++j) {
			q = Arr[j];
			Arr[j] = q + p;
			p = q;
			Arr[i] = 1;
			printf("%d  ", Arr[j]);
		}
		printf("\n");
	}
	system("pause");
}