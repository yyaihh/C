#pragma once
#include"BTree.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef BTNode* STDataType;
typedef struct Stack {
	STDataType* data;
	int _top; // Õ»¶¥
	int _capacity; // ÈÝÁ¿
}Stack;
void StackInit(Stack* ps, int capacity);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
