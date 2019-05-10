#include<stdio.h>
#include<stdlib.h>
int Strlen(char* str) {
	int count = 0;
	while (*str != '\0') {
		count += 1;
		++str;
	}
	return count;
}
void main() {
	char str[1024] = { '\0' };
	char ch;
	char* p = str;
	printf("请输入str\n");
	for (int i = 0; i < 1023; ++i) {
		ch = getchar();
		if (ch == '\n') {
			break;
		}
		p[i] = ch;
	}
	printf("这个字符串为:%s\n", p);
	printf("这个字符串的长度为:%d\n", Strlen(p));
	system("pause");
}
