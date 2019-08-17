#include"hpsort.h"
void adjustDown(HPDataType* array, int n, int size) {
	int cur = n;
	int tmp;
	while (cur * 2 + 1 < size) {//循环直到左孩子不存在
		if (cur * 2 + 2 >= size) {
			n = cur * 2 + 1;//没有右孩子, 只能是左孩子
		}
		else if (array[cur * 2 + 1] > array[cur * 2 + 2]) {
			n = cur * 2 + 1;
		}
		else {
			n = cur * 2 + 2;
		}

		if (array[cur] < array[n]) {
			tmp = array[cur];
			array[cur] = array[n];
			array[n] = tmp;
			cur = n;
		}
		else {
			break;
		}
	}
}
void HeapPop(HPDataType* array, int* size) {
	/*if (size == 0) {
		return;
	}*/
	--*size;
	int tmp = array[0];
	array[0] = array[*size];
	array[*size] = tmp;
	adjustDown(array, 0, *size);
}
int HeapSort(HPDataType* array, int size,int n) {
	for (int i = size / 2 - 1; i >= 0; --i) {//将数组变成堆
		adjustDown(array, i, size);
	}

	while (n--) {//排序
		HeapPop(array, &size);
	}
	return array[size];
}

