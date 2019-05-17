#include<stdio.h>
#include<stdlib.h>
#define N 10
int Strcmp(const char* p1, const char* p2) {
	for (int i = 0; i < N; ++i) {
		if (p1[i] != p2[i]) {
			return p1[i] - p2[i];
		}
		else if (p1[i] == '\0' && p2[i] == '\0') {
			return 0;
		}
	}
	return 0;
}
void main() {
	char s1[N];
	char s2[N];
	printf("请输入s1\n");
	for (int i = 0, ch = '\0'; ch != '\n'; ++i) {
		ch = getchar();
		if (i >= N) {//当超出字符串长度时, 继续接受键盘输入的字符,直到输入\n为止
			//这是为了防止字符串输入完成后输入的字符会被下一个需要输入的数据接收
			continue;
		}
		if (ch == '\n' || i == N - 1) {
			s1[i] = '\0';
			continue;
		}
		s1[i] = ch;
	}
	printf("请输入s2\n");
	for (int i = 0, ch = '\0'; ch != '\n'; ++i) {
		ch = getchar();
		if (i >= N) {//当超出字符串长度时, 继续接受键盘输入的字符,直到输入\n为止
			//这是为了防止字符串输入完成后输入的字符会被下一个需要输入的数据接收
			continue;
		}
		if (ch == '\n' || i == N - 1) {
			s2[i] = '\0';
			continue;
		}
		s2[i] = ch;
	}
	printf("s1为%s\ns2为%s\n", s1, s2);
	printf("%d\n", Strcmp(s1, s2));
	system("pause");
}