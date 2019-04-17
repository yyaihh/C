#include<stdio.h>
#include<stdlib.h>
void init(int* arr, int x) {
	for (int i = 0; i < x; ++i, ++arr) {
		*arr = i;
	}
}
void reverse(int* arr, int x) {
	for (int i = 0; i < x / 2; ++i) {
		arr[i] = arr[x - i - 1] ^ arr[i];
		arr[x - i - 1] = arr[x - i - 1] ^ arr[i];
		arr[i] = arr[x - i - 1] ^ arr[i];
	}
}
void empty(int* arr,int x) {
	for (int i = 0; i < x; ++i, ++arr) {
		*arr = 0;
	}
}
void print(int* arr,int x) {
	for (int i = 0; i < x; ++i) {
		printf("%d  ", arr[i]);
	}
	printf("\n");
}
void main() {
	int arr[10];
	int l = sizeof(arr) / sizeof(arr[0]);
	init(arr, l);
	print(arr, l);
	reverse(arr, l);
	print(arr, l);
	empty(arr,l);
	print(arr, l);
	system("pause");
}
