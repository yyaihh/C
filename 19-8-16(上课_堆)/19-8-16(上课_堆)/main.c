#include"heap.h"

int main() {
	int date[10] = { 29,72,48,53,45,30,18,36,15,35};
	Heap hp;
	HeapInit(&hp, date, 10);
	HeapPrint_(&hp);
	putchar('\n');
	HeapPrint(&hp);
	putchar('\n');	
	putchar('\n');


	HeapPush(&hp, 10);
	HeapPrint_(&hp);
	putchar('\n');
	HeapPrint(&hp);
	putchar('\n');
	putchar('\n');

	HeapPop(&hp);
	HeapPrint_(&hp);
	putchar('\n');
	HeapPrint(&hp);
	putchar('\n');
	putchar('\n');


	HeapSort(&hp);
	HeapPrint_(&hp);
	putchar('\n');
	HeapPrint(&hp);
	system("pause");
	return 0;
}