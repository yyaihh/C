#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main() {
	char str1[10], str2[10], str3[11];
	char* p1 = str1;
	char* p2 = str2;
	char* p3 = str3;
	char* temp;
	scanf("%s", p1);
	scanf("%s", p2);
	scanf("%s", p3);
	for (int i = 0; i < 10; ++i) {
		if (p1[i] > p2[i]) {
			temp = p1;
			p1 = p2;
			p2 = temp;
			break;
		}
	}
	for (int i = 0; i < 10; ++i) {
		if (p1[i] > p3[i]) {
			temp = p1;
			p1 = p3;
			p3 = temp;
			break;
		}
	}
	for (int i = 0; i < 10; ++i) {
		if (p2[i] > p3[i]) {
			temp = p2;
			p2 = p3;
			p3 = temp;
			break;
		}
	}
	printf("从小到大为:\n%s\n%s\n%s\n", p1,p2,p3);
	system("pause");
}