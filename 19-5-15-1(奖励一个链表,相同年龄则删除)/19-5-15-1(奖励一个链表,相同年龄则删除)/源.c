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
		printf("�������%d��ѧ������Ϣ\n", i + 1);
		printf("������ѧ��\n");
		scanf("%d", &s->id);
		printf("����������\n");
		scanf("%s", &s->name);
		printf("�������Ա�\n");
		scanf("%s", &s->sex);
		printf("����������\n");
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
				printf("��ɾ��ѧ��Ϊ%d��ѧ����Ϣ\n", q->next->id);
				--i;//ɾ��һ��ѧ����Ϣ��i������
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
	printf("ѧ��\t����\t�Ա�\t����\n");
	for (stu* p = head->next; p != NULL; p = p->next) {
		printf("%d\t%s\t%s\t%d\n", p->id, p->name, p->sex, p->age);
	}
}
void main() {
	int n;
	printf("��������ĳ���\n");
	scanf("%d", &n);
	stu* a = creat(n);
	print(a);
	system("pause");
}