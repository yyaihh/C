#include<stdio.h>
#include<stdlib.h>
#if 0
int main() {
	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int(*p)[4] = a;
	printf("\t[0]\t[1]\t[2]\t[3]\n");
	for (int i = 0; i < 3; ++i, printf("\n")) {
		printf("a[%d]\t", i);
		for (int j = 0; j < 4; ++j) {
			printf("%d\t", *(*(p + i) + j));//�ȼ�printf("%d\t", a[i][j]);
		}
	}
	printf("\n�����Ԫ�ص�ַΪ\n");
	printf("\t[0]\t\t[1]\t\t[2]\t\t[3]\n");
	for (int i = 0; i < 3; ++i, printf("\n")) {
		printf("a[%d]\t", i);
		for (int j = 0; j < 4; ++j) {
			printf("%p\t", *(p + i) + j);
		}
	}
	printf("\n");
	printf("&a\t=%p\n", &a);
	printf("&a+1\t=%p\n\n", &a + 1);

	printf("a��ָ�ڴ���ռ�ֽ�Ϊ:%d\n", sizeof(a));
	printf("a\t=%p,������Ϊ:%d\n", a, **a);
	printf("a+1\t=%p,������Ϊ:%d\n\n", a + 1, **(a + 1));

	printf("a[0]��ָ�ڴ���ռ�ֽ�Ϊ:%d\n", sizeof(a[0]));
	printf("&a[0]��ָ�ڴ���ռ�ֽ�Ϊ:%d\n", sizeof(&a[0]));
	printf("&a[0]\t=%p\n", &a[0]);
	printf("a[0]\t=%p,������Ϊ:%d\n", a[0], *a[0]);
	printf("a[0]+1\t=%p,������Ϊ:%d\n\n", a[0] + 1, *(a[0] + 1));

	printf("&a[0][0]��ָ�ڴ���ռ�ֽ�Ϊ:%d\n", sizeof(&a[0][0]));
	printf("a[0][0]\t��ַ=%p,ֵΪ:%d\n", &a[0][0], a[0][0]);
	printf("&a[0][0]+1=%p,������Ϊ:%d\n\n", &a[0][0] + 1, *(&a[0][0] + 1));

	printf("*a+1\t=%p,������Ϊ:%d\n", *a + 1, *(*a + 1));
	printf("*(a+1)\t=%p,������Ϊ:%d\n", *(a + 1), *(*(a + 1)));
	printf("*(*(a+1)+1)��ַ=%p,ֵΪ:%d\n", *(a + 1) + 1, *(*(a + 1) + 1));
	system("pause");
	return 0;
}
#endif
#if 1
#include<stdio.h>
#include<stdlib.h>
int main() {
	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int(*p)[4] = a;
	printf("\t[0]\t[1]\t[2]\t[3]\n");
	for (int i = 0; i < 3; ++i, printf("\n")) {
		printf("a[%d]\t", i);
		for (int j = 0; j < 4; ++j) {
			printf("%d\t", *(*(p + i) + j));//�ȼ�printf("%d\t", a[i][j]);
		}
	}
	printf("\n�����Ԫ�ص�ַΪ\n");
	printf("\t[0]\t\t[1]\t\t[2]\t\t[3]\n");
	for (int i = 0; i < 3; ++i, printf("\n")) {
		printf("a[%d]\t", i);
		for (int j = 0; j < 4; ++j) {
			printf("%p\t", *(p + i) + j);
		}
	}
	printf("\n");
	printf("&a\t=%p\n", &a);
	printf("a\t=%p,������Ϊ:%d\n", a, **a);
	printf("&a[0]\t=%p\n", &a[0]);
	printf("a[0]\t=%p,������Ϊ:%d\n", a[0], *a[0]);
	printf("&a[0][0]=%p,������Ϊ:%d\n\n", &a[0][0], a[0][0]);
	printf("&a��ָ�ڴ���ռ�ֽ�Ϊ:%d\n", sizeof(&a));
	printf("a��ָ�ڴ���ռ�ֽ�Ϊ:%d\n", sizeof(a));
	printf("a[0]��ָ�ڴ���ռ�ֽ�Ϊ:%d\n", sizeof(a[0]));
	printf("&a[0]��ָ�ڴ���ռ�ֽ�Ϊ:%d\n", sizeof(&a[0]));
	printf("&a[0][0]��ָ�ڴ���ռ�ֽ�Ϊ:%d\n", sizeof(&a[0][0]));
	system("pause");
	return 0;
}
#endif