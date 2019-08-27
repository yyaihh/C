#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100

inline void Swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
int doublePointerWay1(int* src, int start, int end) {
	int a = start;
	int b = end;
	int flag = 0;//flag==0ʱ��ָ������,����1ʱ��ָ������
	while (src[b] > src[a]) {
		--b;
	}
	while (a < b) {
		flag = !flag;
		Swap(src + a, src + b);
		for (; src[b] >= src[a]; flag ? ++a : --b);
	}
	return flag ? b : a;//��ǩ����ֵָʾ�ĸ�ָ���ƶ�, ���ָ���Խ������һ��ָ��, �������û�����Ǹ�ָ��
}
int doublePointerWay2(int* src, int start, int end) {
	int a = start;
	int mid = (start + end) / 2;
	int b = end - 1;
	Swap(src + mid, src + end);
	while (a <= b) {
		for (; a < end && src[a] <= src[end]; ++a);
		for (; b > 0 && src[b] >= src[end]; --b);
		if (a == b && (a == 0 || a == end)) {
			break;
		}
		if (a < b) {
			Swap(src + a, src + b);
		}
	}
	Swap(src + a, src + end);
	return a;
}
int digWay(int* src, int start, int end) {

}
void dealQuickSort(int* src, int start, int end) {
	if (start < end) {
		int mid = doublePointerWay2(src, start, end);
		dealQuickSort(src, start, mid - 1);
		dealQuickSort(src, mid + 1, end);
	}
}
void QuickSort(int* src, int size) {
	dealQuickSort(src, 0, size - 1);
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
	QuickSort(src, N);
	QuickSort(src1, 10);
	PrintArray(src1, 10);
	//printf("�����:\n");
	PrintArray(src, N);
	system("pause");
	return 0;
}