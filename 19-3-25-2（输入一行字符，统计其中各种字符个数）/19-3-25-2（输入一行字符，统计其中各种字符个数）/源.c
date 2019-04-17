#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 50
void main() {
	char str[M] = " ";
	printf("请输入一行字符\n");
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
			if (str[i] != '\n') {//因为fgets()函数会在末尾自动加上\n，影响判断结果，需要判断是否为换行符
				_else += 1;
			}
		}
	}
	printf("空格的个数为：%d\n", space);
	printf("英文字母的个数为：%d\n", letter);
	printf("数字的个数为：%d\n", num);
	printf("其他字符的个数为：%d\n", _else);
	system("pause");
}