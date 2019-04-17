#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int binsearch(int a[],int x,int right) {
	int left = 0;
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (x > a[mid]) {
			left = mid + 1;
		}
		else if (x < a[mid]) {
			right = mid - 1;
		}
		else{
			return mid;
		}
	}
	if (left > right) {
		return -1;
	}
}
void main(){
	int arr[] = { 1,3,4,5,7,8,11,12,14,15 };
	int key;
	printf("��������Ҫ���ҵ���\n");
	scanf("%d", &key);
	int R = sizeof(arr) / sizeof(arr[0]) - 1;
	if (binsearch(arr, key, R) != -1) {
		printf("�ҵ��ˣ��±�Ϊ%d\n", binsearch(arr, key, R));
	}
	else {
		printf("û���ҵ�\n");
	}
	system("pause");
}
