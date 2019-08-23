#include"BTree.h"

int main() {
	BTNode* root = BinaryTreeCreate("ABD#GI##J###CE#HK###F##");
	printf("�ݹ�ǰ�����:");
	BinaryTreePrevOrder(root);
	printf("\n�ݹ��������:");
	BinaryTreeInOrder(root);
	printf("\n�ݹ�������:");
	BinaryTreePostOrder(root);


	printf("\n\n�ǵݹ����:");
	printf("\n�������:");
	BinaryTreeLevelOrder(root);

	printf("\nǰ�����(ջʵ��):");
	BinaryTreePrevOrderNonR(root);

	printf("\n�������(ջʵ��):");
	BinaryTreeInOrderNonR(root);


	printf("\n�������(ջʵ��):");
	BinaryTreePostOrderNonR(root);
	putchar('\n');

	if (BinaryTreeComplete(root)) {
		printf("\n����ȫ������\n");
	}
	else {
		printf("\n������ȫ������\n");
	}


	BTNode* root1 = BinaryTreeCreate("ABD##E##CF##G##");
	printf("\n�������:");
	BinaryTreeLevelOrder(root);
	if (BinaryTreeComplete(root1)) {
		printf("\n����ȫ������\n");
	}
	else {
		printf("\n������ȫ������\n");
	}
	int n = 4;
	printf("�ڵ����:%d\n", BinaryTreeSize(root));
	printf("Ҷ�Ӹ���:%d\n", BinaryTreeLeafSize(root));
	printf("%d��ڵ����:%d\n", n, BinaryTreeLevelKSize(root, n));
	BTNode* t = BinaryTreeFind(root, 'F');
	if (t) {
		printf("������%c\n", t->_data);
	}
	else {
		printf("û���������\n");
	}
	system("pause");
	return 0;
}