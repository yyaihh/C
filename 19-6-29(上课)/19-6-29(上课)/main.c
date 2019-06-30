#include"List.h"
int main() {//双向带头链表
	List test;
	ListInit(&test);
	for (int i = 10; i > 0; --i) {
		ListPushFront(&test, i);
	}
	ListPopBack(&test);
	ListPopFront(&test);
	ListPrint(&test);
	ListDestory(&test);
	ListPrint(&test);
	system("pause");
	return 0;
}