#include"sort.h"
void InsertSort(int* src, int size) { //ֱ�Ӳ�������
	//����Խ���������Խ��, �����ģ��Сʱ��������
	//�ȶ���
	int j;
	int tmp;
	for (int i = 1; i < size; ++i) {
		tmp = src[i];
		for (j = i ; j > 0 && src[j - 1] > tmp ; --j) {
			src[j] = src[j - 1];
		}
		src[j] = tmp;
	}
}
void ShellSort(int* src, int size) {
	//���ȶ�
	int j;
	int gap, tmp;
	gap = size / 2;//n/3������
	for (int k = 0; gap; ++k) {
		if (k >= gap) {
			gap /= 2;
			k = -1;
			continue;
		}
		for (int i = gap + k; i < size ; i += gap) { 
			tmp = src[i];
			for (j = i; j >= gap && src[j - gap] > tmp; j -= gap) { 
				src[j] = src[j - gap];
			}
			src[j] = tmp;
		}
	}
}
void dealMergeSort(int* src, int* tmp, int start, int end) {
	//ÿ�㶼����n��, һ��log2n��
	if (start >= end) {
		return;
	}
	int mid = (start + end) / 2;
	dealMergeSort(src, tmp, start, mid);
	dealMergeSort(src, tmp, mid + 1, end);
	int a = start;
	int b = mid + 1;
	int c = start;
	while (a <= mid && b <= end) {
		if (src[a] < src[b]) { 
			tmp[c] = src[a];
			++a;
		}
		else {
			tmp[c] = src[b];
			++b;
		}
		++c;
	}
	for (; a <= mid; ++a, ++c) {
		tmp[c] = src[a];
	}
	for (; b <= end; ++b, ++c) {
		tmp[c] = src[b];
	}
	for (int i = start; i <= end; ++i) {
		src[i] = tmp[i];
	}
}
void MergeSort(int* src, int size) {
	int* tmp = (int*)calloc(size, sizeof(int));
	dealMergeSort(src, tmp, 0, size - 1);
	free(tmp);
}
void swapArga(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
int doublePointerWay1(int* src, int start, int end) {
	int a = start;
	int b = end;
	int flag = 0;
	while (src[b] > src[a]) {//���һ��ʼ��׼ֵ������С��, û�� = �� b �Ͳ��� <0
		--b;
	}
	while (a < b) { 
		flag = !flag;
		swapArga(src + a, src + b);
		while (src[b] >= src[a]) {
			flag ? ++a : --b;
		}
	}
	return flag ? b : a;
}

int doublePointerWay2(int* src, int start, int end) {
	int mid = (start + end) / 2;
	int a = start;
	int b = end - 1;//-1����Ϊ���������������һ�����м��, 
	swapArga(src + mid, src + end);
	while (a <= b) { 
		while (a < end && src[a] <= src[end]) { 
			++a;
		}
		while (b > 0 && src[b] >= src[end]) { 
			--b;
		}
		if (a == b && (a == 0 || a == end)) {
			break;
		}
		if (a < b) {
			swapArga(src + a, src + b);
		}
	}
	swapArga(src + a, src + end);
	return a;
}
int doublePointerWay3(int* src, int start, int end) {
	int cur = (start + end) / 2;
	//int mid = start;
	int tmp = src[cur];
	int a = start;
	int b = end;
	while (a < b) { 
		while (b > 0 && src[b] > tmp) {
			--b;
		}
		if (a < b) {
			src[cur] = src[b];
			cur = b;
		}

		while (a < end && src[a] <= tmp) {
			++a;
		}
		if (a < b) {
			src[cur] = src[a];
			cur = a;
		}
	}
	src[cur] = tmp;
	return cur;
}
void dealQuickSort(int* src, int start, int end) {
	int mid;
	if (start < end) {
		mid = doublePointerWay3(src, start, end);
		dealQuickSort(src, start, mid - 1);
		dealQuickSort(src, mid + 1, end);
	}
}
void QuickSort(int* src, int size) {
	dealQuickSort(src, 0, size - 1);
}