#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 32
unsigned int reverse_bit_1(unsigned int value) {
	int num = 0;
	for (int i = 1; i <= N; ++i) {
		num = num + (value % 2) * (int)pow(2, N - i);
		value /= 2;
	}
	return num;
}

unsigned int reverse_bit_2(unsigned int value) {
	int num1 = 0;
	for (int j = 0; j < N; ++j) {
		num1 = (num1 << 1) |((value >> j) & 1);
	}
	return num1;
}
void Print_2(unsigned int num, int n) {
	if (n != 1) {
		Print_2(num / 2,--n);
	}
	printf("%d", num % 2);
}
void main() {
	unsigned int num;
	printf("请输入一个无符号整数\n");
	scanf("%u", &num);
	Print_2(num, N);
	printf("\n");
	printf("方法一反转后为:%u\n", reverse_bit_1(num));
	Print_2(reverse_bit_1(num), N);
	printf("\n");
	printf("方法二反转后:%u\n", reverse_bit_2(num));
	Print_2(reverse_bit_2(num), N);
	printf("\n");
	system("pause");
}