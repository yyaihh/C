#include"BTree.h"
#include"stack.h"
#include"queue.h"
#include<math.h>
BTNode* BinaryTreeCreate_(BTDataType* src, int* s_n) {
	//先考虑少层的
	//求一个数组中第n大的数据
	//传参数怎么做
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
void BinaryTreeDestory(BTNode* root) {//前中后都可以, 这里写后序
	if (root) {
		BinaryTreeDestory(root->lchild);
		BinaryTreeDestory(root->rchild);
		free(root);
	}
}
int BinaryTreeSize(BTNode* root) {//树大小, 遍历计数
#if 1 //递归
	if (root) {
		return BinaryTreeSize(root->rchild)+ BinaryTreeSize(root->lchild) + 1;
	}
	else {
		return 0;
	}
#else //非递归
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
int BinaryTreeLeafSize(BTNode* root) {//叶子个数
#if 1 //递归
	if (root) {
		return BinaryTreeLeafSize(root->rchild) + BinaryTreeLeafSize(root->lchild) 
				+(!root->lchild && !root->rchild);
	}
	else {
		return 0;
	}
#else //非递归
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
int BinaryTreeLevelKSize(BTNode* root, int k) {//K层结点
//1.层序遍历	2.递归(层号是几就在哪一层, 出现几次就有几个)
#if 0 //递归
	static int tag = 0;//层数
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

#else //非递归
	if (k <= 0) {
		printf("k不能小于0!\n");
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
BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {//查找
//遍历
#if 1//递归
	BTNode* cur = root;
	if (root) {
		if (root->_data == x) {
			return root;
		}

		putchar(cur->_data);
		BinaryTreeFind(root->lchild, x);
		BinaryTreeFind(root->rchild, x);
	}
#else //非递归

#endif
}
// 遍历
void BinaryTreePrevOrder(BTNode* root) {//前序遍历
	if (root) {
		putchar(root->_data);
		BinaryTreePrevOrder(root->lchild);
		BinaryTreePrevOrder(root->rchild);
	}
}
void BinaryTreeInOrder(BTNode* root) {//中序
	if (root) {
		BinaryTreeInOrder(root->lchild);
		putchar(root->_data);
		BinaryTreeInOrder(root->rchild);
	}
}
void BinaryTreePostOrder(BTNode* root) {//后序
	if (root) {
		BinaryTreePostOrder(root->lchild);
		BinaryTreePostOrder(root->rchild);
		putchar(root->_data);
	}
}
/////// 非递归遍历

// 层序遍历,也是一种非递归遍历,队列
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

//前序遍历用栈(DS)来实现, 根和左孩子不入栈, 只有右孩子入栈
void BinaryTreePrevOrderNonR(BTNode* root) {
	Stack st;
	BTNode* cur = root;
	StackInit(&st, 20);
	while (cur) {//左孩子为空和栈为空时cur为空
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

//中序
void BinaryTreeInOrderNonR(BTNode* root) {

	Stack st;
	BTNode* cur = root;
	StackInit(&st, 20);
	while (1) {
		
		for (; cur; cur = cur->lchild) {
			StackPush(&st, cur);
		}

		cur = StackTop(&st);
		if (cur == NULL) {//取栈顶时发现已空
			break;
		}
		putchar(cur->_data);
		StackPop(&st);
		cur = cur->rchild;
	}
	StackDestory(&st);
}

//后序

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
		while (!StackEmpty(&st) && tag[st._top - 1] == 1) {//栈不为空并且栈顶元素标记为1
			cur = StackTop(&st);
			putchar(cur->_data);
			StackPop(&st);
		}
		if (!StackEmpty(&st)) {
			cur = StackTop(&st);
			tag[st._top - 1] = 1;//当没有左孩子时,给这个元素标记为1
			cur = cur->rchild;
		}
	} while (!StackEmpty(&st));
	StackDestory(&st);
}

// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root) {

	Queue qu;
	QueueInit(&qu);
	QueuePush(&qu, root);
	BTNode* cur;
	int tag = 0;
	while (!QueueEmpty(&qu)) {
		cur = QueueTop(&qu);
		if (cur->rchild && !cur->lchild) {//有左没右
			return 0;
		}
		if (tag && (cur->rchild || cur->lchild)) { //没右孩子,本应结束,但当后面再有时就不是完全二叉树
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




