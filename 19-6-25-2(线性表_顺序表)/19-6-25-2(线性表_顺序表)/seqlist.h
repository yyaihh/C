#pragma once
#include<stdio.h>
#include<stdlib.h.>
#include<assert.h>
//Sequence list
typedef int SLDataType;
typedef struct SeqList {
	SLDataType* array;
	size_t size;
	size_t capacity;
}SeqList;
void SeqListInit(SeqList* psl, size_t capacity);//��ʼ��
void SeqListDestory(SeqList* psl);//����
void CheckCapacity(SeqList* psl);//����
void SeqListPushBack(SeqList* psl, SLDataType x);//β��
void SeqListPopBack(SeqList* psl);//βɾ
void SeqListPushFront(SeqList* psl, SLDataType x);//ͷ��
void SeqListPopFront(SeqList* psl);//ͷɾ
int SeqListFind(SeqList* psl, SLDataType x);//����
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);//�ڵ�pos��λ�ò���
void SeqListErase(SeqList* psl, size_t pos);//ɾ����pos��
void SeqListRemove(SeqList* psl, SLDataType x);//ɾ������x
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);//�޸�
void SeqListPrint(SeqList* psl);//���
void SeqListBubbleSort(SeqList* psl);//ð������
int SeqListBinaryFind(SeqList* psl, SLDataType x);//���ֲ���
// ����Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1)
void SeqListRemoveAll(SeqList* psl, SLDataType x);//��������Ļ�����,��xȥ��