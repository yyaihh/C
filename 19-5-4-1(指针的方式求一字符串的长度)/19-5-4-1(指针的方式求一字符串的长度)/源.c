#include<stdio.h>
#include<stdlib.h>
#define N 10
#include<string.h>
int Strlen(char* str) {
	int count = 0;
	while (*str != '\0') {
		count += 1;
		++str;
	}
	return count;
}
void main() {
	char str[N];
	char* p = str;
	printf("请输入str\n");
	for (int i = 0, ch = '\0';ch != '\n'; ++i) {
		ch = getchar();
		if (i >= N) {//当超出字符串长度时, 继续接受键盘输入的字符,直到输入\n为止
			//这是为了防止字符串输入完成后输入的字符会被下一个需要输入的数据接收
			continue;
		}
		if (ch == '\n' || i == N - 1) {
			p[i] = '\0';
			continue;
		}
		p[i] = ch;
	}
	printf("这个字符串为:%s\n", p);
	printf("这个字符串的长度为:%d\n", Strlen(p));
	system("pause");
}
