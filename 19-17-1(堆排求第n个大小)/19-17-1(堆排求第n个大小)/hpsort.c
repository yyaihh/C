#include"hpsort.h"
void adjustDown(HPDataType* array, int n, int size) {
	int cur = n;
	int tmp;
	while (cur * 2 + 1 < size) {//ѭ��ֱ�����Ӳ�����
		if (cur * 2 + 2 >= size) {
			n = cur * 2 + 1;//û���Һ���, ֻ��������
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
	for (int i = size / 2 - 1; i >= 0; --i) {//�������ɶ�
		adjustDown(array, i, size);
	}

	while (n--) {//����
		HeapPop(array, &size);
	}
	return array[size];
}

