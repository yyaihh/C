#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct arr {
	int num;
	struct arr* next;
};
typedef struct arr arr;
arr* creat(int n) {
	arr* s;
	arr* p;
	arr* head = (arr*)malloc(sizeof(arr));//头结点
	p = head;
	for (int i = 0; i < n; ++i) {
		s = (arr*)malloc(sizeof(arr));
		s->num = i + 1;
		s->next = p->next;
		p->next = s;
		p = p->next;
		if (i == n - 1) {
			p->next = NULL;
		}
	}
	return head;
}
void print(arr* head) {
	for (arr* p = head->next; p != NULL; p = p->next) {
		printf("%d\t", p->num);
	}
	printf("\n");
}
arr* del(arr* head, int m) {
	arr* p = head;
	arr* temp;
	for (int i = 0; i < m - 1; ++i) {
		p = p->next;
	}
	temp = p->next;
	printf("%d\n", temp->num);
	p->next = temp->next;
	free(temp);
	return head;
}
arr* insert(int m, arr* head) {
	int n;
	arr* p = head;
	arr* s = (arr*)malloc(sizeof(arr));
	printf("请输入num的值\n");
	scanf("%d", &n);
	s->num = n;
	for (int i = 0; i < m; ++i) {
		p = p->next;
	}
	s->next = p->next;
	p->next = s;
	return head;
}
void main() {
	int n, m, k;
	printf("请输入链表的长度\n");
	for (scanf("%d", &n); n <= 0; printf("您输入有误,请重新输入\n"), scanf("%d", &n));
	arr* head;
	head = creat(n);
	printf("输出未插入新节点前链表\n");
	print(head);
	printf("请输入需要插入的位置(0<= m <=%d)\n", n);
	for (scanf("%d", &m); m < 0 || m > n; printf("您输入有误,请重新输入\n"), scanf("%d", &m));
	head = insert(m, head);
	print(head);
	printf("要删除第几个节点,请输入\n");
	for (scanf("%d", &k); k < 1 || k>n; printf("您的输入有误,请重新输入\n"), scanf("%d", &k));
	head = del(head, k);
	printf("删除指定结点后链表为\n");
	print(head);
	system("pause");
}
