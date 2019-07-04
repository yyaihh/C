#include"dequeue.h"
void dequeueInit(DeQueue* qu) {//初始化
	qu->_head = qu->_tail = qu->_data;
	qu->_size = 0;
}
void dequeueDestory(DeQueue* qu) {
	qu->_head = qu->_tail = qu->_data;
	qu->_size = 0;
}
int dequeuEmpty(DeQueue* qu) {
	if (qu->_head == qu->_tail) {
		return 0;
	}
	return 1;
}
int dequeuPush(DeQueue* qu, DataType x) {//增
	if (qu->_tail + 1 == qu->_head || (qu->_tail + 1 - qu->_data == QOEUENUM && qu->_head == qu->_data)) { //满不满
		return 0;
	}
	*qu->_tail = x;
	++qu->_tail;
	if (qu->_tail - qu->_data == QOEUENUM) {
		qu->_tail = qu->_data;
	}
	++qu->_size;
	return 1;
}
void dequeuPrint(DeQueue* qu) {
	DataType *tmp =qu->_tail;
	if (qu->_tail == qu->_data) {
		tmp = qu->_data + QOEUENUM;
	}
	for (DataType *q = qu->_head;q!=tmp;++q) {
		if (q - qu->_data == QOEUENUM) {
			q = qu->_data;
		}
		printf("%d ", *q);
		putchar('\n');
	}
}
int dequeuPop(DeQueue* qu) {//删
	if (dequeuEmpty(qu)) {
		return 0;
	}
	++qu->_head;
	if (qu->_head - qu->_data == QOEUENUM) {
		qu->_head = qu->_data;
	}
	--qu->_size;
	return 1;
}
DataType dequeuFront(DeQueue* qu) {
	return *qu->_head;
}
DataType dequeuBack(DeQueue* qu) {
	if (qu->_tail == qu->_data) {
		return *(qu->_data + QOEUENUM - 1);
	}
	return *(qu->_tail - 1);
}
int dequeuIsEmpty(DeQueue* qu) {
	return qu->_head == qu->_tail;
}
size_t dequeuSize(DeQueue* qu) {
	return qu->_size;
}