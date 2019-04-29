#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main() {
	int a, b, c;
	int* ap = &a;
	int* bp = &b;
	int* cp = &c;
	printf("请输入三个整数\n");
	scanf("%d %d %d", ap, bp, cp);
	if (*ap > *bp ) {
		*ap = *ap^*bp;
		*bp = *ap^*bp;
		*ap = *ap^*bp;
	}
	if (*ap > *cp) {
		*ap = *ap^*cp;
		*cp = *ap^*cp;
		*ap = *ap^*cp;
	}
	if (*bp > *cp) {
		*bp = *bp^*cp;
		*cp = *bp^*cp;
		*bp = *bp^*cp;
	}
	printf("%d  %d  %d\n", *ap, *bp, *cp);
	system("pause");
}
