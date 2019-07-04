#pragma once
#include<stdio.h>
#include<stdlib.h>
#define QOEUENUM 5
typedef int DataType;
typedef struct  {
	size_t _size;
	DataType* _head;
	DataType* _tail;
	DataType _data[QOEUENUM];
}DeQueue;
void dequeueInit(DeQueue* qu);//≥ı ºªØ
void dequeueDestory(DeQueue* qu);
int dequeuEmpty(DeQueue* qu);
int dequeuPush(DeQueue* qu, DataType x);
void dequeuPrint(DeQueue* qu);
int dequeuPop(DeQueue* qu);
DataType dequeuFront(DeQueue* qu);
DataType dequeuBack(DeQueue* qu);
int dequeuIsEmpty(DeQueue* qu);
size_t dequeuSize(DeQueue* qu);
