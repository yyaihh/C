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
	printf("������s1\n");
	for (int i = 0, ch = '\0'; ch != '\n'; ++i) {
		ch = getchar();
		if (i >= N) {//�������ַ�������ʱ, �������ܼ���������ַ�,ֱ������\nΪֹ
			//����Ϊ�˷�ֹ�ַ���������ɺ�������ַ��ᱻ��һ����Ҫ��������ݽ���
			continue;
		}
		if (ch == '\n' || i == N - 1) {
			s1[i] = '\0';
			continue;
		}
		s1[i] = ch;
	}
	printf("������s2\n");
	for (int i = 0, ch = '\0'; ch != '\n'; ++i) {
		ch = getchar();
		if (i >= N) {//�������ַ�������ʱ, �������ܼ���������ַ�,ֱ������\nΪֹ
			//����Ϊ�˷�ֹ�ַ���������ɺ�������ַ��ᱻ��һ����Ҫ��������ݽ���
			continue;
		}
		if (ch == '\n' || i == N - 1) {
			s2[i] = '\0';
			continue;
		}
		s2[i] = ch;
	}
	printf("s1Ϊ%s\ns2Ϊ%s\n", s1, s2);
	printf("%d\n", Strcmp(s1, s2));
	system("pause");
}