#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void print(int x) {
	if (x > 9) {
		print(x / 10);
	}
	printf("%d  ", x % 10);
}

int Strlen(char* str) {
	if (str[0] == '\0') {
		return 0;
	}
	return Strlen(str + 1) + 1;//f(n)=f(n-1)+1
}
int factorial(int n) {//n*(n-1)! => n*(n-2)*(n-3)!бнбн
	if (n == 1) {
		return 1;
	}
	return n * factorial(n - 1);//
}
int rabbit(int n) {//f(n)=f(n-1)+f(n-2)
	if (n == 1 || n == 2) {
		return 1;
	}
	return rabbit(n - 1) + rabbit(n - 2);
}
void get_put() {
	char ch;
	ch = getchar();
	if (ch != '\n') {
		get_put(ch);
	}
	if (ch != '\n') {
		ch = putchar(ch);
	}
}
void main() {	
	int num = 189642;
	print(num);
	printf("\n");
	char str[] = "abcde";
	printf("%d\n", Strlen(str));
	printf("%d\n",factorial(4));
	printf("%d\n", rabbit(10));
	get_put();
	printf("\n");
	system("pause");
}