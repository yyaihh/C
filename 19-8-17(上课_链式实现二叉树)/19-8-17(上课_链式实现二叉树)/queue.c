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
QUDataType QueueTop(Queue* pq) {
	assert(pq);
	return pq->_front->_data;
}

int QueueEmpty(Queue* pq) {
	assert(pq);
	return pq->_front == NULL;
}