#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
void main() {
	printf("������һ��Ӣ���ַ�\n");
	while (1) {
		char word[1] = "0";
		word[0]=_getch();
		if (word[0] > 47 && word[0] < 58) {
			printf("%c\n", word[0]);
			printf("������һ��Ӣ���ַ�\n");
			continue;
		}
		else if (word[0] > 64 && word[0] < 91)//��д��ĸ
		{
			printf("%c\n", word[0]);
			_strlwr(word);
			printf("ת�����ַ�Ϊ:%c\n", word[0]);
			continue;
		}
		else if (word[0] > 96 && word[0] < 123)//Сд��ĸ
		{
			printf("%c\n", word[0]);
			 _strupr(word);
			printf("ת�����ַ�Ϊ:%c\n", word[0]);
			continue;
		}
	}
	system("pause");
}