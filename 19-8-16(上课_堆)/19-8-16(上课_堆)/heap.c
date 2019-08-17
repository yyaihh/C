#include"heap.h"
void adjustDown(Heap* hp, int n) {//向下调整算法, n:下标(从哪个节点开始向下执行)
	int cur = n;
	int tmp;
	while (cur * 2 + 1 < hp->size) {//循环直到左孩子不存在
		if (cur * 2 + 2 >= hp->size) {
			n = cur * 2 + 1;//没有右孩子, 只能是左孩子
		}
		else if (hp->data[cur * 2 + 1] > hp->data[cur * 2 + 2]) {
			n = cur * 2 + 1;
		}
		else {
			n = cur * 2 + 2;
		}

		if (hp->data[cur] < hp->data[n]) {
			tmp = hp->data[cur];
			hp->data[cur] = hp->data[n];
			hp->data[n] = tmp;
			cur = n;
		}
		else {//出现根节点的值比刚刚逼出来的要小(大),再不用比了,跳出
			break;
		}
	}
}
void HeapInit(Heap* hp, HPDataType* a, int n) {
	hp->capicity = 2 * n;
	hp->size = n;//初始化了长度为n的数组
	hp->data = (HPDataType*)calloc(hp->capicity, sizeof(HPDataType));
	for (int i = 0; i < n; ++i) {
		hp->data[i] = a[i];
	}
	for (int i = n / 2 - 1; i >= 0; --i) {
		adjustDown(hp, i);
	}
}
void HeapDestory(Heap* hp) {
	if (hp->data) {
		free(hp->data);
	}
	hp->data = NULL;
	hp->capicity = 0;
	hp->size = 0;
}

void HeapPush(Heap* hp, HPDataType x) {
	int tmp;
	if (hp->size == hp->capicity) {
		hp->capicity *= 2;
		hp->data = (HPDataType*)realloc(hp->data, hp->capicity * sizeof(HPDataType));
	}
	int cur = hp->size;//下标
	hp->data[hp->size] = x;
	hp->size++;
	while (cur > 0) { 
		if (hp->data[cur] > hp->data[(cur - 1) / 2]) {//(cur - 1) / 2 为父亲节点,大于父亲节点则交换,否则则符合跳出
			tmp = hp->data[cur];
			hp->data[cur] = hp->data[(cur - 1) / 2];
			hp->data[(cur - 1) / 2] = tmp;
			cur = (cur - 1) / 2;//下标变化
		}
		else {
			break;
		}
	}
}
void HeapPop(Heap* hp) {
	//堆的删除就是删除堆顶的元素,将堆顶的数据与最后一个要删除的交换
	//然后删除最后一个数据, 再从根向下调整算法
	if (hp->size == 0) {
		return;
	}
	--hp->size;
	int tmp = hp->data[0];
	hp->data[0] = hp->data[hp->size];
	hp->data[hp->size] = tmp;
	adjustDown(hp,0);
}
HPDataType HeapTop(Heap* hp) {//返回堆顶
	if (hp->size == 0) {
		return (HPDataType)0;
	}
	return hp->data[0];

}
int HeapSize(Heap* hp) {//返回堆的大小
	return hp->size;
}
int HeapEmpty(Heap* hp){
	return hp->size != 0;
}
void HeapPrint(Heap* hp) {
		for (int j = 0; j < hp->size ; ++j) {
			printf("%d ", hp->data[j]);
		}
		putchar('\n');
}
void HeapPrint_(Heap* hp) {
	int m = 1;
	int n = 1;
	for (int i = 0; i < hp->size; ++i) {
		printf("%d ", hp->data[i]);
		if (i + 1 == m) {
			n *= 2;
			m = m + n;
			putchar('\n');
		}
	}
	putchar('\n');
}
// 堆排序
void HeapSort(Heap* hp) { 
	int tmp = hp->size;
	while (hp->size > 1) {
		HeapPop(hp);
	}
	hp->size = tmp;
}