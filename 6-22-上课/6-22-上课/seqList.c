#include"seqList.h"
void SeqListInit(SeqList* psl, size_t capicity) {//初始化
	assert(psl);//需要但不合适
	psl->capicity = capicity;
	psl->array = (SLDataType*)calloc(capicity, sizeof(SLDataType));
	psl->size = 0;
}
void SeqListDestory(SeqList* psl) {
	assert(psl);//需要但不合适
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
void SeqListPushBack(SeqList* psl, SLDataType x) {//尾插
	assert(psl);
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}
void SeqListPopBack(SeqList* psl) {//尾删
	assert(psl || psl->size);
	psl->size--;
}
void SeqListPushFront(SeqList* psl, SLDataType x) {//头插
	assert(psl);
	for (int i = psl->size - 1; i >= 0; --i) {
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[0] = x;
	psl->size++;
}
void SeqListPopFront(SeqList* psl) {//头删
	assert(psl);
	for (int i = 0; i < (int)psl->size - 1; ++i) {
		psl->array[i] = psl->array[i + 1];
	}
}
int SeqListFind(SeqList* psl, SLDataType x) {//查找
	assert(psl);
	
	for(int i = 0; i < (int)psl->size; ++i) {
		if (x == psl->array[i]) {
			return i;
		}
	}
	return -1;
}
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x) {//位置插入
	assert(psl || (pos <= psl->size));
	for (int i = psl->size - 1; i > (int)pos; --i) {
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[pos] = x;
	psl->size++;
}
void SeqListErase(SeqList* psl, size_t pos) {//删除
	assert(psl || (pos - 1 < psl->size));
	for (int i = pos - 1; i < (int)psl->size - 1; ++i) {
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}
void SeqListRemove(SeqList* psl, SLDataType x) {//查删
	assert(psl);
	int pos;
	if ((pos = SeqListFind(psl, x)) != -1) {
		SeqListErase(psl, pos + 1);
	}
}
void SeqListModify(SeqList* psl, size_t pos, SLDataType x) {//修改
	assert(psl || pos - 1 <= psl->size);
	psl->array[pos - 1] = x;
}
void SeqListPrint(SeqList* psl) {//输出
	assert(psl);
	for (int i = 0; i < (int)psl->size; ++i) {
		printf("%d\n", psl->array[i]);
	}
}
void SeqListBubbleSort(SeqList* psl) {//冒泡排序
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
int SeqListBinaryFind(SeqList* psl, SLDataType x) {//二分查找
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
// 本题要求：时间复杂度：O(N) 空间复杂度 O(1)
void SeqListRemoveAll(SeqList* psl, SLDataType x) {//查重
	
}