#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef int HPDataType;
typedef struct Heap {
	HPDataType* data;
	int size;
	int capicity;
}Heap;
void adjustDown(Heap* hp, int n);//���µ����㷨
void HeapInit(Heap* hp, HPDataType* a, int n);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);//�Ȳ��뵽β����, ��ִ�����ϵ����㷨
void HeapPop(Heap* hp);//�ѵ�ɾ������ɾ���Ѷ���Ԫ��,���Ѷ������������һ��Ҫɾ���Ľ���,Ȼ��ɾ�����һ������, �ٴӸ����µ����㷨
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);//���ضѵĴ�С
int HeapEmpty(Heap* hp);
void HeapPrint(Heap* hp);
void HeapPrint_(Heap* hp);
// ������
void HeapSort(Heap* hp);