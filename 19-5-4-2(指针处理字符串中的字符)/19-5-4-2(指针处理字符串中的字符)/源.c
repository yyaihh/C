#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 1024
void main() {
	char str[M];
	fgets(str, M, stdin);
	int space = 0;
	int capital = 0;
	int lowercase = 0;
	int num = 0;
	int other = 0;
	for (char* p = str; *p != '\0';++p) {
		if (*p == ' ') {
			space += 1;
		}
		else if (*p > 64 && *p < 91) {
			capital += 1;
		}
		else if (*p > 96 && *p < 123) {
			lowercase += 1;
		}
		else if (*p > 47 && *p < 58) {
			num += 1;
		}
		else {
			if (*p != '\n') {//��Ϊfgets()��������ĩβ�Զ�����\n��Ӱ���жϽ������Ҫ�ж��Ƿ�Ϊ���з�
				other += 1;
			}
		}
	}
	printf("�ո�ĸ���Ϊ��%d\n", space);
	printf("��дӢ����ĸ�ĸ���Ϊ��%d\n", capital);
	printf("СдӢ����ĸ�ĸ���Ϊ��%d\n", capital);
	printf("���ֵĸ���Ϊ��%d\n", num);
	printf("�����ַ��ĸ���Ϊ��%d\n", other);
	system("pause");
}
