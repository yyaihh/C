//#include<stdio.h>
//#include<stdlib.h>
//struct e{
//	int a;
//	char b[20];
//	int c;
//}s;
//struct score {
//	int chinese;
//	int math;
//	int english;
//}s1 = { 88,89,80 };
//struct score s2 = { 90,45,67 };
//struct Student
//{
//	char name[20];//名字
//	int age;//年龄
//	char sex[5];//性别
//	char id[20];//学号
//	struct score stu;
//}stu1 = { "张三",18,"男","12376",{ 88,89,80 } };
//struct Student stu2 = { "李四",20,"男","12378",{ 90,45,67 } };
//
//int main() {
//	printf("%d\n", sizeof(s));
//	system("pause");
//	return 0;
//}
#if 0
#include<stdio.h>
#include<stdlib.h>
typedef struct MyStruct {
	int arr[1000];
	char str[10];
}S;

void print_1(S x) {
	printf("%s\n", x.str);
}

void print_2(S* p) {
	printf("%s\n", p->str);
}

int main() {
	S a = { {1,2,3,4},"哈哈" };
	print_1(a);
	print_2(&a);
	system("pause");
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
#define M 4
enum day{
	星期二 = 2,
	星期五 = 5,
	星期六,
	星期三 = 3
};
enum day 星期七 = 星期二 + 星期五;
enum day 星期四 = M;
enum day 星期一 = 1;
/*
//不可以这样
enum day 星期一;
星期一 = 1;
*/
int main() {
	int Mon = 星期一;
	int num = 星期一 + 星期二;
	printf("%d %d %d %d %d %d %d\n", 星期一, 星期二, 星期三, 星期四, 星期五, 星期六, 星期七);
	printf("Mon = %d, num = %d\n", Mon, num);
	system("pause");
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
星期四 = 4;
int main() {
	printf("%d\n", 星期四);
	system("pause");
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
union Un1
{
	char c[5];
	int i;
};
union Un2
{
	short c[7];
	int i;
};
int main() {
	//下面输出的结果是什么？
	printf("%d\n", sizeof(union Un1));
	printf("%d\n", sizeof(union Un2));
	system("pause");
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
union Un
{
	char c;
	int i;
};
int main() {
	union Un un;
	printf("%p\n", &(un.i));
	printf("%p\n", &(un.c));
	printf("%d\n", sizeof(union Un));
	printf("%d\n", offsetof(union Un, c));
	printf("%d\n", offsetof(union Un, i));
	system("pause");
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>

union Un1
{
	char c[5];
	int i;
};
union Un2
{
	short c[7];
	int i;
};
int main() {
	printf("%d\n", sizeof(union Un1));
	printf("%d\n", sizeof(union Un2));
	system("pause");
	return 0;
}
#endif 