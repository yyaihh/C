#if 0
#include<stdio.h>
#include<stdlib.h>
int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int mul(int a, int b) {
	return a * b;
}
int Div(int a, int b) {//不考虑b=0的情况
	return a / b;
}
int main() {
	int a = 4;
	int b = 2;
	printf("%d+%d=%d\n", a, b, add(a, b));
	printf("%d-%d=%d\n", a, b, sub(a, b));
	printf("%d*%d=%d\n", a, b, mul(a, b));
	printf("%d/%d=%d\n", a, b, Div(a, b));
	system("pause");
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int mul(int a, int b) {
	return a * b;
}
int Div(int a, int b) {//不考虑b=0的情况
	return a / b;
}
int main() {
	int a = 4;
	int b = 2;
	int(*p[4])(int a, int b) = { add,sub,mul,Div };
	for (int i = 0; i < 4; ++i) {
		printf("%d\n", p[i](a, b));
	}
	system("pause");
	return 0;
}
#endif
#if 1
#include<stdio.h>
#include<stdlib.h>
int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int mul(int a, int b) {
	return a * b;
}
int Div(int a, int b) {//不考虑b=0的情况
	return a / b;
}
int main() {
	int a = 4;
	int b = 2;
	int(*p[4])(int a, int b) = { add,sub,mul,Div };
	int(*(*pp)[4])(int a, int b);
	pp = &p;
	//int(*(*pp)[4])(int a, int b) = &p;
	for (int i = 0; i < 4; ++i) {
		printf("%d\n", p[i](a, b));
	}
	printf("通过指向函数指针数组的指针调用\n");
	for (int i = 0; i < 4; ++i) {
		printf("%d\n", (*(*pp + i))(a, b));
		//等价printf("%d\n", (*(*pp)[i])(a, b));
	}
	system("pause");
	return 0;
}
#endif
