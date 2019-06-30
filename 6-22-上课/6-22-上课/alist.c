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
		tmp = NULL;
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
void SListfun(SList* plist) {
	assert(plist);
	SListNode* tmp1;
	SListNode* tmp2;
	/*for (SListNode* p = plist->_head; p;tmp = tmp->_next, p = p->_next) {
		p->_next = tmp;
		tmp = p->_next;
	}*/

	/*SListNode* head = plist->_head;
	for (SListNode* p = plist->_head; p; p = p->_next) {
		head->_next
		head = p;

	}*/

	/*SListNode* tmp;
	SListNode* cur = plist->_head;
	for (;tmp = cur->_next;) {
		cur->_next = tmp->_next;
		tmp->_next = plist->_head;
		plist->_head = tmp;
	}*/

	SListNode* tmp = NULL;
	SListNode* head = NULL;
	while(tmp = plist->_head) {
		plist->_head = tmp->_next;
		tmp->_next = head;
		head = tmp;
	}
	plist->_head = head;


}
SListNode *detectCycle(SList* plist) {
	SListNode* tmp = NULL;
	if (plist->_head == NULL || plist->_head->_next == NULL) {
		return NULL;
	}
	for (SListNode* p = plist->_head->_next, *q = head->_next->_next; p&&q; p = p->_next) {
		if (p == q) {
			tmp = p;
			break;
		}
		if (q->_next == NULL) {
			return NULL;
		}
		q = q->_next->_next;
	}
	if (tmp == NULL) {
		return NULL;
	}
	for (SListNode* p = plist->_head, *q = tmp; p&&q; p = p->_next, q = q->_next) {
		if (p == q) {
			return p;
		}
	}
	return NULL;
}
SListNode *getIntersectionNode(SList* plistA, SList* plistB) {
	int i = 0;
	int j = 0;
	SListNode* tmp;
	for (tmp = plistA->_head; tmp; tmp = tmp->_next, ++i);
	for (tmp = plistB->_head; tmp; tmp = tmp->_next, ++j);
	if (i > j) {
		for (i = i - j; i; plistA->_head = plistA->_head->_next, --i);
	}
	else if (j > i) {
		for (j = j - i; j; plistB->_head = plistB->_head->_next, --j);
	}
	for (; plistA->_head; plistA->_head = plistA->_head->_next, plistB->_head = plistB->_head->next) {
		if (plistA->_head == plistB->_head) {
			return plistA->_head;
		}
	}
	return NULL;
}