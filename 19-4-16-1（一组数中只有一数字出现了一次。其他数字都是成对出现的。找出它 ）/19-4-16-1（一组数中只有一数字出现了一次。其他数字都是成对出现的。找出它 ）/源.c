#include<stdio.h>
#include<stdlib.h>
int fun(int arr[], int L){
	int m, j;
	for (int i = 0; i < L; ++i) {
		for ( j = 0; j < L; ++j) {
			if (j == i) {
				continue;
			}
			for (m = 0; m < 32; ++m) {
				if (((arr[i] >> m) & 1) ^ ((arr[j] >> m) & 1)) {
					break;
				}
			}
			if (m == 32) {//˵����һ�����Ͱ�arr[i]��ͬ,������ѭ�������ж���һ����
				break;
			}
		}
		if (j == L) {
			return arr[i];
		}
	}
	return 0;
}
void main() {
	int arr[] = { 1,2,3,4,1,9,2,3,4,5,5 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
		printf("%d  ", arr[i]);
	}
	printf("\nֻ����һ�ε���Ϊ��%d\n", fun(arr,sizeof(arr)/sizeof(arr[0])));
	system("pause");
}