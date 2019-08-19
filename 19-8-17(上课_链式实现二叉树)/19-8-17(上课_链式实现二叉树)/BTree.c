#include"BTree.h"
#include"stack.h"
#include"queue.h"
#include<math.h>
BTNode* BinaryTreeCreate_(BTDataType* src, int* s_n) {
	//�ȿ����ٲ��
	//��һ�������е�n�������
	//��������ô��
	if (src[*s_n] == '#') {
		++*s_n;
		return NULL;
	}

	BTNode* cur = (BTNode*)calloc(1, sizeof(BTNode));
	cur->_data = src[*s_n];
	++*s_n;

	cur->lchild = BinaryTreeCreate_(src, s_n);
	cur->rchild = BinaryTreeCreate_(src, s_n);

	return cur;
}
BTNode* BinaryTreeCreate(BTDataType* src) {
	int s_n = 0;
	return BinaryTreeCreate_(src, &s_n);
}
void BinaryTreeDestory(BTNode* root) {//ǰ�к󶼿���, ����д����
	if (root) {
		BinaryTreeDestory(root->lchild);
		BinaryTreeDestory(root->rchild);
		free(root);
	}
}
int BinaryTreeSize(BTNode* root) {//����С, ��������
#if 1 //�ݹ�
	if (root) {
		return BinaryTreeSize(root->rchild)+ BinaryTreeSize(root->lchild) + 1;
	}
	else {
		return 0;
	}
#else //�ǵݹ�
	Queue qu;
	QueueInit(&qu);
	QueuePush(&qu, root);
	int count = 0;
	BTNode* cur;
	while (!QueueEmpty(&qu)) {
		cur = QueueTop(&qu);
		++count;
		if (cur->lchild) {
			QueuePush(&qu, cur->lchild);
		}
		if (cur->rchild) {
			QueuePush(&qu, cur->rchild);
		}
		QueuePop(&qu);
	}
	QueueDestory(&qu);
	return count;
#endif
}
int BinaryTreeLeafSize(BTNode* root) {//Ҷ�Ӹ���
#if 1 //�ݹ�
	if (root) {
		return BinaryTreeLeafSize(root->rchild) + BinaryTreeLeafSize(root->lchild) 
				+(!root->lchild && !root->rchild);
	}
	else {
		return 0;
	}
#else //�ǵݹ�
	Queue qu;
	QueueInit(&qu);
	QueuePush(&qu, root);
	int count = 0;
	BTNode* cur;
	while (!QueueEmpty(&qu)) {
		cur = QueueTop(&qu);
		if (!cur->lchild && !cur->rchild) {
			++count;
		}
		if (cur->lchild) {
			QueuePush(&qu, cur->lchild);
		}
		if (cur->rchild) {
			QueuePush(&qu, cur->rchild);
		}
		QueuePop(&qu);
	}
	QueueDestory(&qu);
	return count;
#endif
}
int BinaryTreeLevelKSize(BTNode* root, int k) {//K����
//1.�������	2.�ݹ�(����Ǽ�������һ��, ���ּ��ξ��м���)
#if 0 //�ݹ�
	static int tag = 0;//����
	if ((k == 1) && root) {
		return 1;
	}
	if (root) {
		tag++;
		return (tag == k) + BinaryTreeLevelKSize(root->lchild, k) + BinaryTreeLevelKSize(root->rchild, k);
	}
	else {
		return 0;
	}

#else //�ǵݹ�
	if (k <= 0) {
		printf("k����С��0!\n");
		return 0;
	}
	Queue qu;
	QueueInit(&qu);
	QueuePush(&qu, root);
	int count = 0;
	BTNode* cur;
	BTNode tmp;
	BTNode* pt = &tmp;
	pt->_data = '#';
	pt->lchild = NULL;
	pt->rchild = NULL;
	int left = 1;
	int right = (int)pow(2, k - 1);
	while (--k) {
		left = left + (int)pow(2, k);
	}
	right = left - right;
	int size = left;
	int n = 0;
	while (size--) { 
		++n;
		cur = QueueTop(&qu);
		if (n > right && n <= left && cur->_data != '#') { 
			++count;
		}
		if (cur->lchild) {
			QueuePush(&qu, cur->lchild);
		}
		else { 
			QueuePush(&qu, pt);
		}
		if (cur->rchild) {
			QueuePush(&qu, cur->rchild);
		}
		else  { 
			QueuePush(&qu, pt);
		}
		QueuePop(&qu);
	}
	QueueDestory(&qu);
	return count;
#endif
}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {//����
//����
#if 1//�ݹ�
	BTNode* cur = root;
	if (root) {
		if (root->_data == x) {
			return root;
		}

		putchar(cur->_data);
		BinaryTreeFind(root->lchild, x);
		BinaryTreeFind(root->rchild, x);
	}
#else //�ǵݹ�

#endif
}
// ����
void BinaryTreePrevOrder(BTNode* root) {//ǰ�����
	if (root) {
		putchar(root->_data);
		BinaryTreePrevOrder(root->lchild);
		BinaryTreePrevOrder(root->rchild);
	}
}
void BinaryTreeInOrder(BTNode* root) {//����
	if (root) {
		BinaryTreeInOrder(root->lchild);
		putchar(root->_data);
		BinaryTreeInOrder(root->rchild);
	}
}
void BinaryTreePostOrder(BTNode* root) {//����
	if (root) {
		BinaryTreePostOrder(root->lchild);
		BinaryTreePostOrder(root->rchild);
		putchar(root->_data);
	}
}
/////// �ǵݹ����

