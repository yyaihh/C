#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main() {
	int a, s, n, Sn = 0;
	printf("����Ҫǰ����ĺͣ�������n\n");
	scanf("%d", &n);
	printf("������a\n");
	scanf("%d", &a);
	s = a;
	Sn += s;
	for (int i = 1, m = 10; i < n; ++i, m *= 10) {
		s += a * m;
		Sn += s;
	}
	printf("Sn=%d\n", Sn);
	system("pause");
}