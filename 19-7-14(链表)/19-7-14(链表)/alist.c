#include "alist.h"
void SListInit(SList* plist) {
	assert(plist);
	plist->_head = NULL;
}
void SListDestory(SList* plist) {//����
	assert(plist);
	SListNode* tmp = plist->_head;
	for (SListNode* cur = tmp; tmp; cur = tmp) {
		tmp = cur->_next;
		free(cur);
	}
}
SListNode* BuySListNode(SLTDataType x) {

}
void SListPushFront(SList* plist, SLTDataType x) {//ͷ��
	assert(plist);
	SListNode* cur = (SListNode*)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = plist->_head;
	plist->_head = cur;
}
void SListPopFront(SList* plist) {//ͷɾ
	assert(plist);
	SListNode* cur = plist->_head;
	plist->_head = cur->_next;
	free(cur);
	cur = NULL;
}
void SListPushBack(SList* plist, SLTDataType x) {//β��
	assert(plist);
	SListNode* p;
	for (p = plist->_head; p && p->_next; p = p->_next);
	SListNode* cur = (SListNode*)malloc(sizeof(SListNode));
	cur->_data = x;
	p->_next = cur;
	cur->_next = NULL;
}
void SListPopBack(SList* plist) {//βɾ
	assert(plist);
	SListNode* p;
	for (p = plist->_head; p && p->_next && p->_next->_next; p = p->_next);
	free(p->_next);
	p->_next = NULL;
}
SListNode* SListFind(SList* plist, SLTDataType x) {//����
	assert(plist);
	for (SListNode* cur = plist->_head; cur; cur = cur->_next) {
		if (cur->_data == x) {
			return cur;
		}
	}
	return NULL;
}
void SListInsertAfter(SListNode* pos, SLTDataType x) {// ��pos�ĺ�����в���
	assert(pos);
	SListNode* cur = (SListNode*)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = pos->_next;
	pos->_next = cur;
}
void SListInsertFront(SList* plist, SListNode* pos, SLTDataType x) {// ��pos��ǰ����в���
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
		printf("pos���δ�ڴ�������!\n");
	}
#else if //������
	assert(pos && plist);
	SListNode* newp = (SListNode*)malloc(sizeof(SListNode));
	newp->_data = pos->_data;
	newp->_next = pos->_next;
	pos->_next = newp;
	pos->_data = x;
#endif
}
void SListEraseAfter(SListNode* pos) {//ɾ��pos����Ľ��
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
		printf("%dδ�ڴ�������!\n", x);
	}
#else if //����������
	assert(plist);
	SListNode* pos = SListFind(plist, x);
	if (pos == NULL) {
		printf("������û��%d \n", x);
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