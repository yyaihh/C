#include"seqList.h"
void SeqListInit(SeqList* psl, size_t capicity) {//��ʼ��
	assert(psl);//��Ҫ��������
	psl->capicity = capicity;
	psl->array = (SLDataType*)calloc(capicity, sizeof(SLDataType));
	psl->size = 0;
}
void SeqListDestory(SeqList* psl) {
	assert(psl);//��Ҫ��������
	if (psl->array) {
		free(psl->array);
		psl->size = 0;
		psl->capicity = 0;
	}
}
void CheckCapacity(SeqList* psl) {//
	assert(psl);
	if (psl->size == psl->capicity) {
		psl->capicity *= 2;
		psl->array = (SLDataType*)realloc(psl->array, psl->capicity * sizeof(SLDataType));
	}
}
void SeqListPushBack(SeqList* psl, SLDataType x) {//β��
	assert(psl);
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}
void SeqListPopBack(SeqList* psl) {//βɾ
	assert(psl || psl->size);
	psl->size--;
}
void SeqListPushFront(SeqList* psl, SLDataType x) {//ͷ��
	assert(psl);
	for (int i = psl->size - 1; i >= 0; --i) {
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[0] = x;
	psl->size++;
}
void SeqListPopFront(SeqList* psl) {//ͷɾ
	assert(psl);
	for (int i = 0; i < (int)psl->size - 1; ++i) {
		psl->array[i] = psl->array[i + 1];
	}
}
int SeqListFind(SeqList* psl, SLDataType x) {//����
	assert(psl);
	
	for(int i = 0; i < (int)psl->size; ++i) {
		if (x == psl->array[i]) {
			return i;
		}
	}
	return -1;
}
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x) {//λ�ò���
	assert(psl || (pos <= psl->size));
	for (int i = psl->size - 1; i > (int)pos; --i) {
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[pos] = x;
	psl->size++;
}
void SeqListErase(SeqList* psl, size_t pos) {//ɾ��
	assert(psl || (pos - 1 < psl->size));
	for (int i = pos - 1; i < (int)psl->size - 1; ++i) {
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}
void SeqListRemove(SeqList* psl, SLDataType x) {//��ɾ
	assert(psl);
	int pos;
	if ((pos = SeqListFind(psl, x)) != -1) {
		SeqListErase(psl, pos + 1);
	}
}
void SeqListModify(SeqList* psl, size_t pos, SLDataType x) {//�޸�
	assert(psl || pos - 1 <= psl->size);
	psl->array[pos - 1] = x;
}
void SeqListPrint(SeqList* psl) {//���
	assert(psl);
	for (int i = 0; i < (int)psl->size; ++i) {
		printf("%d\n", psl->array[i]);
	}
}
void SeqListBubbleSort(SeqList* psl) {//ð������
	assert(psl);
	SLDataType temp;
	for (int i = 0; i < (int)psl->size - 1; ++i) {
		for (int j = 0; j < (int)psl->size - i - 1; ++j) {
			if (psl->array[j] > psl->array[j + 1]) {
				temp = psl->array[j];
				psl->array[j] = psl->array[j + 1];
				psl->array[j + 1] = temp;
			}
		}
	}
}
int SeqListBinaryFind(SeqList* psl, SLDataType x) {//���ֲ���
	assert(psl);
	//SeqListBubbleSort(psl);
	int left = 0;
	int right = psl->size - 1;
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (psl->array[mid] > x) {
			right = mid - 1;
		}
		else if (psl->array[mid] < x) {
			left = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}
// ����Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1)
void SeqListRemoveAll(SeqList* psl, SLDataType x) {//����
	
}