#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int Fibonacci_1(int n) {//�ݹ�
	if (n == 1) {
		return 0;
	}
	if (n == 2) {
		return 1;
	}
	return Fibonacci_1(n - 1) + Fibonacci_1(n - 2);
}
int Fibonacci_2(int n) {//�ǵݹ�
	int a = 0;
	int b = 1;
	int sum;
	if (n == 1) {
		return a;
	}
	if (n == 2) {
		return b;
	}
	for (int i = 0; i < n - 2; ++i) {
		sum = a + b;
		a = b;
		b = sum;
	}
	return sum;
}
void main() {
	int n;
	printf("������n��ֵ\n");
	scanf("%d", &n);
	printf("�ݹ����Ϊ��%d\n", Fibonacci_1(n));
	printf("�ǵݹ����Ϊ��%d\n", Fibonacci_2(n));
	system("pause");
}