#include<stdio.h>
#include<stdlib.h>
int Strcmp(char* p1, char* p2) {
	for (int i = 0; i < 1023; ++i) {
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
	char s1[1024] = { '\0' };
	char s2[1024] = { '\0' };
	char ch;
	printf("ÇëÊäÈës1\n");
	for (int i = 0; i < 1023; ++i) {
		ch = getchar();
		if (ch == '\n') {
			break;
		}
		s1[i] = ch;
	}
	printf("ÇëÊäÈës2\n");
	for (int i = 0; i < 1023; ++i) {
		ch = getchar();
		if (ch == '\n') {
			break;
		}
		s2[i] = ch;
	}
	printf("%d\n", Strcmp(s1, s2));
	system("pause");
}