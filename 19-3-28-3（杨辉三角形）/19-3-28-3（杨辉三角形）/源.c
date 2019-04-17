#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main() {
	int m;
	int p, q;
	printf("您要输出多少行的杨辉三角形，请输入(行数限制在33行及以内)\n");
	scanf("%d", &m);
	while (m <= 0 || m > 33) {
		printf("输入有误，请重新输入\n");
		scanf("%d", &m);
	} 
	int* Arr = (int*)malloc(m * sizeof(int));
	printf("行数为%d的杨辉三角形为\n",m);
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