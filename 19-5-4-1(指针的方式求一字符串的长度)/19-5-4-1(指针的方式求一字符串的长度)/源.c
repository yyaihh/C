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
	printf("������str\n");
	for (int i = 0; i < 1023; ++i) {
		ch = getchar();
		if (ch == '\n') {
			break;
		}
		p[i] = ch;
	}
	printf("����ַ���Ϊ:%s\n", p);
	printf("����ַ����ĳ���Ϊ:%d\n", Strlen(p));
	system("pause");
}
