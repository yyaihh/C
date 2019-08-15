#include "alist.h"
void SListInit(SList* plist) {
	assert(plist);
	plist->_head = NULL;
}
void SListDestory(SList* plist) {//销毁
	assert(plist);
	SListNode* tmp = plist->_head;
	for (SListNode* cur = tmp; tmp; cur = tmp) {
		tmp = cur->_next;
		free(cur);
	}
}
SListNode* BuySListNode(SLTDataType x) {

}
void SListPushFront(SList* plist, SLTDataType x) {//头插
	assert(plist);
	SListNode* cur = (SListNode*)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = plist->_head;
	plist->_head = cur;
}
void SListPopFront(SList* plist) {//头删
	assert(plist);
	SListNode* cur = plist->_head;
	plist->_head = cur->_next;
	free(cur);
	cur = NULL;
}
void SListPushBack(SList* plist, SLTDataType x) {//尾插
	assert(plist);
	SListNode* p;
	for (p = plist->_head; p && p->_next; p = p->_next);
	SListNode* cur = (SListNode*)malloc(sizeof(SListNode));
	cur->_data = x;
	p->_next = cur;
	cur->_next = NULL;
}
void SListPopBack(SList* plist) {//尾删
	assert(plist);
	SListNode* p;
	for (p = plist->_head; p && p->_next && p->_next->_next; p = p->_next);
	free(p->_next);
	p->_next = NULL;
}
SListNode* SListFind(SList* plist, SLTDataType x) {//查找
	assert(plist);
	for (SListNode* cur = plist->_head; cur; cur = cur->_next) {
		if (cur->_data == x) {
			return cur;
		}
	}
	return NULL;
}
void SListInsertAfter(SListNode* pos, SLTDataType x) {// 在pos的后面进行插入
	assert(pos);
	SListNode* cur = (SListNode*)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = pos->_next;
	pos->_next = cur;
}
void SListInsertFront(SList* plist, SListNode* pos, SLTDataType x) {// 在pos的前面进行插入
#if 0
	assert(pos && plist);
	SListNode* newp = (SListNode*)malloc(sizeof(SListNode));
	newp->_data = x;
	SListNode* cur = plist->_head;
	for (; cur != pos && cur->_next != pos && cur; cur = cur->_next);
	if (cur == pos) {
		pos->_next = plist->_head;
		plist->_head = pos;
	}
	else if (cur->_next == pos) { 
		newp->_next = pos;
		cur->_next = newp;
	}
	else {
		printf("pos结点未在次链表中!\n");
	}
#else if //不遍历
	assert(pos && plist);
	SListNode* newp = (SListNode*)malloc(sizeof(SListNode));
	newp->_data = pos->_data;
	newp->_next = pos->_next;
	pos->_next = newp;
	pos->_data = x;
#endif
}
void SListEraseAfter(SListNode* pos) {//删除pos后面的结点
	assert(pos);
	SListNode* tmp = pos->_next;
	if (pos->_next != NULL) {
		pos->_next = pos->_next->_next;
	}
	free(tmp);
}
void SListRemove(SList* plist, SLTDataType x) {
#if 0
	assert(plist);
	SListNode* pos = SListFind(plist, x);
	SListNode* cur = plist->_head;
	for (; cur != pos && cur->_next != pos && cur; cur = cur->_next);
	if (cur == pos) {
		plist->_head = plist->_head->_next;
		free(pos);
	}
	else if (cur->_next == pos && pos) {
		cur->_next = pos->_next;
		free(pos);
	}
	else {
		printf("%d未在此链表中!\n", x);
	}
#else if //不遍历链表
	assert(plist);
	SListNode* pos = SListFind(plist, x);
	if (pos == NULL) {
		printf("链表中没有%d \n", x);
		return;
	}
	SListNode* tmp = pos->_next;
	pos->_data = pos->_next->_data;
	pos->_next = pos->_next->_next;
	free(tmp);
#endif
}
void SListPrint(SList* plist) {
	assert(plist);
	for (SListNode* cur = plist->_head; cur; cur = cur->_next) {
		printf("%d  ", cur->_data);
	}
	putchar('\n');
}