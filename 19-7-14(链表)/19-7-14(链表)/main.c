#include"alist.h"
int main() {
	SList test;
	SList* p = &test;
	SListInit(p);
	for (int i = 8; i > 0; --i) {
		SListPushFront(p, i);
	}
	for (int i = 9; i < 15; ++i) {
		SListPushBack(p, i);
	}
	SListPrint(p);
	SListPopFront(p);
	SListPopBack(p);
	SListPrint(p);
	printf("%d \n", SListFind(p, 6)->_data);
	SListInsertAfter(SListFind(p, 6), 77);
	SListInsertFront(p, SListFind(p, 10), 99);
	//SListInsertFront(p, SListFind(p, 20), 100);
	SListPrint(p);
	SListEraseAfter(SListFind(p, 12));
	//SListEraseAfter(SListFind(p, 20));
	SListPrint(p);
	SListRemove(p, 4);
	SListRemove(p, 20);
	SListPrint(p);
	SListDestory(p);
	system("pause");
	return 0;
}