#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main() {
	double H;
	int N;//��ش���
	double S;//������������
	double h;//�����ĸ߶�
	printf("�������ʼ�߶�\n");
	scanf("%lf", &H);
	printf("��������ش���\n");
	scanf("%d", &N);
	h = H / 2;
	S = H;
	for (int i = 1; i < N; ++i) {
		S += 2 * h;
		h /= 2;
	}
	printf("%lfm����%d����ع�����%lfm\n��%d����ط����߶�Ϊ%lfm\n", H, N, S, N, h);
	system("pause");
}