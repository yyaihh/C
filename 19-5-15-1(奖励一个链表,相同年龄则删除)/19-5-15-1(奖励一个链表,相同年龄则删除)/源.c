#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define N sizeof(stu)
struct student {
	int id;
	char name[1024];
	char sex[10];
	int age;
	struct student* next;
};
typedef struct student stu;
stu* creat(int n) {
	stu* head;
	stu* p;
	stu* s = (stu*)malloc(N);
	head = s;
	p = head;
	for (int i = 0; i < n; ++i) {
		s = (stu*)malloc(N);
		printf("请输入第%d个学生的信息\n", i + 1);
		printf("请输入学号\n");
		scanf("%d", &s->id);
		printf("请输入姓名\n");
		scanf("%s", &s->name);
		printf("请输入性别\n");
		scanf("%s", &s->sex);
		printf("请输入年龄\n");
		scanf("%d", &s->age);
		s->next = p->next;
		p->next = s;
		p = p->next;
		if (i == n - 1) {
			p->next = NULL;
		}
		stu* temp;
		for (stu* q = head; q->next != p; q = q->next) {
			if (q->next->age == p->age) {
				printf("已删除学号为%d的学生信息\n", q->next->id);
				--i;//删除一名学生信息后i不自增
				temp = q->next;
				q->next = temp->next;
				free(temp);
				break;
			}
		}
	}
	return head;
}
void print(stu* head) {
	printf("学号\t姓名\t性别\t年龄\n");
	for (stu* p = head->next; p != NULL; p = p->next) {
		printf("%d\t%s\t%s\t%d\n", p->id, p->name, p->sex, p->age);
	}
}
void main() {
	int n;
	printf("输入链表的长度\n");
	scanf("%d", &n);
	stu* a = creat(n);
	print(a);
	system("pause");
}