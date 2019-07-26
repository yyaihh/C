#include "alist.h"
void SListInit(SList* plist) {
	assert(plist);
	plist->_head = NULL;
}
void SListDestory(SList* plist) {//����
	assert(plist);
	SListNode* tmp = plist->_head;
	for (SListNode* cur; tmp; cur = tmp) {
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
void SListPopBack(SList* plist, SLTDataType x) {//β��
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
// ��pos��ǰ����в���
void SListEraseAfter(SListNode* pos);
void SListRemove(SList* plist, SLTDataType x);
void SListPrint(SList* plist);
void TestSList();