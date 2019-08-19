#include"stack.h"

void StackInit(Stack* ps, int capacity) {
	assert(ps);

	ps->data = (STDataType*)calloc(capacity, sizeof(STDataType));
	ps->_capacity = capacity;
	ps->_top = 0;
}
void StackDestory(Stack* ps) {
	assert(ps);
	if (ps->data) {
		ps->_top = 0;
		ps->_capacity = 0;
		free(ps->data);
	}
}
void StackPush(Stack* ps, STDataType x) {
	assert(ps);
	if (ps->_top >= ps->_capacity) {
		ps->_capacity *= 2;
		ps->data = (STDataType*)realloc(ps->data, ps->_capacity * sizeof(STDataType));
	}
	ps->data[ps->_top] = x;
	++ps->_top;
}
void StackPop(Stack* ps) {
	assert(ps || ps->_top);
	--ps->_top;
}
STDataType StackTop(Stack* ps) {
	assert(ps);
	if (StackEmpty(ps)) { 
		return (STDataType)0;
	}
	return ps->data[ps->_top - 1];
}
int StackEmpty(Stack* ps) {
	assert(ps);
	return ps->_top == 0;
}