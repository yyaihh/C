#include"seqlist.h"
void SeqListInit(SeqList* psl, size_t capacity) {//��ʼ��
	psl->array = (SLDataType*)calloc(capacity, sizeof(SeqList));
	psl->size = 0;
	psl->capacity = capacity;
}
void SeqListDestory(SeqList* psl) {//���ٿռ�
	assert(psl);
	if (psl->array) {
		free(psl->array);
		psl->size = 0;
		psl->capacity = 0;
	}
}
void CheckCapacity(SeqList* psl) {//�������
	assert(psl);
	if (psl->size == psl->capacity) {
		psl->capacity *= 2;
		psl->array = (SLDataType*)realloc(psl->array, psl->capacity * sizeof(SLDataType));
	}
}
void SeqListPushBack(SeqList* psl, SLDataType x) {//β��
	CheckCapacity(psl);
	psl->array[psl->size++] = x;
}
void SeqListPopBack(SeqList* psl) {//βɾ
	assert(psl || psl->size);
	--psl->size;
}
void SeqListPushFront(SeqList* psl, SLDataType x) {//ͷ��
	assert(psl);
	CheckCapacity(psl);
	for (int i = psl->size; i > 0; --i) {
		psl->array[i] = psl->array[i - 1];
	}
	++psl->size;
	psl->array[0] = x;
}
void SeqListPopFront(SeqList* psl) {//ͷɾ
	assert(psl || psl->size);
	for (int i = 1; i < (int)psl->size; ++i) {
		psl->array[i - 1] = psl->array[i];
	}
	--psl->size;
}
int SeqListFind(SeqList* psl, SLDataType x) {//����
	for (int i = 0; i < (int)psl->size; ++i) {
		if (psl->array[i] == x) {
			return i;
		}
	}
	return -1;
}
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x) {//�ڵ�pos��λ�ò���
	assert(psl || pos <= psl->size);
	for (int i = psl->size; i > (int)pos; --i) {
		psl->array[i] = psl->array[i - 1];
	}
	psl->array[pos] = x;
	++psl->size;
}
void SeqListErase(SeqList* psl, size_t pos) {//ɾ����pos��
	assert(psl);
	for (int i = pos - 1; i < (int)psl->size - 1; ++i) {
		psl->array[i] = psl->array[i + 1];
	}
	--psl->size;
}
void SeqListRemove(SeqList* psl, SLDataType x) {//ɾ������x
	assert(psl);
	int i;
	while ((i = SeqListFind(psl, x)) != -1) {
		SeqListErase(psl, i + 1);
	}
}
void SeqListModify(SeqList* psl, size_t pos, SLDataType x) {//�޸�
	assert(psl || pos <= psl->size);
	psl->array[pos - 1] = x;
}
void SeqListPrint(SeqList* psl) {//���
	for (int i = 0; i < (int)psl->size; ++i) {
		printf("%d  ", psl->array[i]);
	}
	putchar('\n');
}
void SeqListBubbleSort(SeqList* psl) {//ð������
	SLDataType tmp;
	for (int i = 0; i < (int)psl->size; ++i) {
		for (int j = 0; j < (int)psl->size - 1; ++j) {
			if (psl->array[j] > psl->array[j + 1]) {
				tmp = psl->array[j];
				psl->array[j] = psl->array[j + 1];
				psl->array[j + 1] = tmp;
			}
		}
	}
}
int SeqListBinaryFind(SeqList* psl, SLDataType x) {//���ֲ���
	int left = 0;
	int right = psl->size - 1;
	int mid = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		if (psl->array[mid] < x) {
			left = mid + 1;
		}
		else if (psl->array[mid] > x) {
			right = mid - 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}
void SeqListRemoveAll(SeqList* psl, SLDataType x) {//��������Ļ�����,��xȥ��
	for (int i = 0; i < (int)psl->size; ) {
		if (psl->array[i] == x) {
			SeqListErase(psl, i + 1);
			continue;
		}
		else if (psl->array[i] > x) {
			return;
		}
		++i;
	}
}