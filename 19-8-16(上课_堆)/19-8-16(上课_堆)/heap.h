#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef int HPDataType;
typedef struct Heap {
	HPDataType* data;
	int size;
	int capicity;
}Heap;
void adjustDown(Heap* hp, int n);//向下调整算法
void HeapInit(Heap* hp, HPDataType* a, int n);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);//先插入到尾巴上, 在执行向上调整算法
void HeapPop(Heap* hp);//堆的删除就是删除堆顶的元素,将堆顶的数据与最后一个要删除的交换,然后删除最后一个数据, 再从根向下调整算法
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);//返回堆的大小
int HeapEmpty(Heap* hp);
void HeapPrint(Heap* hp);
void HeapPrint_(Heap* hp);
// 堆排序
void HeapSort(Heap* hp);