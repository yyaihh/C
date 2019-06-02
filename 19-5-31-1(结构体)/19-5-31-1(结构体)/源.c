#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
typedef struct s1 {//12
	char a;//0,1+3
	int b; //4,4+0
	char c;//8,1+3
}s1;
typedef struct s2 {//8
	char a;//0,1
	char b;//1,1+2
	int c;//4,4
}s2;
typedef struct s3 {//24
	s2 a;//0,8
	int b;//8,4+4
	double c;//16,8+0
}s3;
typedef struct s4 {//16
	s2 a;//0,8
	int b;//8,4+0
	int c;//12,4+0
}s4;
typedef struct s5 {//16
	s2 a;//0,8+0
	double b;//8,8+0
	char c;//16,1+7
}s5;
typedef struct s6 {//16
	char a;//0,1+3
	int b;//4,4+0
	s2 c;//8,8+0
}s6;
typedef struct s7 {//16
	char a;//0,1+3
	s2 b;//4,4+8//自己是8字节,但是别人在对齐时为4,因为它自身对齐是按照4字节对齐的
	int c;//12,4+0
}s7;
typedef struct s8 {//16
	int a;//0,4+0
	//int c;//12,4+0
	char b[4];//4,1+1+1+5
	double c;//12,8+0
}s8;
int main() {
	printf("%d\n", sizeof(s5));
	printf("%d\n", offsetof(s5, a));
	printf("%d\n", offsetof(s5, b));
	printf("%d\n", offsetof(s5, c));
	printf("\n");
	printf("%d\n", sizeof(s6));
	printf("%d\n", offsetof(s6, a));
	printf("%d\n", offsetof(s6, b));
	printf("%d\n", offsetof(s6, c));
	printf("\n");
	printf("%d\n", sizeof(s7));
	printf("%d\n", offsetof(s7, a));
	printf("%d\n", offsetof(s7, b));
	printf("%d\n", offsetof(s7, c));
	printf("\n");
	printf("%d\n", sizeof(s8));
	printf("%d\n", offsetof(s8, a));
	printf("%d\n", offsetof(s8, b));
	printf("%d\n", offsetof(s8, c));
	system("pause");
	return 0;
}