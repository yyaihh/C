//ѭ������

#include"dequeue.h"
int main() {
	DeQueue test;
	dequeueInit(&test);//��ʼ��
	for (int i = 1; i <= 5; ++i) {
		dequeuPush(&test, i);
	}
	dequeuPop(&test);
	dequeuPush(&test, 10);
	printf("%d\n",dequeuBack(&test));
	dequeuPrint(&test);
	system("pause");
	return 0;
}