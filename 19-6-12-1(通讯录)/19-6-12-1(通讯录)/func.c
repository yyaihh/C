#define _CRT_SECURE_NO_WARNINGS
#include"AddressList.h"
int Menu() {//�˵�
	int choic;
	int n = 0;
	printf("1.�����ϵ��         2.ɾ����ϵ��\n"
		"3.�޸���ϵ����Ϣ     4.������ϵ��\n"
		"5.��ʾ������ϵ��     6.���������ϵ��\n"
		"7.����������         8.���浽�ļ�\n"
		"9.���ļ��ж�ȡ��ϵ�� 0.�˳�\n"
		"����������ѡ��!\n");
	n = scanf("%d", &choic);
	while (n != 1 || choic < 0 || choic > 9) {
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
	while (n != 1 || p->age <= 0 || p->age > 130) {
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
		while (n != 1) {
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
void alter(AL* p) {//��
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
	if (head->next == NULL) {
		printf("��δ�����ϵ��\n");
		return NULL;
	}
	char str[100] = { 0 };
	AL* find = NULL;
	AL** ptr = NULL;
	ptr = (AL**)calloc(4, sizeof(AL*));
	if (ptr == NULL) {
		exit(EXIT_FAILURE);
	}
	printf("��������Ҫ���ҵ���Ϣ\n");
	scanf("%s", str);
	static int count;
	count = 1;
	int m = 4;
	for (AL* p = head; p->next != NULL; p = p->next) {
		if (count >= m) {
			m += 4;
			AL** pt = (AL**)realloc(ptr, m * sizeof(AL*));
			if (pt == NULL) {
				exit(EXIT_FAILURE);
			}
			ptr = pt;
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
		for (int i = 1; i < count; ++i) {
			printf("%d\t", i);
			print(ptr[i]->next);
		}
		ptr[0] = (AL*)&count;
		return ptr;
	}
	return NULL;
}
void print(AL* p) {//���
	printf("%s\t%c\t%d\t%s\t\t%s\t\t\n", p->name, p->sex, p->age, p->Add, p->Tel);
}
void allprint(AL* head) {//ȫ�����
	if (head->next == NULL) {
		printf("û����ϵ��\n");
		return;
	}
	printf("���\t����\t�Ա�\t����\t��ַ\t\t�绰\t\t\n");
	int i = 1;
	for (AL* p = head->next; p != NULL; p = p->next, ++i) {
		printf("%d\t", i);
		print(p);
	}
}
int empty(AL* head) {//���
	if (head->next == NULL) {
		return 0;
	}
	for (AL* p = head; p->next != NULL;) {
		del(p);
	}
	return 1;
}
void swap(AL* p, AL* q) {
	AL temp;
	AL* t;
	temp = *p;
	*p = *q;
	*q = temp;
	t = p->next;
	p->next = q->next;
	q->next = t;
}
int sort(AL* head) {
	if (head->next == NULL) {
		return 0;
	}
	for (AL* p = head->next; p != NULL; p = p->next) {
		for (AL* q = p->next; q != NULL; q = q->next) {
			if (strcmp(p->name, q->name) > 0) {
				swap(p, q);
			}
		}
	}
	return 1;
}
int save(AL* head) {
	FILE* fp;//����ָ���ļ������ݵ�ָ�����(��һ���ṹ�����)fp
	char temp[5] = { 0 };
	int choic;
	int n = 0;
	if (head->next == NULL) {
		return -1;
	}
	printf("1.���� 2.����\n������ѡ��\n");
	n = scanf("%d", &choic);
	while (n != 1 || choic < 1 || choic > 2) {
		printf("������������,����������\n");
		while (getchar() != '\n');
		n = scanf("%d", &choic);
	}
	if (choic == 1) {
		if ((fp = fopen("AL.txt", "w+")) == NULL) {//fopen(�ļ���,ʹ�÷�ʽ),�˴�wΪwrite,ֻд.
		//Ӧ����ָ������ļ���ָ��,�ļ��������������ļ�,�Ȳ������ִ������ļ�ʧ���򷵻�NULL
			return 0;//
		}
	}
	else {
		if ((fp = fopen("AL.txt", "a+")) == NULL) {
			return 0;
		}
	}
	for (AL* p = head->next; p != NULL; p = p->next) {
		fputs(p->name, fp);
		fputc(' ', fp);
		fputc(p->sex, fp);
		fputc(' ', fp);
		sprintf(temp, "%d", p->age);
		fputs(temp, fp);
		fputc(' ', fp);
		fputs(p->Add, fp);
		fputc(' ', fp);
		fputs(p->Tel, fp);
		fputc('\n', fp);
	}
	fclose(fp);//�ر�
	return 1;
}
void finput(AL* p, FILE* fp) {
	fscanf(fp, "%s", p->name);
	fgetc(fp);
	fscanf(fp, "%c", &p->sex);
	fscanf(fp, "%d", &p->age);
	fscanf(fp, "%s", p->Add);
	fscanf(fp, "%s", p->Tel);
}
AL* read(AL* temphead) {
	FILE* fp;//����ָ���ļ������ݵ�ָ�����(��һ���ṹ�����)fp
	AL* p = temphead;
	AL* s = NULL;
	if ((fp = fopen("AL.txt", "r+")) == NULL) {//fopen(�ļ���,ʹ�÷�ʽ),�˴�rΪread,ֻд.
		//Ӧ����ָ������ļ���ָ��,�ļ��������򷵻�NULL
		printf("û�б������ϵ���ļ�!\n");
		return p;//
	}
	getc(fp);
	if (feof(fp)) {//����EOF���ط�0
		printf("�ļ�Ϊ��!\n");
		fclose(fp);
		return p;
	}
	while (1) {
		s = (AL*)malloc(sizeof(AL));
		if (s == NULL) {
			exit(EXIT_FAILURE);
		}
		finput(s, fp);
		if (feof(fp)) {//����EOF���ط�0
			break;
		}
		s->next = p->next;
		p->next = s;
		p = p->next;
		p->next = NULL;
	}
	fclose(fp);
	printf("��ȡ�ɹ�!\n");
	return p;
}
void AddressList() {
	int n = 0;
	int choic_1;
	AL** find = NULL;
	int choic_2;
	int choic_3;
	AL* head = (AL*)malloc(sizeof(AL));//ͷ���
	head->next = NULL;
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
			if ((find = allfind(head)) == NULL) {
				printf("δ�ҵ�!\n");
			}
			else {
				printf("��������Ҫɾ����ѡ��\n");
				n = scanf("%d", &choic_2);
				while (n != 1 || choic_2 < 1 || choic_2 > *(int*)find[0] - 1) {
					printf("������������,����������\n");
					while (getchar() != '\n');
					n = scanf("%d", &choic_2);
				}
				del(find[choic_2]);
				free(find);
				find = NULL;
			}
			system("pause");
			system("cls");
			break;
		case �޸�:
			if ((find = allfind(head)) == NULL) {
				printf("δ�ҵ�!\n");
			}
			else {
				printf("��������Ҫ�޸ĵ�ѡ��\n");
				n = scanf("%d", &choic_2);
				while (n != 1 || choic_2 < 1 || choic_2 > *(int*)find[0] - 1) {
					printf("������������,����������\n");
					while (getchar() != '\n');
					n = scanf("%d", &choic_2);
				}
				alter(find[choic_2]);
				free(find);
				find = NULL;
			}
			system("pause");
			system("cls");
			break;
		case ����:
			find = allfind(head);
			free(find);
			find = NULL;
			system("pause");
			system("cls");
			break;
		case ��ʾ:
			allprint(head);
			system("pause");
			system("cls");
			break;
		case ���://ȫ��ɾ��
			if (empty(head)) {
				temphead = head;
				printf("�����\n");
			}
			else {
				printf("��ϵ��Ϊ��\n");
			}
			system("pause");
			system("cls");
			break;
		case ����:
			if (sort(head)) {
				printf("������!\n");
			}
			else {
				printf("��ϵ��Ϊ��!\n");
			}
			system("pause");
			system("cls");
			break;
		case ����:
			n = save(head);
			if (n == 1) {
				printf("����ɹ�!\n");
			}
			else if (n == 0) {
				printf("���ļ��򴴽��ļ�ʧ��!\n");
			}
			else {
				printf("��ϵ��Ϊ��!\n");
			}
			system("pause");
			system("cls");
			break;
		case ��ȡ:
			if (head->next != NULL) {//��������
				printf("��������!\n");
				printf("1.����  2.����\n������ѡ��\n");
				n = scanf("%d", &choic_3);
				while (n != 1 || choic_3 < 1 || choic_3 > 2) {
					printf("������������,����������\n");
					while (getchar() != '\n');
					n = scanf("%d", &choic_3);
				}
				if (choic_3 == 1) {
					temphead = read(head);
				}
				else {
					temphead = read(temphead);
				}
			}
			else {
				temphead = read(head);
			}
			system("pause");
			system("cls");
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