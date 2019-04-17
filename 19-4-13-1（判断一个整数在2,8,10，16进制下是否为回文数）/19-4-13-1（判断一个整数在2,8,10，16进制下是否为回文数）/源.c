#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int palindromic_num(int n, int num) {
	int count = 0;
	int ret;
	ret = num;
	while (ret) {
		++count;
		ret /= n;
	}
	for (int i = 0, j = count; i < j; ++i, --j) {
		if ((num / (int)pow(n, i)) % n != (num / (int)pow(n, j - 1) )% n) {
			return 0;
		}
	}
	return 1;
}
void Print_2(int num) {
	if (num !=1) {
		Print_2(num / 2);
	}
	printf("%d", num % 2);
}
void main() {
	int num;
	int n;
	printf("请输入需要判断的10进制正整数\n");
	scanf("%d", &num);
	printf("请输入您需判断该数转化为哪种进制判断，请输入(只允许输入2,8,10,16)\n");
	while (1) {
		scanf("%d", &n);
		if (n == 2 || n == 8 || n == 10 || n == 16) {
			break;
		}
		printf("您的输入非法，请重新输入\n");
	}
	if (n == 2) {
		printf("%d在%d进制下是", num, n);
		Print_2(num);
		if (palindromic_num(n, num) == 1) {
			printf("\n是回文数\n");
		}
		else {
			printf("\n不是回文数\n");
		}
	}
	if (n == 8) {
		printf("%d在%d进制下是%o\n",num, n, num);
		if (palindromic_num(n, num) == 1) {
			printf("是回文数\n");
		}
		else {
			printf("不是回文数\n");
		}
	}
	if (n == 10) {
		printf("%d在%d进制\n", num, n);
		if (palindromic_num(n, num) == 1) {
			printf("是回文数\n");
		}
		else {
			printf("不是回文数\n");
		}
	}
	if (n == 16) {
		printf("%d在%d进制下是%X\n", num, n, num);
		if (palindromic_num(n, num) == 1) {
			printf("是回文数\n");
		}
		else {
			printf("不是回文数\n");
		}
	}
	system("pause");
}