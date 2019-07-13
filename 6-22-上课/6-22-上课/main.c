#include"seqList.h"
#include"alist.h"
#if 1
int main() {
	SeqList test;
	SeqListInit(&test, 15);
	for (int i = 1; i <= 10; ++i) {
		SeqListPushBack(&test, i);
	}
	SeqListPushFront(&test, 0);
	SeqListPushFront(&test, -1);
	SeqListInsert(&test, 5, 100);//第5个位置插入
	SeqListModify(&test, 7, 50);//第7个改为50
	SeqListPrint(&test);
	putchar('\n');
	SeqListErase(&test, 8);//删除第8
	SeqListRemove(&test, 3);//查找3,再删除
	SeqListBubbleSort(&test);
	printf("%d\n\n\n", test.array[SeqListBinaryFind(&test, 100)]);
	SeqListPrint(&test);
	SeqListDestory(&test);
	system("pause");
	return 0;
}
#endif

#if 0
int main() {
	SList test;
	SList test1;
	SListInit(&test);
	for (int i = 10; i > 0; --i) {
		SListPushFront(&test, i);
	}
	SListInit(&test1);
	for (int i = 0; i < 10; ++i) {
		SListPushFront(&test, i);
	}
	SListPopFront(&test);
	SListInsertAfter(SListFind(&test, 5), 100);
	SListRemove(&test, 3);
	SListPrint(&test);
	SListfun(&test);
	SListPrint(&test);
	//printf("\n%d\n", SListFind(&test, 8)->_data);
	//printf("\n%d\n", SListFind(&test, 12)->_data);
	SListDestory(&test);
	system("pause");
	return 0;
}
#endif