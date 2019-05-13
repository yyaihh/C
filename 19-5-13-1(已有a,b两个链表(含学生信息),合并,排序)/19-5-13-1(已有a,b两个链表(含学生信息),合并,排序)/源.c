#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct student {
	int id;
	char name[1024];
	int score[3];
	struct student* next;
};
typedef struct student stu;
stu* creat(int n) {
	stu* s;
	stu* head;
	stu* p;
	s = (stu*)malloc(sizeof(stu));
	head = s;
	p = head;
	for (int i = 0; i < n; ++i) {
		s= (stu*)malloc(sizeof(stu));
		printf("请输入第%d个学生的信息\n", i + 1);
		printf("请输入学号\n");
		scanf("%d", &s->id);
		printf("请输入姓名\n");
		scanf("%s", &s->name);
		for (int j = 0; j < 3; ++j) {
			printf("请输入第%d门课的成绩\n", j + 1);
			scanf("%d", &s->score[j]);
		}
		s->next = p->next;
		p->next = s;
		p = p->next;
		if (i == n - 1) {
			p->next = NULL;
		}
	}
	return head;
}
void print(stu* head) {
	for (stu* p = head->next; p != NULL; p = p->next) {
		printf("%d\t%s\t%d\t%d\t%d\n", p->id, p->name, p->score[0], p->score[1], p->score[2]);
	}
}

void fun(stu* a, stu* b) {
	stu* p;
	stu* temp1;
	stu* temp2;
	//stu* temp2;
	for (p = a; p->next != NULL; p = p->next);//找到a的最后一个指针
	p->next = b->next;//让塔指向b
	free(b);
	print(a);
	for (stu* p = a->next; p != NULL; p = p->next) { 
		for (stu* q = p->next; q != NULL; q = q->next) {//lq为q的前驱
			if (p->id > q->id) {
				
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
	printf("链表a学生信息\n学号\t姓名\t成绩1\t成绩2\t成绩3\n");
	print(a);
	printf("链表b学生信息\n学号\t姓名\t成绩1\t成绩2\t成绩3\n");
	print(b);
	printf("合并排序后为\n");
	fun(a, b);
	printf("\n\n\n");
	print(a);
	system("pause");
}