#include<stdio.h>
#include<stdlib.h>
void main() {
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	printf("ԭ����\n");
	for (int i = 0; i < 10; ++i) {
		printf("%d  ", arr[i]);
	}
	printf("\n");
	for (int j = 0; j < 10 / 2; ++j) {
		arr[j] = arr[j] ^ arr[9 - j];
		arr[9 - j] = arr[j] ^ arr[9 - j];
		arr[j] = arr[j] ^ arr[9 - j];
	}
	printf("�����������\n");
	for (int i = 0; i < 10; ++i) {
		printf("%d  ", arr[i]);
	}
	printf("\n");
	system("pause");
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    