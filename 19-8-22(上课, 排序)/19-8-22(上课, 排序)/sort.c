#include"sort.h"
#include"queue.h"
void InsertSort(int* src, int size) { //直接插入排序
	//数组越有序插排序越快, 数组规模较小时插排最优
	//稳定的
	//大数据下慢
	//O(n)-O(n^2)
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
	//不稳定
	int j;
	int gap, tmp;
	gap = size / 2;//n/3是最快的
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
	//每层都遍历n个, 一共log2n层
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
	while (src[b] > src[a]) {//如果一开始基准值就是最小的, 没有 = 号 b 就不会 <0
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
	int b = end - 1;//-1是因为接下来交换了最后一个和中间的, 
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
	//int cur = (start + end) / 2;
	int cur = start;
	int tmp = src[cur];
	int a = start;
	int b = end;
	while (a < b) { 
		while (b > start && src[b] > tmp) {
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
int HoareWay(int* src, int start, int end) {
	int a = start + 1;
	int b = end - 2;
	int mid = (start + end) / 2;
	if (src[start] > src[mid]) {
		swapArga(src + start, src + mid);
	}
	if (src[mid] > src[end]) {
		swapArga(src + mid, src + end);
	}
	if (src[start] > src[mid]) {
		swapArga(src + start, src + mid);
	}
	if (end - start <= 2) {
		return mid;
	}
	swapArga(src + mid, src + end - 1);
	while (a <= b) {
		while (a < end - 1&& src[a] <= src[end - 1]) {
			++a;
		}
		while (b > 0 && src[b] >= src[end - 1]) {
			--b;
		}
		if (a == b && (a == 1 || a == end - 1)) {
			break;
		}
		if (a < b) {
			swapArga(src + a, src + b);
		}
	}
	swapArga(src + a, src + end - 1);
	return a;
}
void dealQuickSort(int* src, int start, int end) {
	int mid;
	if (start + 8 < end) {//当数组长度大于8时,快排
		mid = HoareWay(src, start, end);
		dealQuickSort(src, start, mid - 1);
		dealQuickSort(src, mid + 1, end);
	}
	else {//否则进插排
		InsertSort(src + start, end - start + 1);
	}
}
void QuickSort(int* src, int size) {
	dealQuickSort(src, 0, size - 1);
}
void QuickSortNoR(int* src, int size) {
	int start;
	int end;
	int mid;
	Queue qu;
	QueueInit(&qu);
	QueuePush(&qu, 0);
	QueuePush(&qu, size - 1);
	while (!QueueEmpty(&qu)) { 
		start = QueueTop(&qu);
		QueuePop(&qu);
		end = QueueTop(&qu);
		QueuePop(&qu);
		mid = HoareWay(src, start, end);
		if (start < mid - 1) {
			QueuePush(&qu, start);
			QueuePush(&qu, mid);
		}
		if (mid + 1 < end) { 
			QueuePush(&qu, mid + 1);
			QueuePush(&qu, end);
		}
	}
	QueueDestory(&qu);
}