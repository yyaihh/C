#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int fun(int x) {
	int Sn = 0;
	int S;
	for (int i = 1; i <= x; ++i) {
		S = 1;
		for (int j = 1; j <= i; ++j) {
			S *= j;
		}
		Sn += S;
	}
	return Sn;
}
void main() {
	int n;
	printf("����Ҫ1�����ٵĽ׳�֮�ͣ������루��ֵ��С��26��\n");
	scanf("%d", &n);
	printf("����1������%d���׳�֮��Ϊ%d\n", n, fun(n));
	system("pause");
}