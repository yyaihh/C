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
//	char name[20];//����
//	int age;//����
//	char sex[5];//�Ա�
//	char id[20];//ѧ��
//	struct score stu;
//}stu1 = { "����",18,"��","12376",{ 88,89,80 } };
//struct Student stu2 = { "����",20,"��","12378",{ 90,45,67 } };
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
	S a = { {1,2,3,4},"����" };
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
	���ڶ� = 2,
	������ = 5,
	������,
	������ = 3
};
enum day ������ = ���ڶ� + ������;
enum day ������ = M;
enum day ����һ = 1;
/*
//����������
enum day ����һ;
����һ = 1;
*/
int main() {
	int Mon = ����һ;
	int num = ����һ + ���ڶ�;
	printf("%d %d %d %d %d %d %d\n", ����һ, ���ڶ�, ������, ������, ������, ������, ������);
	printf("Mon = %d, num = %d\n", Mon, num);
	system("pause");
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
������ = 4;
int main() {
	printf("%d\n", ������);
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
	//��������Ľ����ʲô��
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