#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 50
void main() {
	char str[M] = " ";
	printf("������һ���ַ�\n");
	fgets(str, M+1, stdin);
	int space = 0;
	int letter = 0;
	int num = 0;
	int _else = 0;
	for (int i = 0; i < (int)strlen(str); ++i) {
		if (str[i] == ' ') {
			space += 1;
		}
		else if (str[i] > 64 && str[i] < 91 || str[i]>96 && str[i] < 123)  {
			letter += 1;
		}
		else if (str[i] > 47 && str[i] < 58)  {
			num += 1;
		}
		else {
			if (str[i] != '\n') {//��Ϊfgets()��������ĩβ�Զ�����\n��Ӱ���жϽ������Ҫ�ж��Ƿ�Ϊ���з�
				_else += 1;
			}
		}
	}
	printf("�ո�ĸ���Ϊ��%d\n", space);
	printf("Ӣ����ĸ�ĸ���Ϊ��%d\n", letter);
	printf("���ֵĸ���Ϊ��%d\n", num);
	printf("�����ַ��ĸ���Ϊ��%d\n", _else);
	system("pause");
}