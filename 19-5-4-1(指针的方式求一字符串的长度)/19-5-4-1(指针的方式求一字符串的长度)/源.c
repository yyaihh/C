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
	printf("������str\n");
	for (int i = 0, ch = '\0';ch != '\n'; ++i) {
		ch = getchar();
		if (i >= N) {//�������ַ�������ʱ, �������ܼ���������ַ�,ֱ������\nΪֹ
			//����Ϊ�˷�ֹ�ַ���������ɺ�������ַ��ᱻ��һ����Ҫ��������ݽ���
			continue;
		}
		if (ch == '\n' || i == N - 1) {
			p[i] = '\0';
			continue;
		}
		p[i] = ch;
	}
	printf("����ַ���Ϊ:%s\n", p);
	printf("����ַ����ĳ���Ϊ:%d\n", Strlen(p));
	system("pause");
}
