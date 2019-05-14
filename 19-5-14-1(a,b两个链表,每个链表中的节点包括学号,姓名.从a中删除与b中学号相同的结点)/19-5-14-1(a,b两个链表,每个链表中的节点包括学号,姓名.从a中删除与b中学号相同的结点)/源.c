#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define N sizeof(stu)
struct student {
	int id;
	char name[1024];
	struct student* next;
};
typedef struct student stu;
stu* creat(int n) {//创建
	stu* head;
	stu* s = (stu*)malloc(N);
	head = s;
	stu* p = head;
	for (int i = 0; i < n; ++i) {
		s = (stu*)malloc(N);
		printf("请输入第%d个学生的信息\n", i + 1);
		printf("请输入学号\n");
		scanf("%d", &s->id);
		printf("请输入姓名\n");
		scanf("%s", &s->name);
		s->next = p->next;
		p->next = s;
		p = p->next;
		if (i == n - 1) {
			p->next = NULL;
		}
	}
	return head;
}
void print(stu* head) {//输出
	int n = 0;
	for (stu* p = head->next; p != NULL; p = p->next, n = 1) {
		printf("%d\t%s\n", p->id, p->name);
	}
	if (n == 0) {
		printf("链表为空\n");
	}
}
void fun(stu* a, stu* b) {
	stu* temp;
	for (stu* p = a; p->next != NULL;) {
		for (stu* q = b; q->next != NULL; q = q->next) {
			if (p->next->id == q->next->id) {
				temp = p->next;
				p->next = temp->next;
				free(temp);
				break;
			}
			if (q->next->next == NULL) {
				p = p->next;
			}
		}
	}
}
void main() {
	int n, m;
	printf("请输入链表a的长度\n");
	scanf("%d", &n);
	printf("请输入链表b的长度\n");
	scanf("%d", &m);
	printf("请输入链表a中的学生信息\n");
	stu* a = creat(n);
	printf("请输入链表b中的学生信息\n");
	stu* b = creat(m);
	printf("链表a学生信息\n学号\t姓名\n");
	print(a);
	printf("链表b学生信息\n学号\t姓名\n");
	print(b);
	printf("删除相同学号后a链表为\n学号\t姓名\n");
	fun(a, b);
	print(a);
	system("pause");
}