#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef char BTDataType;
typedef struct BinaryTreeNode{
	BTDataType _data;
	struct BinaryTreeNode* lchild;
	struct BinaryTreeNode* rchild;
}BTNode;
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate_(BTDataType* a, int* s_n);
BTNode* BinaryTreeCreate(BTDataType* a);
void BinaryTreeDestory(BTNode* root);
int BinaryTreeSize(BTNode* root);//节点个数
int BinaryTreeLeafSize(BTNode* root);//叶子个数
int BinaryTreeLevelKSize(BTNode* root, int k);//k层的节点数
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);//查找

// 遍历
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);

// 非递归遍历
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);//层序遍历,用队列

// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);
void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);
void TestBinaryTree();