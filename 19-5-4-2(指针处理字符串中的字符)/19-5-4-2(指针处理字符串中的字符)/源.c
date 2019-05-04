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
			if (*p != '\n') {//因为fgets()函数会在末尾自动加上\n，影响判断结果，需要判断是否为换行符
				other += 1;
			}
		}
	}
	printf("空格的个数为：%d\n", space);
	printf("大写英文字母的个数为：%d\n", capital);
	printf("小写英文字母的个数为：%d\n", capital);
	printf("数字的个数为：%d\n", num);
	printf("其他字符的个数为：%d\n", other);
	system("pause");
}
