#include<stdio.h>
#include<stdlib.h>
int Strlen(char* str) {
	if (*str == '\0') {
		return 0;
	}
	else {
		return Strlen(str + 1) + 1;
	}
}
void fun(char str[],int L) {
	int ret = 0;
	for (int i = 0; i < L / 2; ++i) {
		str[i] = str[i] ^ str[L - 1 - i];
		str[L - 1 - i] = str[i] ^ str[L - 1 - i];
		str[i] = str[i] ^ str[L - 1 - i];
	}
	printf("//中间值为：%s\n", str);
	for (int i = 0; i <= L; ++i) {
		if (str[i] == ' '|| str[i] == '\0') {
			for (int j = ret, m = 1; m <= (i - ret) / 2; ++j, ++m) {
				str[j] = str[j] ^ str[i - m];
				str[i - m] = str[j] ^ str[i - m];
				str[j] = str[j] ^ str[i - m];
			}
			ret = i + 1;
		}
	}
}
void main() {
	char str[] = "student am I";
	printf("原字符串为:%s\n", str);
	int L = Strlen(str);
	fun(str, L);
	printf("转换完成后:%s\n", str);
	system("pause");
}