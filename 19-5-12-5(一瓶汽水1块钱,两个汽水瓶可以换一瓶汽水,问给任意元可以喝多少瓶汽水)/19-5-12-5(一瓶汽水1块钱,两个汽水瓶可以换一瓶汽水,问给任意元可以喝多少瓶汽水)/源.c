#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
double fun(int n) {//nΪƿ����
	if (n <= 0) { 
		return 0;
	}
	return fun(n / 2) + n + (n % 2)/2.0;
} 
void main() {
	int n;
	printf("���ж���Ǯ?,������\n");
	scanf("%d", &n);
	printf("��ЩǮ����Ժ�%dƿ����ˮ\n", (int)fun(n));
	system("pause");
}