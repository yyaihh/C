#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void reverse_string(char * string) {
	int len = strlen(string) - 1;
	char tmp;
	if (len > 0) {
		tmp = *string;
		*string = *(string + len);
		*(string + len) = '\0';
		reverse_string(string + 1);
		*(string + len) = tmp;
	}
}
void main() {
	char str[] = { "abcdefg" };
	printf("原字符串为:%s\n", str);
	reverse_string(str);
	printf("转换后字符串为:%s\n", str);
	system("pause");
}
