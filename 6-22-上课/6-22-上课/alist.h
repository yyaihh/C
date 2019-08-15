#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDataType;
typedef struct SListNode{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;
typedef struct SList{
	SListNode* _head;
}SList;
void SListInit(SList* plist);
void SListDestory(SList* plist);//ȫɾ
SListNode* BuySListNode(SLTDataType x);//
void SListPushFront(SList* plist, SLTDataType x);//ͷ��
void SListPopFront(SList* plist);//ͷɾ
SListNode* SListFind(SList* plist, SLTDataType x);//��
void SListInsertAfter(SListNode* pos, SLTDataType x);// ��pos�ĺ�����в���
//void SListInsertFront(SListNode* pos, SLTDataType x);// ��pos��ǰ����в���
void SListEraseAfter(SListNode* pos);//ɾ��pos����Ľ��
void SListRemove(SList* plist, SLTDataType x);
void SListPrint(SList* plist);
void SListfun(SList* plist);