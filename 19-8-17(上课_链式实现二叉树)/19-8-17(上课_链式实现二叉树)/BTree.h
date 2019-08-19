#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef char BTDataType;
typedef struct BinaryTreeNode{
	BTDataType _data;
	struct BinaryTreeNode* lchild;
	struct BinaryTreeNode* rchild;
}BTNode;
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate_(BTDataType* a, int* s_n);
BTNode* BinaryTreeCreate(BTDataType* a);
void BinaryTreeDestory(BTNode* root);
int BinaryTreeSize(BTNode* root);//�ڵ����
int BinaryTreeLeafSize(BTNode* root);//Ҷ�Ӹ���
int BinaryTreeLevelKSize(BTNode* root, int k);//k��Ľڵ���
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);//����

// ����
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);

// �ǵݹ����
// �������
void BinaryTreeLevelOrder(BTNode* root);//�������,�ö���

// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);
void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);
void TestBinaryTree();