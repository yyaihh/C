#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void sort(int a[],int L,int x) {
	int tepm;
	for (int i = 0; i < L; ++i) {
		int m = i;
		for (int j = i + 1; j < L; ++j) {//a[i]���κ�a[i]֮���Ԫ�����Ƚϣ���¼��С���±�
			switch (x) {
				case 0:
					if (a[j] > a[m]) {
						m = j;
					}break;
				case 1:
					if (a[j] < a[m]) {
						m = j;
					}break;
			}
		}
		if (m != i) {
			tepm = a[i];
			a[i] = a[m];
			a[m] = tepm;
		}
	}
}
void main() {
	//int arr[11] = { 0,8,36,45,89,185,234,250,290,300 };
	int arr[11] = { 300,290,250,234,185,89,45,36,8,0 };
	int length = sizeof(arr) / sizeof(arr[0]);
	int X;
	for (int i = 0; i < 10; ++i) {
		printf("%d  ", arr[i]);
	}
	printf("\n��������Ҫ�������\n");
	scanf("%d", &arr[10]);
	if (arr[0] < arr[9]) {//��С����
		X = 1;
	}
	else if (arr[0] > arr[10]) {//�Ӵ�С
		X = 0;
	}
	sort(arr, length, X);
	printf("������Ԫ�غ�����Ϊ;\n");
	for (int i = 0; i < 11; ++i) {
		printf("%d  ", arr[i]);
	}
	printf("\n");
	system("pause");
}
