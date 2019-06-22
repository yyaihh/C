#include"alist.h"
void SListInit(SList* plist) {
	plist->_head = NULL;
}

void SListPushFront(SList* plist, SLTDataType x) {//头插
	SListNode* cur = (SListNode*)malloc(1 * sizeof(SListNode));
	cur->_next = plist->_head;
	cur->_data = x;
	plist->_head = cur;
}

void SListPopFront(SList* plist) {//头删
	assert(plist);
	if (plist->_head) {
		SListNode* tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}

SListNode* SListFind(SList* plist, SLTDataType x) {//查
	for (SListNode* p = plist->_head; p; p = p->_next) {
		if (p->_data == x) {
			return p;
		}
	}
	return NULL;
}

void SListPrint(SList* plist) {//输出
	assert(plist);
	for (SListNode* p = plist->_head; p; p = p->_next) {
		printf("%d  ", p->_data);
	}
	putchar('\n');
}

void SListDestory(SList* plist) {//销毁
	SListNode* tmp;
	while (plist->_head) {
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}

void SListInsertAfter(SListNode* pos, SLTDataType x) {//在pos后面插入
	SListNode* cur = (SListNode*)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = pos->_next;
	pos->_next = cur;
}

void SListEraseAfter(SListNode* pos) {//删除pos
	SListNode* tmp = pos->_next;
	pos->_next = tmp->_next;
	free(tmp);
}

void SListRemove(SList* plist, SLTDataType x) {
	SListNode* lp = plist->_head;
	for (SListNode* p = plist->_head; p; lp = p, p = p->_next) {
		if (p->_data == x) {
			SListEraseAfter(lp);
			break;
		}
	}
}
