#if 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
	int a[3][4] = { 0 };
	int i, j;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; ++j) {
			printf("%d\t", &a[i][j]);
		}
		printf("\n");
	}
	printf("%d\n", sizeof(a));//48
	printf("%d\n", sizeof(a[0][0]));//4
	printf("%d\n", sizeof(a[0]));//16
	printf("%d\n", sizeof(a[0] + 1));//4
	printf("%d\n", sizeof(*(a[0] + 1)));//4
	printf("%d\n", sizeof(a + 1));//4
	printf("%d\n", sizeof(*(a + 1)));//16
	printf("%d\n", sizeof(&a[0] + 1));//4
	printf("%d\n", sizeof(*(&a[0] + 1)));//16
	printf("%d\n", sizeof(*a));//16
	printf("%d\n", sizeof(a[3]));//16
	system("pause");
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Test{
	int Num;//4
	char *pcName; //4
	short sDate; //2
	short sBa[4];
} *p;

//假设p 的值为0x100000。 如下表表达式的值分别为多少？
int main() {
	printf("%d\n", sizeof(int)+ sizeof(char*)+ sizeof(short) +  sizeof(short[4]));
	printf("%d\n", sizeof(struct Test));
	printf("%p\n", p);
	printf("%p\n", p + 0x1);
	printf("%p\n", (unsigned long)p + 0x1);
	printf("%p\n", (unsigned int)p + 0x1); 
	system("pause");
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
int main() {
	int a[4] = { 1, 2, 3, 4 };
	int *ptr1 = (int *)(&a + 1);
	int *ptr2 = (int *)((int)a + 1);
	printf("%p\n", &a[0]);
	printf("%x\n%x\n", ptr1[-1], *ptr2);//4,2000000
	system("pause");
	return 0;
}
#endif
#if 1
#include<stdio.h>
#include<stdlib.h>
int main() {
	int a = 1;
	char b = a;
	printf("%d\n", b);
	system("pause");
	return 0;
}
#endif