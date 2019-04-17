#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//递归实现
int Hanoi(int x) {//递归公式为H(n) = 2*H(n-1）+1 (n>1）
	if (x == 1) {
		return 1;
	}
	return 2 * Hanoi(x - 1) + 1;
}
//有一只青蛙跳n阶台阶，一次可以跳1阶，也可以跳2阶，问有几种跳法可以跳上n阶台阶
int frog1(int x) {//f(n)=f(n-1)+f(n-2)
	if (x == 1) {
		return 1;
	}
	if (x == 2) {
		return 2;
	}
	return frog1(x - 1) + frog1(x - 2);
}
//有一只青蛙跳n阶台阶，一次可以跳1阶，也可以跳n阶，问有几种跳法可以跳上n阶台阶
int frog2(int x) {//规律是1,2,4,8,16,32=>f(n)=2*f(n-1)
	if (x == 1) {
		return 1;
	}
	return 2 * frog2(x - 1);
}
void main() {
	int n;
	int N;
	printf("请输入盘子数(n需小于等于31，否则结果会过大溢出)\n");
	scanf("%d", &n);
	printf("%d\n", Hanoi(n));
	printf("请输入台阶数\n");
	printf("请输入台阶数\n");
	scanf("%d", &N);
	printf("%d\n", frog1(N));
	printf("%d\n", frog2(N));
	system("pause");
}