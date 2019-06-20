#include <stdio.h>
#include<stdlib.h>
#define Offsetof(s,m) ((size_t)&(((s*)0)->m))
typedef struct {
	double a;
	char str[10];
	int b;
	char c;
}S;
int main() {
	int a = 0;//地址为0
	S* A = (S*)a;//结构体指针
	printf("%d\n",(size_t)&(A->b));//结构体从地址0开始, &(A->b)为b的地址
	printf("%d\n", (size_t)&(A->c));
	printf("%d\n", offsetof(S, b));
	printf("%d\n", Offsetof(S, b));
	printf("%d\n", offsetof(S, c));
	printf("%d\n", Offsetof(S, c));
	system("pause");
	return 0;
}