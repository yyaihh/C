#include"BTree.h"

int main() {
	BTNode* root = BinaryTreeCreate("ABD#GI##J###CE#HK###F##");
	printf("递归前序遍历:");
	BinaryTreePrevOrder(root);
	printf("\n递归中序遍历:");
	BinaryTreeInOrder(root);
	printf("\n递归后序遍历:");
	BinaryTreePostOrder(root);


	printf("\n\n非递归遍历:");
	printf("\n层序遍历:");
	BinaryTreeLevelOrder(root);

	printf("\n前序遍历(栈实现):");
	BinaryTreePrevOrderNonR(root);

	printf("\n中序遍历(栈实现):");
	BinaryTreeInOrderNonR(root);


	printf("\n后序遍历(栈实现):");
	BinaryTreePostOrderNonR(root);
	putchar('\n');

	if (BinaryTreeComplete(root)) {
		printf("\n是完全二叉树\n");
	}
	else {
		printf("\n不是完全二叉树\n");
	}


	BTNode* root1 = BinaryTreeCreate("ABD##E##CF##G##");
	printf("\n层序遍历:");
	BinaryTreeLevelOrder(root);
	if (BinaryTreeComplete(root1)) {
		printf("\n是完全二叉树\n");
	}
	else {
		printf("\n不是完全二叉树\n");
	}
	int n = 4;
	printf("节点个数:%d\n", BinaryTreeSize(root));
	printf("叶子个数:%d\n", BinaryTreeLeafSize(root));
	printf("%d层节点个数:%d\n", n, BinaryTreeLevelKSize(root, n));
	BTNode* t = BinaryTreeFind(root, 'F');
	if (t) {
		printf("树中有%c\n", t->_data);
	}
	else {
		printf("没有这个数据\n");
	}
	system("pause");
	return 0;
}