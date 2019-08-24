#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int QUDataType;
typedef struct QueueNode {
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;
typedef struct Queue {
	QueueNode* _front; // ∂”Õ∑
	QueueNode* _rear; // ∂”Œ≤
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QUDataType x);
void QueuePop(Queue* pq);
QUDataType QueueTop(Queue* pq);
int QueueEmpty(Queue* pq);