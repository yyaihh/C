#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main() {
	double score;
	printf("������ɼ�\n");
	scanf("%lf", &score);
	for (; score > 100 || score < 0;) {
		printf("����������������������0��100������\n");
		scanf("%lf", &score);
	}
	switch ((int)score / 10) {
	case 10:
	case 9:
		printf("A\n"); break;
	case 8:
		printf("B\n"); break;
	case 7:
		printf("C\n"); break;
	case 6:
		printf("D\n"); break;
	default :
		printf("E\n"); break;
	}
	system("pause");
}