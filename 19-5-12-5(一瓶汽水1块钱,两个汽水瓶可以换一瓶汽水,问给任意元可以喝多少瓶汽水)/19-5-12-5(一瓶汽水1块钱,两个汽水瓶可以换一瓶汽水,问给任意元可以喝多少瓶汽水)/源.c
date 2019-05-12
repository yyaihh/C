#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
double fun(int n) {//n为瓶子数
	if (n <= 0) { 
		return 0;
	}
	return fun(n / 2) + n + (n % 2)/2.0;
} 
void main() {
	int n;
	printf("你有多少钱?,请输入\n");
	scanf("%d", &n);
	printf("这些钱你可以喝%d瓶快乐水\n", (int)fun(n));
	system("pause");
}