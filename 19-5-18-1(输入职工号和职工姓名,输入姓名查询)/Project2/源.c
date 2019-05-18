#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
struct staff {//�����ṹ�����
	int id;//ְ����
	char name[1024];//����
};
void input(struct staff* p) {//����ְ����������ְ����
	struct staff* q = p;
	for (int i = 1; p < q + N; ++i, ++p) {
		printf("�������%d��ְ����ְ����\n", i);
		scanf("%d", &p->id);
		printf("�������ְ��������\n");
		scanf("%s", p->name);//p->name��������ָ��,��ŵľ��ǵ�ַ,����ȡ��ַ

	}
}
void sort(struct staff* p) {//��ְ���ŴӴ�С����
	char temp[1024];
	struct staff* q = p;
	for (; p < q + N; ++p) {
		for (struct staff* qq = p + 1; qq < q + N; ++qq) {
			if (p->id > qq->id) {
				p->id = p->id ^ qq->id;//��λ���
				qq->id = p->id ^ qq->id;
				p->id = p->id ^ qq->id;
				strcpy(temp, p->name);
				strcpy(p->name, qq->name);
				strcpy(qq->name, temp);
			}
		}
	}
}
struct staff* bisearch(char* str, struct staff* p) {
	struct staff* q = p;
	int n;
	for (int i = 1; p < q + N; ++i, ++p) {
		n = strlen(p->name);
		if (n == strlen(str)) {
			for (int j = 0; j < n; ++j) {
				if (str[j] != p->name[j]) {
					break;
				}
				if (j == n - 1) {
					return p;
				}
			}
		}
	}
	return NULL;
}
void main() {
	char str[1024];
	struct staff staff[N];//����N���ṹ�����
	struct staff* p;//����ָ��ṹ��
	p = staff;//ָ��ṹ���������Ԫ��
	input(p);
	sort(p);
	system("cls");
	for (; p < staff + N; ++p) {
		printf("%d\t%s\n", p->id, p->name);
	}
	p = staff;
	printf("��������Ҫ��ѯ��Ա������\n");
	scanf("%s", str);
	struct staff* q = bisearch(str, p);
	if (q != NULL) {
		printf("ְ��%s��ְ����Ϊ:%d\n", q->name, q->id);
	}
	else {
		printf("û������Ϊ%s��ְ��\n", str);
	}
	system("pause");
}
