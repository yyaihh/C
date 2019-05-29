#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* New(int n){
	char* str;
	str = (char*)malloc(n * sizeof(char));
	return str;
}
void main() {
	int n;
	char* s;
	printf("«Î ‰»Înµƒ÷µ\n");
	scanf("%d", &n);
	s = New(n);
	scanf("%s", s);
	printf("%p\n", s);
	printf("%s\n", s);
	Free(s);
	printf("%p\n", s);
	system("pause");
}
