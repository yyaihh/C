#include"List.h"
int main() {//˫���ͷ����
	List test;
	ListInit(&test);
	for (int i = 10; i > 0; --i) {
		ListPushFront(&test, i);
	}
	ListPopBack(&test);
	ListPopFront(&test);
	ListInsert(ListFind(&test,5), 55);
	ListPrint(&test);
	ListRemove(&test, 55);
	ListPrint(&test);
	ListDestory(&test);
	ListPrint(&test);
	system("pause");
	return 0;
}