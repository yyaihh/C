#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//�ݹ�ʵ��
int Hanoi(int x) {//�ݹ鹫ʽΪH(n) = 2*H(n-1��+1 (n>1��
	if (x == 1) {
		return 1;
	}
	return 2 * Hanoi(x - 1) + 1;
}
//��һֻ������n��̨�ף�һ�ο�����1�ף�Ҳ������2�ף����м���������������n��̨��
int frog1(int x) {//f(n)=f(n-1)+f(n-2)
	if (x == 1) {
		return 1;
	}
	if (x == 2) {
		return 2;
	}
	return frog1(x - 1) + frog1(x - 2);
}
//��һֻ������n��̨�ף�һ�ο�����1�ף�Ҳ������n�ף����м���������������n��̨��
int frog2(int x) {//������1,2,4,8,16,32=>f(n)=2*f(n-1)
	if (x == 1) {
		return 1;
	}
	return 2 * frog2(x - 1);
}
void main() {
	int n;
	int N;
	printf("������������(n��С�ڵ���31����������������)\n");
	scanf("%d", &n);
	printf("%d\n", Hanoi(n));
	printf("������̨����\n");
	printf("������̨����\n");
	scanf("%d", &N);
	printf("%d\n", frog1(N));
	printf("%d\n", frog2(N));
	system("pause");
}