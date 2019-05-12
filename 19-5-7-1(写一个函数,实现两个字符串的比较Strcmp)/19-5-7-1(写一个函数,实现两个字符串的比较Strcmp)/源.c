#include<stdio.h>
#include<stdlib.h>
#define N 1024
int Strcmp(char* p1, char* p2) {
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
	char ch;
	printf("ÇëÊäÈës1\n");
	for (int i = 0; i < N; ++i) {
		ch = getchar();
		if (ch == '\n' || i == N - 1) {
			s1[i] = '\0';
			break;
		}
		s1[i] = ch;
	}
	printf("ÇëÊäÈës2\n");
	for (int i = 0; i < N; ++i) {
		ch = getchar();
		if (ch == '\n' || i == N - 1) {
			s2[i] = '\0';
			break;
		}
		s2[i] = ch;
	}
	printf("%d\n", Strcmp(s1, s2));
	system("pause");
}