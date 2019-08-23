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
#if 1//递归
	if (root == NULL || k <= 0)
		return 0;
	if (root != NULL && k == 1)
		return 1;

	return (BinaryTreeLevelKSize(root->lchild, k - 1) + BinaryTreeLevelKSize(root->rchild, k - 1));

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
	if (root == NULL){
		//非法输入
		return;
	}
	//如果找到了直接返回
	if (root->_data == x){
		return root;
	}

	else{
		return BinaryTreeFind(&root->lchild, x);
		return BinaryTreeFind(&root->rchild, x);
	}
#else //非递归
	Stack st;
	BTNode* cur = root;
	StackInit(&st, 20);
	while (cur) {//左孩子为空和栈为空时cur为空,跳出
		if (cur->_data == x) {
			return cur;
		}
		if (cur->rchild) { //有右,右入栈
			StackPush(&st, cur->rchild);
		}
		if (cur->lchild) {//有左,访问
			cur = cur->lchild;
		}
		else {//没左,取栈顶
			cur = StackTop(&st);
			StackPop(&st);
		}
	}
	StackDestory(&st);
	return NULL;
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
	while (cur) {//左孩子为空和栈为空时cur为空,跳出
		putchar(cur->_data);
		if (cur->rchild) { //有右,右入栈
			StackPush(&st, cur->rchild);
		}
		if (cur->lchild) {//有左,访问
			cur = cur->lchild;
		}
		else {//没左,取栈顶
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
	while (cur || !StackEmpty(&st)) {
		
		for (; cur; cur = cur->lchild) {
			StackPush(&st, cur);
		}

		cur = StackTop(&st);
		//1.如果右孩子为空,for循环不进,直接取栈顶
		//2.如果右孩子不为空,那么这是一个没有左孩子的
		//第一种是左子树访问完毕, 2,是左子树为空
		putchar(cur->_data);
		StackPop(&st);
		cur = cur->rchild;//当右子树为空时,检查栈是否为空,都为空时跳出
	}
	StackDestory(&st);
}

//后序

void BinaryTreePostOrderNonR(BTNode* root) {

	Stack st;
	BTNode* cur = root;
	StackInit(&st, 20);
	char tag[64]; //左子树访问标记, 左子树访问完记为1,反之0
	do {
		for (; cur; cur = cur->lchild) {//将当前结点和左孩子入栈
			StackPush(&st, cur);
			tag[st._top - 1] = 0;
		}
		while (!StackEmpty(&st) && tag[st._top - 1] == 1) {//栈不为空并且栈顶元素标记为1,
			//前面的条件只在最后一次循环跳出的时候生效
			//
			//1..当cur为空时, 上面for不进, 此条件生效
			//2, ''''''不为'','''''''''进,'''''''不生效
			//情况1执行完之后再检查父亲节点是不是也要被打印
			cur = StackTop(&st);
			putchar(cur->_data);
			StackPop(&st);
		}
		if (!StackEmpty(&st)) {
			cur = StackTop(&st);
			//1,如果上面的while进了, 则证明左子树访问完毕
			//2,...............没进,.....没有左.........
			//所以都要给标记置为1
			tag[st._top - 1] = 1;//当没有左孩子时,给这个元素标记为1
			cur = cur->rchild;
		}
	} while (!StackEmpty(&st));//后序遍历中根节点最早入栈, 最后出栈, 如栈空,则已经遍历完毕,跳出
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




