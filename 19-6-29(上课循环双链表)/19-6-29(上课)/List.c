#include"List.h"
void ListInit(List* plist) {//初始化
	plist->_head = (ListNode*)malloc(sizeof(ListNode));
	memset(&plist->_head->_data, 0, sizeof(LTDataType));
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}
void ListDestory(List* plist) {//销毁
	ListNode* tmp = plist->_head;
	for (;plist->_head->_next!=plist->_head;) {
		ListPopBack(plist);
	}
}
void ListPushBack(List* plist, LTDataType x) {//尾插
	ListNode* cur = (ListNode*)calloc(1, sizeof(ListNode));
	cur->_data = x;

	plist->_head->_prev->_next = cur;
	cur->_prev = plist->_head->_prev;
	cur->_next= plist->_head;
	plist->_head->_prev = cur;
}
void ListPopBack(List* plist) {//尾删
	ListNode* tmp = plist->_head->_prev;
	if (tmp != plist->_head) {
		tmp->_next->_prev = tmp->_prev;
		tmp->_prev->_next = tmp->_next;
		free(tmp);
	}
}
void ListPushFront(List* plist, LTDataType x) {//头插
	ListNode* cur = (ListNode*)calloc(1, sizeof(ListNode));
	cur->_data = x;

	plist->_head->_next->_prev = cur;
	cur->_next = plist->_head->_next;
	cur->_prev = plist->_head;
	plist->_head->_next = cur;
}
void ListPopFront(List* plist) {//头删, 对head后面的
	ListNode* tmp = plist->_head->_next;
	if(tmp!=plist->_head){
		tmp->_next->_prev = tmp->_prev;
		tmp->_prev->_next = tmp->_next;
		free(tmp);
	}
}
ListNode* ListFind(List* plist, LTDataType x);
// 在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x) {//
	
}
void ListErase(ListNode* pos) {// 删除pos位置的节点
	assert(pos);
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}
void ListRemove(List* plist, LTDataType x);
void ListPrint(List* plist) {
	printf("head");
	for (ListNode* p = plist->_head->_next; p != plist->_head; p = p->_next) {
		printf("->%d", p->_data);
	}
	putchar('\n');
}
