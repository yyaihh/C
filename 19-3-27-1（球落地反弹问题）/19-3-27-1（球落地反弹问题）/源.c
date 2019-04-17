#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main() {
	double H;
	int N;//落地次数
	double S;//共经过的米数
	double h;//反弹的高度
	printf("请输入初始高度\n");
	scanf("%lf", &H);
	printf("请输入落地次数\n");
	scanf("%d", &N);
	h = H / 2;
	S = H;
	for (int i = 1; i < N; ++i) {
		S += 2 * h;
		h /= 2;
	}
	printf("%lfm处第%d次落地共经过%lfm\n第%d次落地反弹高度为%lfm\n", H, N, S, N, h);
	system("pause");
}