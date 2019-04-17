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
	printf("��������Ҫ�жϵ�10����������\n");
	scanf("%d", &num);
	printf("�����������жϸ���ת��Ϊ���ֽ����жϣ�������(ֻ��������2,8,10,16)\n");
	while (1) {
		scanf("%d", &n);
		if (n == 2 || n == 8 || n == 10 || n == 16) {
			break;
		}
		printf("��������Ƿ�������������\n");
	}
	if (n == 2) {
		printf("%d��%d��������", num, n);
		Print_2(num);
		if (palindromic_num(n, num) == 1) {
			printf("\n�ǻ�����\n");
		}
		else {
			printf("\n���ǻ�����\n");
		}
	}
	if (n == 8) {
		printf("%d��%d��������%o\n",num, n, num);
		if (palindromic_num(n, num) == 1) {
			printf("�ǻ�����\n");
		}
		else {
			printf("���ǻ�����\n");
		}
	}
	if (n == 10) {
		printf("%d��%d����\n", num, n);
		if (palindromic_num(n, num) == 1) {
			printf("�ǻ�����\n");
		}
		else {
			printf("���ǻ�����\n");
		}
	}
	if (n == 16) {
		printf("%d��%d��������%X\n", num, n, num);
		if (palindromic_num(n, num) == 1) {
			printf("�ǻ�����\n");
		}
		else {
			printf("���ǻ�����\n");
		}
	}
	system("pause");
}