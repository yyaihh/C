#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void sort(int a[]) {
	int tepm;
	for (int i = 0; i < 10; ++i) {
		int min = i;
		for (int j = i + 1; j < 10; ++j) {//a[i]���κ�a[i]֮���Ԫ�����Ƚϣ���¼��С���±�
			if (a[j] < a[min]) {
				min = j;
			}
		}
		//��min����iʱ��˵��a[i]����a[i]֮������Ԫ������С��
		// min������iʱ˵��a[i]����a[i]֮������Ԫ������С�ģ���С��Ϊa[mid]�������ǵ�ֵ����
		if (min != i) {
			tepm = a[i];
			a[i] = a[min];
			a[min] = tepm;
		}
	}
	for (int i = 0; i < 10; ++i) {
		printf("%d  ", a[i]);
	}
	printf("\n");
}
void main() {
	int arr[10];
	for (int i = 0; i < 10; ++i) {
		printf("����������arr�ĵ�%d����\n", i + 1);
		scanf("%d", &arr[i]);
		system("cls");
	}
	printf("����arrΪ��\n");
	for (int i = 0; i < 10; ++i) {
		printf("%d  ", arr[i]);
	}
	printf("\n");
	sort(arr);
	system("pause");
}