#include"stack.h"

int main() {
	Stack s;
	Stack* p = &s;
	StackInit(p);
	for (int i = 0; i < 20; ++i) {
		StackPush(p, i);
	}
	StackPrint(p);
	StackPush(p, 100);
	StackPrint(p);
	StackPop(p);
	StackPrint(p);
	system("pause");
	return 0;
}