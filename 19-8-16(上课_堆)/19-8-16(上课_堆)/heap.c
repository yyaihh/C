#include"heap.h"
void adjustDown(Heap* hp, int n) {//���µ����㷨, n:�±�(���ĸ��ڵ㿪ʼ����ִ��)
	int cur = n;
	int tmp;
	while (cur * 2 + 1 < hp->size) {//ѭ��ֱ�����Ӳ�����
		if (cur * 2 + 2 >= hp->size) {
			n = cur * 2 + 1;//û���Һ���, ֻ��������
		}
		else if (hp->data[cur * 2 + 1] > hp->data[cur * 2 + 2]) {
			n = cur * 2 + 1;
		}
		else {
			n = cur * 2 + 2;
		}

		if (hp->data[cur] < hp->data[n]) {
			tmp = hp->data[cur];
			hp->data[cur] = hp->data[n];
			hp->data[n] = tmp;
			cur = n;
		}
		else {//���ָ��ڵ��ֵ�ȸոձƳ�����ҪС(��),�ٲ��ñ���,����
			break;
		}
	}
}
void HeapInit(Heap* hp, HPDataType* a, int n) {
	hp->capicity = 2 * n;
	hp->size = n;//��ʼ���˳���Ϊn������
	hp->data = (HPDataType*)calloc(hp->capicity, sizeof(HPDataType));
	for (int i = 0; i < n; ++i) {
		hp->data[i] = a[i];
	}
	for (int i = n / 2 - 1; i >= 0; --i) {
		adjustDown(hp, i);
	}
}
void HeapDestory(Heap* hp) {
	if (hp->data) {
		free(hp->data);
	}
	hp->data = NULL;
	hp->capicity = 0;
	hp->size = 0;
}

void HeapPush(Heap* hp, HPDataType x) {
	int tmp;
	if (hp->size == hp->capicity) {
		hp->capicity *= 2;
		hp->data = (HPDataType*)realloc(hp->data, hp->capicity * sizeof(HPDataType));
	}
	int cur = hp->size;//�±�
	hp->data[hp->size] = x;
	hp->size++;
	while (cur > 0) { 
		if (hp->data[cur] > hp->data[(cur - 1) / 2]) {//(cur - 1) / 2 Ϊ���׽ڵ�,���ڸ��׽ڵ��򽻻�,�������������
			tmp = hp->data[cur];
			hp->data[cur] = hp->data[(cur - 1) / 2];
			hp->data[(cur - 1) / 2] = tmp;
			cur = (cur - 1) / 2;//�±�仯
		}
		else {
			break;
		}
	}
}
void HeapPop(Heap* hp) {
	//�ѵ�ɾ������ɾ���Ѷ���Ԫ��,���Ѷ������������һ��Ҫɾ���Ľ���
	//Ȼ��ɾ�����һ������, �ٴӸ����µ����㷨
	if (hp->size == 0) {
		return;
	}
	--hp->size;
	int tmp = hp->data[0];
	hp->data[0] = hp->data[hp->size];
	hp->data[hp->size] = tmp;
	adjustDown(hp,0);
}
HPDataType HeapTop(Heap* hp) {//���ضѶ�
	if (hp->size == 0) {
		return (HPDataType)0;
	}
	return hp->data[0];

}
int HeapSize(Heap* hp) {//���ضѵĴ�С
	return hp->size;
}
int HeapEmpty(Heap* hp){
	return hp->size != 0;
}
void HeapPrint(Heap* hp) {
		for (int j = 0; j < hp->size ; ++j) {
			printf("%d ", hp->data[j]);
		}
		putchar('\n');
}
void HeapPrint_(Heap* hp) {
	int m = 1;
	int n = 1;
	for (int i = 0; i < hp->size; ++i) {
		printf("%d ", hp->data[i]);
		if (i + 1 == m) {
			n *= 2;
			m = m + n;
			putchar('\n');
		}
	}
	putchar('\n');
}
// ������
void HeapSort(Heap* hp) { 
	int tmp = hp->size;
	while (hp->size > 1) {
		HeapPop(hp);
	}
	hp->size = tmp;
}