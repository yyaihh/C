#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
void main() {
	printf("请输入一个英文字符\n");
	while (1) {
		char word[1] = "0";
		word[0]=_getch();
		if (word[0] > 47 && word[0] < 58) {
			printf("%c\n", word[0]);
			printf("请输入一个英文字符\n");
			continue;
		}
		else if (word[0] > 64 && word[0] < 91)//大写字母
		{
			printf("%c\n", word[0]);
			_strlwr(word);
			printf("转化后字符为:%c\n", word[0]);
			continue;
		}
		else if (word[0] > 96 && word[0] < 123)//小写字母
		{
			printf("%c\n", word[0]);
			 _strupr(word);
			printf("转化后字符为:%c\n", word[0]);
			continue;
		}
	}
	system("pause");
}