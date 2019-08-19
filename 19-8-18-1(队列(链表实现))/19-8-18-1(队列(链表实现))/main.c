#include"queue.h"

int main() {

	Queue test;
	QueueInit(&test);
	for (int i = 1; i <= 10; ++i) {
		QueuePush(&test, i);
	}
	QueuePrint(&test);
	QueuePop(&test);
	QueuePrint(&test);
	printf("%d\n", QueueFront(&test));
	printf("%d\n", QueueBack(&test));
	printf("%d\n", QueueSize(&test));
	system("pause");
	return 0;
}