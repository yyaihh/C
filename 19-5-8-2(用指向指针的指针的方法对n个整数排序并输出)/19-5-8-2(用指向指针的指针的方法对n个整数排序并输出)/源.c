#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void sort(int** arr, int n) {
	int tepm;
	for (int i = 0; i < n; ++i) {
		int min = i;
		for (int j = i + 1; j < n; ++j) {//a[i]���κ�a[i]֮���Ԫ�����Ƚϣ���¼��С���±�
			if (**(arr + j) < **(arr + min)) {
				min = j;
			}
		}
		//��min����iʱ��˵��a[i]����a[i]֮������Ԫ������С��
		// min������iʱ˵��a[i]����a[i]֮������Ԫ������С�ģ���С��Ϊa[mid]�������ǵ�ֵ����
		if (min != i) {
			tepm = **(arr + i);
			**(arr + i) = **(arr + min);
			**(arr + min) = tepm;
		}
	}
	printf("�����\n");
	for (int i = 0; i <n ; ++i) {
		printf("%d  ", **(arr + i));
	}
	printf("\n");
}
void main() {
	int n;
	printf("������n��ֵ\n");
	scanf("%d",&n);
	int* a = (int*)malloc(n * sizeof(int));
	int** arr= (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; ++i) {
		*(arr + i) = a + i;
	}
	for (int i = 0; i < n; ++i) {
		printf("����������ĵ�%d����\n", i + 1);
		scanf("%d", *(arr + i));
	}
	printf("�����������Ϊ��\n");
	for (int i = 0; i < n; ++i) {
		printf("%d  ", **(arr + i));
	}
	printf("\n");
	sort(arr, n);
	system("pause");
}