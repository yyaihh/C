#include<stdio.h>
#include<stdlib.h>
struct {
	int a;
	char b[20];
	int c;
}s;
struct {
	char a;
	int b;
	char c;
}*p;
int main() {
	//p = &s;
	printf("%d\n", sizeof(s));
	system("pause");
	return 0;
}