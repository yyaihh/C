#pragma once
#include"AddressList.h"
int Menu() {//�˵�
	int choic;
	int n = 0;
	printf("1.�����ϵ�� 2.ɾ����ϵ��\n"
		"3.�޸���ϵ����Ϣ 4.������ϵ��\n"
		"5.��ʾ������ϵ�� 6.���������ϵ��\n"
		"7.���������� 8.���浽�ļ�\n"
		"9.���ļ��ж�ȡ��ϵ�� 0.�˳�\n"
		"����������ѡ��!\n");
	//for (n = scanf("%d", &choic); n != 1 || choic < 0 || choic > 9; printf("������������,����������"), n = scanf("%d", &choic));
	n = scanf("%d", &choic);
	while(n != 1 || choic < 0 || choic > 9) {
		printf("������������,����������\n");
		while (getchar() != '\n');
		n = scanf("%d", &choic);
	}
	return choic;
}
void input(AL* p) {
	int n = 0;
	printf("����������\n");
	scanf("%s", p->name);
	getchar();
	printf("�������Ա�,��m,Ůf\n");
	n = scanf("%c", &p->sex);
	while (n != 1 || p->sex != 'm' && p->sex != 'f') {
		printf("������������,����������\n");
		while (getchar() != '\n');
		n = scanf("%c", &p->sex);
	}
	printf("����������\n");
	n = scanf("%d", &p->age);
	while (n != 1 || p->age < 0 || p->age > 130) {
		printf("������������,����������\n");
		while (getchar() != '\n');
		n = scanf("%d", &p->age);
	}
	printf("�������ַ\n");
	scanf("%s", p->Add);
	printf("������绰����\n");
	scanf("%s", p->Tel);
}
AL* add(AL* temphead) {//��
	int n = 0;
	AL* p = temphead;
	AL* s = NULL;
	char choic;
	do {
		s = (AL*)malloc(sizeof(AL));
		if (s == NULL) {
			exit(EXIT_FAILURE);
		}
		input(s);
		s->next = p->next;
		p->next = s;
		p = p->next;
		p->next = NULL;
		printf("��������������'y'\n");
		getchar();
		n = scanf("%c", &choic);
		while (n != 1 ) {
			printf("������������,����������\n");
			while (getchar() != '\n');
			n = scanf("%c", &choic);
		}
	} while (choic == 'y');
	system("cls");
	return p;
}
void del(AL* p) {//ɾ
	AL* temp;
	temp = p->next;
	p->next = temp->next;
	free(temp);
}
int alter(AL* p) {//��
	input(p->next);
}
AL* find_1(AL* p, const char* str) {//��������
	if (strstr(p->next->name, str)) {
		return p;
	}
	return NULL;
}
AL* find_2(AL* p, const char* str) {//��������
	char temp[5];
	sprintf(temp, "%d", p->next->age);
	if (strstr(temp, str)) {
		return p;
	}
	return NULL;
}
AL* find_3(AL* p, const char* str) {//���绰������
	if (strstr(p->next->Tel, str)) {
		return p;
	}
	return NULL;
}
AL* find_4(AL* p, const char* str) {//����ַ��
	if (strstr(p->next->Add, str)) {
		return p;
	}
	return NULL;
}
AL** allfind(AL* head) {//��
	char str[50] = { 0 };
	AL* find = NULL;
	AL** ptr = NULL;
	ptr = (AL**)calloc(5, sizeof(AL*));
	printf("��������Ҫ���ҵ���Ϣ\n");
	scanf("%s", str);
	int count = 0;
	for (AL* p = head; p->next != NULL; p = p->next) {
		if (count == 5) {
			ptr = (AL**)realloc(ptr, 5 * sizeof(AL*));
		}
		if (find = find_1(p, str)) {
			ptr[count++] = find;
			continue;
		}
		if (find = find_2(p, str)) {
			ptr[count++] = find;
			continue;
		}
		if (find = find_3(p, str)) {
			ptr[count++] = find;
			continue;
		}
		if (find = find_4(p, str)) {
			ptr[count++] = find;
			continue;
		}
	}
	if (count != 0) {
		printf("���\t����\t�Ա�\t����\t��ַ\t\t�绰\t\t\n");
		for (int i = 0; i < count; ++i) {
			printf("%d\t", i + 1);
			print(ptr[i]);
		}
	}
	return ptr;
}

void print(AL* p) {//���
	printf("%s\t%c\t%d\t%s\t\t%s\t\t\n", p->name, p->sex, p->age, p->Add, p->Tel);
}
void allprint(AL* head) {//ȫ�����
	printf("���\t����\t�Ա�\t����\t��ַ\t\t�绰\t\t\n");
	int i = 1;
	for (AL* p = head->next; p != NULL; p = p->next, ++i) {
		printf("%d\t", i);
		print(p);
	}
}
int empty() {//���

}
int sort(AL* head) {

}
int fun() {
	int choic_1;
	AL** find;
	int choic_2;
	AL* head = (AL*)malloc(sizeof(AL));//ͷ���
	if (head == NULL) {
		exit(EXIT_FAILURE);
	}
	AL* temphead = head;
	while (1) {
		choic_1 = Menu();
		switch (choic_1) {
		case ���:
			temphead = add(temphead);
			break;
		case ɾ��:
			find = allfind(head);
			printf("��������Ҫɾ����ѡ��\n");
			scanf("%d", &choic_2);
			del(find[choic_2 - 1]);
			free(find);
			find = NULL;
			break;
		case �޸�:
			find = allfind(head);
			printf("��������Ҫ�޸ĵ�ѡ��\n");
			scanf("%d", &choic_2);
			alter(find[choic_2 - 1]);
			free(find);
			find = NULL;
			break;
		case ����:
			find = allfind(head);
			free(find);
			find = NULL;
			break;
		case ��ʾ:
			allprint(head);
			break;
		case ���:
			break;
		case ����:
			break;
		case ����:
			break;
		case ��ȡ:
			break;
		case �˳�:
			printf("�ټ�!\n");
			system("pause");
			exit(0);
			break;
		default:
			printf("����!\n");
			system("pause");
			exit(0);
		}
	}

}