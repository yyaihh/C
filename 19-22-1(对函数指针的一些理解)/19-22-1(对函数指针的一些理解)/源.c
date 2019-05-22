#if 0
#include<stdio.h>
#include<stdlib.h>
void test() {
	printf("test被调用\n");
}
int test1(int n) {
	printf("test1被调用\n");
	return n;
}
int main() {
	void(*p)() = test;
	int(*P)() = test1;
	int(*q)() = &test1;
	printf("p=%p\n", p);
	printf("test=%p\n", test);
	printf("&test=%p\n", &test);
	printf("*test=%p\n", *test);
	p();
	test();
	printf("test1=%p\n", test1);
	printf("P=%p\n", P);
	printf("test1返回值%d\n", P(1));
	printf("test1返回值%d\n", test1(2));
	P(3);
	test1(4);
	system("pause");
	return 0;
}
#endif
#if 1
#include<stdio.h>
#include<stdlib.h>
int* fun(int a[]) {
	return &a[0];
}
int main() {
	int a[] = { 1,2,3 };
	printf("fun=%p\n", fun);
	printf("&a[0]=%p\n", &a[0]);
	printf("fun(a)=%p\n", fun(a));
	int* p = fun(a);
	printf("a[0]=%d\n", a[0]);
	printf("*fun(a)=%d\n", *fun(a));
	printf("*p=%d\n", *p);
	system("pause");
	return 0;
}
#endif