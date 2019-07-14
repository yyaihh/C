#include"seqlist.h"
int main() {
	SeqList test;
	SeqList* p = &test;
	SeqListInit(p,10);
	for (int i = 0; i < 12; ++i) {
		SeqListPushFront(p, i + 1);
	}
	SeqListPushFront(p, 0);
	SeqListPushFront(p, -1);
	SeqListPrint(p);
	printf("\n\n");
	SeqListPopBack(p);
	SeqListPopFront(p);
	SeqListPrint(p);
	printf("\n\n");
	printf("%d\n",p->array[SeqListFind(p, 5)]);
	SeqListInsert(p, 4, 4);
	SeqListInsert(p, 6, 4);
	SeqListErase(p, 2);
	SeqListPrint(p);
	printf("\n\n");
	SeqListRemove(p, 4);
	SeqListPrint(p);
	printf("\n\n");
	SeqListBubbleSort(p);
	SeqListPrint(p);
	printf("\n\n");
	printf("%d\n", p->array[SeqListBinaryFind(p, 5)]);
	SeqListInsert(p, 4, 4);
	SeqListInsert(p, 6, 4);
	SeqListInsert(p, 7, 4);
	SeqListBubbleSort(p);
	SeqListPrint(p);
	printf("\n\n");
	SeqListRemoveAll(p, 4);
	SeqListPrint(p);
	printf("\n\n");
	SeqListDestory(p);
	system("pause");
	return 0;
}