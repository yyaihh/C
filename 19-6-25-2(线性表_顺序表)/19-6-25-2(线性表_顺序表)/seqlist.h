#pragma once
#include<stdio.h>
#include<stdlib.h.>
#include<assert.h>
//Sequence list
typedef int SLDataType;
typedef struct SeqList {
	SLDataType* array;
	size_t size;
	size_t capicity;
}SeqList;
void SeqListInit(SeqList* psl, size_t capacity);//初始化
void SeqListDestory(SeqList* psl);
void CheckCapacity(SeqList* psl);
void SeqListPushBack(SeqList* psl, SLDataType x);//尾插
void SeqListPopBack(SeqList* psl);//尾删
void SeqListPushFront(SeqList* psl, SLDataType x);//头插
void SeqListPopFront(SeqList* psl);
int SeqListFind(SeqList* psl, SLDataType x);
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
void SeqListErase(SeqList* psl, size_t pos);
void SeqListRemove(SeqList* psl, SLDataType x);
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);
void SeqListPrint(SeqList* psl);//输出
void SeqListBubbleSort(SeqList* psl);//冒泡排序
int SeqListBinaryFind(SeqList* psl, SLDataType x);//二分查找
// 本题要求：时间复杂度：O(N) 空间复杂度 O(1)
void SeqListRemoveAll(SeqList* psl, SLDataType x);//在先排序的基础上,将x去重