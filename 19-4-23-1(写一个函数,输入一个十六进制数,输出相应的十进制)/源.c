#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void HEX_DEC(int num, int N) {
	if (num > N - 1) {
		HEX_DEC(num / N, N);
	}
	printf("%d", num % N);
}
void main() {
	int num;
	printf("����һ��ʮ�����Ƶ���\n");
	scanf("%x", &num);
	printf("ֱ����%%d���:%d\n", num);
	printf("�ú������:");
	HEX_DEC(num, 10);//ת���ɼ����ƾͰѵڶ����������ɼ�
	printf("\n");
	system("pause");
}