#include<stdio.h>
#include<stdlib.h>
union Un{
	char c;
	int num;
};
int main() {
	union Un u;
	u.num = 1;
	printf("%d\n", u.c);
	system("pause");
	return 0;
}