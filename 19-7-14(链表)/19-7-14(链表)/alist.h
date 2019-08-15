#pragma once
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;
typedef struct SList
{
	SListNode* _head;
}SList;
void SListInit(SList* plist);
void SListDestory(SList* plist);
SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SList* plist, SLTDataType x);//头插
void SListPopFront(SList* plist);//头删
void SListPushBack(SList* plist, SLTDataType x);//尾插
void SListPopBack(SList* plist);//尾删
SListNode* SListFind(SList* plist, SLTDataType x);//查找
void SListInsertAfter(SListNode* pos, SLTDataType x);// 在pos的后面进行插入
void SListInsertFront(SList* plist, SListNode* pos, SLTDataType x);// 在pos的前面进行插入
void SListEraseAfter(SListNode* pos);//删除pos后面的结点
void SListRemove(SList* plist, SLTDataType x);
void SListPrint(SList* plist);