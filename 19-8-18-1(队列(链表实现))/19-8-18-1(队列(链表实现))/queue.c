#include"queue.h"
void QueueInit(Queue* pq) {
	assert(pq);
	pq->_front = NULL;
	pq->_rear = NULL;
}
void QueueDestory(Queue* pq) {
	assert(pq);
	QueueNode* tmp;
	while (pq->_front) {
		tmp = pq->_front;
		pq->_front = tmp->_next;
		free(tmp);
	}
}
void QueuePush(Queue* pq, QUDataType x) {
	assert(pq);
	QueueNode* cur = (QueueNode*)calloc(1, sizeof(QueueNode));
	cur->_data = x;
	if (pq->_front == NULL) {
		pq->_front = pq->_rear = cur;
	}
	cur->_next = NULL;
	pq->_rear->_next = cur;
	pq->_rear = cur;
}
void QueuePop(Queue* pq) {
	assert(pq);
	QueueNode* tmp;
	tmp = pq->_front;
	pq->_front = tmp->_next;
	free(tmp);
}
QUDataType QueueFront(Queue* pq) {
	assert(pq);
	return pq->_front->_data;
}
QUDataType QueueBack(Queue* pq) {
	assert(pq);
	return pq->_rear->_data;
}
int QueueEmpty(Queue* pq) {
	assert(pq);
	return pq->_front == NULL;
}
int QueueSize(Queue* pq) {
	assert(pq);
	QueueNode* cur = pq->_front;
	int count = 0;
	while (cur) {
		++count;
		if (cur == pq->_rear) {
			break;
		}
		cur = cur->_next;
	}
	return count;
}
void QueuePrint(Queue* pq) {
	assert(pq);
	for (QueueNode* cur = pq->_front; cur; cur = cur->_next) {
		printf("%d ", cur->_data);
		if (cur == pq->_rear) {
			break;
		}
	}
	putchar('\n');
}

