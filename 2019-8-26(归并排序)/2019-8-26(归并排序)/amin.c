#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100
void dealMergeSort(int* src, int* tmp, int start, int end) {
	if (start >= end) {//ǰ��ָ�뽻��, �Ѿ��������
		return;
	}
	int mid = (start + end) / 2;
	dealMergeSort(src, tmp, start, mid);
	dealMergeSort(src, tmp, mid + 1, end);
	int a = start;//�ֺ�ǰһ�����������ʼ����
	int b = mid + 1;//�ֺ��һ�����������ʼ����
	int c = start;//��ʱ������ʼ����, ���洢ǰ��������������鲢�����������
	while (a <= mid && b <= end) {
		if(src[a]<src[b]){
			tmp[c] = src[a];
			++a;
		}
		else {
			tmp[c] = src[b];
			++b;
		}
		++c;
	}
	//ѭ������ʱ��һ������������������ͬʱ�������� , ��δ�������һ������ʢ�ĵĿ϶��Ǳ���һ����������������ֵ�������������
	//ֱ�Ӹ���ʱ����tmp
	//��������forѭ��ֻ��һ��
	for (; a <= mid; ++a,++c) {
		tmp[c] = src[a];
	}
	for (; b <= end; ++b, ++c) {
		tmp[c] = src[b];
	}
	//��������ʱ�����еĺϲ������������ٸ�����������src
	for (int i = start; i <= end; ++i) {
		src[i] = tmp[i];
	}
}
void MergeSort(int* src, int size) {
	int* tmp = (int*)malloc(size * sizeof(src[0]));
	dealMergeSort(src, tmp, 0, size - 1);
	free(tmp);
}
void PrintArray(int* src, int size) {
	for (int i = 0; i < size; ++i) {
		printf("%d ", src[i]);
	}
	putchar('\n');
}
int main() {
	srand((unsigned int)time(0));
	int src[N];
	int src1[10] = { 8,7,10,2,3,5,6,1,4,9 };
	for (int i = 0; i < N; ++i) {
		src[i] = rand() % N + 1;
	}
	//printf("����ǰ:\n");
	//PrintArray(src, N);
	MergeSort(src, N);
	MergeSort(src1, 10);
	PrintArray(src1, 10);
	//printf("�����:\n");
	PrintArray(src, N);
	system("pause");
	return 0;
}