// �������,Ҳ��һ�ַǵݹ����,����
void BinaryTreeLevelOrder(BTNode* root) {
	Queue qu;
	QueueInit(&qu);
	QueuePush(&qu, root);
	BTNode* cur;
	while (!QueueEmpty(&qu)) {
		cur = QueueTop(&qu);

		putchar(cur->_data);

		if (cur->lchild) {
			QueuePush(&qu, cur->lchild);
		}
		if (cur->rchild) {
			QueuePush(&qu, cur->rchild);
		}
		QueuePop(&qu);
	}
	QueueDestory(&qu);
}

//ǰ�������ջ(DS)��ʵ��, �������Ӳ���ջ, ֻ���Һ�����ջ
void BinaryTreePrevOrderNonR(BTNode* root) {
	Stack st;
	BTNode* cur = root;
	StackInit(&st, 20);
	while (cur) {//����Ϊ�պ�ջΪ��ʱcurΪ��
		putchar(cur->_data);
		if (cur->rchild) { 
			StackPush(&st, cur->rchild);
		}
		if (cur->lchild) {
			cur = cur->lchild;
		}
		else {
			cur = StackTop(&st);
			StackPop(&st);
		}
	}
	StackDestory(&st);
}

//����
void BinaryTreeInOrderNonR(BTNode* root) {

	Stack st;
	BTNode* cur = root;
	StackInit(&st, 20);
	while (1) {
		
		for (; cur; cur = cur->lchild) {
			StackPush(&st, cur);
		}

		cur = StackTop(&st);
		if (cur == NULL) {//ȡջ��ʱ�����ѿ�
			break;
		}
		putchar(cur->_data);
		StackPop(&st);
		cur = cur->rchild;
	}
	StackDestory(&st);
}

//����

void BinaryTreePostOrderNonR(BTNode* root) {

	Stack st;
	BTNode* cur = root;
	StackInit(&st, 20);
	char tag[64];
	do {
		for (; cur; cur = cur->lchild) {
			StackPush(&st, cur);
			tag[st._top - 1] = 0;
		}
		while (!StackEmpty(&st) && tag[st._top - 1] == 1) {//ջ��Ϊ�ղ���ջ��Ԫ�ر��Ϊ1
			cur = StackTop(&st);
			putchar(cur->_data);
			StackPop(&st);
		}
		if (!StackEmpty(&st)) {
			cur = StackTop(&st);
			tag[st._top - 1] = 1;//��û������ʱ,�����Ԫ�ر��Ϊ1
			cur = cur->rchild;
		}
	} while (!StackEmpty(&st));
	StackDestory(&st);
}

// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root) {

	Queue qu;
	QueueInit(&qu);
	QueuePush(&qu, root);
	BTNode* cur;
	int tag = 0;
	while (!QueueEmpty(&qu)) {
		cur = QueueTop(&qu);
		if (cur->rchild && !cur->lchild) {//����û��
			return 0;
		}
		if (tag && (cur->rchild || cur->lchild)) { //û�Һ���,��Ӧ����,������������ʱ�Ͳ�����ȫ������
			return 0;
		}
		if (cur->lchild) {
			QueuePush(&qu, cur->lchild);
		}
		if (cur->rchild) {
			QueuePush(&qu, cur->rchild);
		}
		else{
			tag = 1;
		}
		QueuePop(&qu);
	}
	QueueDestory(&qu);
	return 1;
}




