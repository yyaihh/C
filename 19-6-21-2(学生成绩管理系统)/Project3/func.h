#pragma once
#include"student.h"
void Student::Menu() {
	cout << "\t ******************��ӭʹ��******************\n";
	cout << "\t **************ѧ���ɼ�����ϵͳ**************\n";
	cout << "\t *------------------------------------------*\n";
	cout << "\t *         1�������ѧ����Ϣ                *\n";
	cout << "\t *         2����ɾ��ѧ����Ϣ                *\n";
	cout << "\t *         3�����޸�ѧ����Ϣ                *\n";
	cout << "\t *         4��������ѧ����Ϣ                *\n";
	cout << "\t *         5������ʾѧ����Ϣ                *\n";
	cout << "\t *         6�������ѧ����Ϣ                *\n";
	cout << "\t *         7��������ѧ����Ϣ                *\n";
	cout << "\t *         8��������ѧ����Ϣ                *\n";
	cout << "\t *         0�����˳�                        *\n";
	cout << "\t *------------------------------------------*\n";
	cout << "\t ��Ҫ����ı���ǣ�0--8��:\n";
}
void Student::finput(stu* p, FILE* fp) {
	fscanf(fp, "%d", &p->id);
	fscanf(fp, "%s", p->name);
	fgetc(fp);
	fscanf(fp, "%c", &p->sex);
	fscanf(fp, "%d", &p->age);
	fscanf(fp, "%lf", &p->chinese);
	fscanf(fp, "%lf", &p->math);
	fscanf(fp, "%lf", &p->english);
	fscanf(fp, "%lf", &p->aver);
	fscanf(fp, "%s", p->Tel);
}
stu* Student::Init(stu* head) {
	int choic;
	FILE* fp;//����ָ���ļ������ݵ�ָ�����(��һ���ṹ�����)fp
	stu* p = head;
	stu* s = NULL;
	if ((fp = fopen("student.txt", "r+")) == NULL) {//fopen(�ļ���,ʹ�÷�ʽ),�˴�rΪread,ֻд.
		//Ӧ����ָ������ļ���ָ��,�ļ��������򷵻�NULL
		cout << "û�б����ļ�\n";
		return p;//
	}
	getc(fp);
	if (feof(fp)) {//����EOF���ط�0
		cout << "û�б�������!\n";
		fclose(fp);
		return p;
	}
	else {
		cout << "�������������Ƿ����?\n����������1, ���������Ϊ������\n";
		cin >> choic;
		if (choic != 1) {
			return p;
		}
	}
	while (1) {
		//s = (stu*)malloc(sizeof(stu));
		s = new stu;
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
	cout << "��ȡ�ɹ�!\n";
	return p;
}
void Student::student() {
	int n = 0;
	int choic_1;
	stu** find = NULL;
	int choic_2;
	//int choic_3;
	stu* head = new stu;
	//stu* head = (stu*)malloc(sizeof(stu));//ͷ���
	head->next = NULL;
	if (head == NULL) {
		exit(EXIT_FAILURE);
	}
	stu* temphead = head;
	Menu();
	temphead = Init(head);
	system("pause");
	system("cls");
	while (1) {
		Menu();
		cin >> choic_1;
		while (choic_1 < 0 || choic_1 > 8) {
			printf("������������,����������\n");
			while (getchar() != '\n');
			cin >> choic_1;
		}
		switch (choic_1) {
		case ���:
			temphead = add(temphead);
			break;
		case ɾ��:
			if ((find = allfind(head)) == NULL) {
				cout << "δ�ҵ�!\n";
			}
			else {
				cout << "��������Ҫɾ����ѧ�������\n";
				n = scanf("%d", &choic_2);
				while (n != 1 || choic_2 < 1 || choic_2 > *(int*)find[0] - 1) {
					cout << "������������,����������\n";
					while (getchar() != '\n');
					n = scanf("%d", &choic_2);
				}
				del(find[choic_2]);
				//free(find);
				delete[]find;
				find = NULL;
				cout << "ɾ���ɹ�!\n";
			}
			system("pause");
			system("cls");
			break;
		case �޸�:
			if ((find = allfind(head)) == NULL) {
				cout << "δ�ҵ�!\n";
			}
			else {
				cout << "��������Ҫ�޸ĵ�ѧ����ѡ��\n";
				n = scanf("%d", &choic_2);
				while (n != 1 || choic_2 < 1 || choic_2 > *(int*)find[0] - 1) {
					cout << "������������,����������\n";
					while (getchar() != '\n');
					n = scanf("%d", &choic_2);
				}
				alter(find[choic_2]);
				//free(find);
				delete[]find;
				find = NULL;
				cout << "�޸ĳɹ�!\n";
			}
			system("pause");
			system("cls");
			break;
		case ����:
			find = allfind(head);
			//free(find);
			delete[]find;
			find = NULL;
			system("pause");
			system("cls");
			break;
		case ��ʾ:
			allprint(head);
			system("pause");
			system("cls");
			break;
		case ����:
			if (sort(head)) {
				cout << "������!\n";
			}
			else {
				cout << "��ϵ��Ϊ��!\n";
			}
			system("pause");
			system("cls");
			break;
		case ���://ȫ��ɾ��
			if (empty(head)) {
				temphead = head;
				cout << "�����\n";
			}
			else {
				cout << "��ϵ��Ϊ��\n";
			}
			system("pause");
			system("cls");
			break;
		case ����:
			n = save(head);
			if (n == 1) {
				cout << "����ɹ�!\n";
			}
			else if (n == 0) {
				cout << "���ļ��򴴽��ļ�ʧ��!\n";
			}
			else {
				cout << "��ϵ��Ϊ��!\n";
			}
			system("pause");
			system("cls");
			break;
		case �˳�:
			cout << "�ټ�!\n";
			system("pause");
			exit(0);
			break;
		default:
			cout << "����!\n";
			system("pause");
			exit(0);
		}
	}
}
void Student::input(stu* p) {
	int n = 0;
	cout << "������ѧ��\n";
	n = scanf("%d", &p->id);
	while (n != 1 || p->id < 0) {
		cout << "������������,����������\n";
		while (getchar() != '\n');
		n = scanf("%d", &p->id);
	}
	cout << "����������\n";
	cin >> p->name;
	getchar();
	cout << "�������Ա�,��m,Ůf\n";
	n = scanf("%c", &p->sex);
	while (n != 1 || p->sex != 'm' && p->sex != 'f') {
		cout << "������������,����������\n";
		while (getchar() != '\n');
		n = scanf("%c", &p->sex);
	}
	cout << "����������\n";
	n = scanf("%d", &p->age);
	while (n != 1 || p->age <= 0 || p->age > 130) {
		cout << "������������,����������\n";
		while (getchar() != '\n');
		n = scanf("%d", &p->age);
	}
	cout << "���������ĳɼ�\n";
	n = scanf("%lf", &p->chinese);
	while (n != 1 || p->chinese < 0 || p->chinese > 100) {
		cout << "������������,����������\n";
		while (getchar() != '\n');
		n = scanf("%lf", &p->chinese);
	}
	cout << "��������ѧ�ɼ�\n";
	n = scanf("%lf", &p->math);
	while (n != 1 || p->math < 0 || p->math > 100) {
		cout << "������������,����������\n";
		while (getchar() != '\n');
		n = scanf("%lf", &p->math);
	}
	cout << "������Ӣ��ɼ�\n";
	n = scanf("%lf", &p->english);
	while (n != 1 || p->english <= 0 || p->english > 130) {
		cout << "������������,����������\n";
		while (getchar() != '\n');
		n = scanf("%lf", &p->english);
	}
	p->aver = (p->chinese + p->math + p->english) / 3.0;
	cout << "������绰����\n";
	cin >> p->Tel;
}
void Student::print(stu* p) {
	cout << p->id << "\t" << p->name << "\t" << p->sex << "\t" << p->age << "\t" << p->chinese << "\t" << p->math << "\t" << p->english << "\t" << p->aver << "\t" << p->Tel << endl;
}
void Student::allprint(stu* head) {
	if (head->next == NULL) {
		cout << "û����ϵ��\n";
		return;
	}
	cout << "ѧ��\t����\t�Ա�\t����\t����\t��ѧ\tӢ��\tƽ��\t�绰\n";
	for (stu* p = head->next; p != NULL; p = p->next) {
		print(p);
	}
}
stu* Student::add(stu* temphead) {//��
	int n = 0;
	stu* p = temphead;
	stu* s = NULL;
	char choic;
	do {
		//s = (stu*)malloc(sizeof(stu));
		s = new stu;
		if (s == NULL) {
			exit(EXIT_FAILURE);
		}
		input(s);
		s->next = p->next;
		p->next = s;
		p = p->next;
		p->next = NULL;
		cout << "��������������'y'\n";
		getchar();
		cin >> choic;
	} while (choic == 'y');
	system("cls");
	return p;
}
stu* Student::find_1(stu* p, const char* str) {//������
	if (strstr(p->next->name, str)) {
		return p;
	}
	return NULL;
}
stu* Student::find_2(stu* p, const char* str) {//������
	char temp[5];
	sprintf(temp, "%d", p->next->age);
	if (strstr(temp, str)) {
		return p;
	}
	return NULL;
}
stu* Student::find_3(stu* p, const char* str) {//���ɼ�/ѧ��
	char temp0[5];
	sprintf(temp0, "%d", p->next->id);
	if (temp0 == str) {
		return p;
	}
	char temp1[5];
	sprintf(temp1, "%d", p->next->age);
	if (strstr(temp1, str)) {
		return p;
	}
	char temp2[5];
	sprintf(temp2, "%d", p->next->age);
	if (strstr(temp2, str)) {
		return p;
	}
	char temp3[5];
	sprintf(temp3, "%d", p->next->age);
	if (strstr(temp3, str)) {
		return p;
	}
	char temp4[5];
	sprintf(temp4, "%d", p->next->age);
	if (strstr(temp4, str)) {
		return p;
	}
	return NULL;
}
stu** Student::allfind(stu* head) {//��
	if (head->next == NULL) {
		cout << "��δ���ѧ��\n";
		return NULL;
	}
	char str[100] = { 0 };
	stu* find = NULL;
	stu** ptr = NULL;
	//ptr = (stu**)calloc(4, sizeof(stu*));
	ptr = new stu*[4];
	if (ptr == NULL) {
		exit(EXIT_FAILURE);
	}
	cout << "��������Ҫ���ҵ���Ϣ\n";
	scanf("%s", str);
	static int count;
	count = 1;
	int m = 4;
	for (stu* p = head; p->next != NULL; p = p->next) {
		if (count >= m) {
			m += 4;
			//stu** pt = (stu**)realloc(ptr, m * sizeof(stu*));
			stu** pt = new stu*[m];
			if (pt == NULL) {
				exit(EXIT_FAILURE);
			}
			for (int i = 0; i < m - 4; ++i) {
				pt[i] = ptr[i];
			}
			delete []ptr;
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
	}
	if (count != 1) {
		cout << "���\tѧ��\t����\t�Ա�\t����\t����\t��ѧ\tӢ��\tƽ��\t�绰\n";
		for (int i = 1; i < count; ++i) {
			cout << i << "\t";
			print(ptr[i]->next);
		}
		ptr[0] = (stu*)&count;
		return ptr;
	}
	return NULL;
}
void Student::del(stu* p) {//ɾ
	stu* temp;
	temp = p->next;
	p->next = temp->next;
	delete temp;
}
void Student::alter(stu* p) {//��
	input(p->next);
}
int Student::empty(stu* head) {//���
	if (head->next == NULL) {
		return 0;
	}
	for (stu* p = head; p->next != NULL;) {
		del(p);
	}
	return 1;
}
void Student::swap(stu* p, stu* q) {
	stu temp;
	stu* t;
	temp = *p;
	*p = *q;
	*q = temp;
	t = p->next;
	p->next = q->next;
	q->next = t;
}
int Student::sort(stu* head) {
	if (head->next == NULL) {
		return 0;
	}
	int choic, n;
	cout << "1.��ѧ������\n2.����������\n";
	cout << "3.�����ĳɼ�����\n4.����ѧ�ɼ�����\n";
	cout << "5.��Ӣ��ɼ�����\n6.��ƽ���ɼ�����\n";
	n = scanf("%d", &choic);
	while (n != 1 || choic < 1 || choic > 6) {
		cout << "������������,����������\n";
		while (getchar() != '\n');
		n = scanf("%d", &choic);
	}
	if (choic == 2) {
		for (stu* p = head->next; p != NULL; p = p->next) {
			for (stu* q = p->next; q != NULL; q = q->next) {
				if (strcmp(p->name, q->name) > 0) {
					swap(p, q);
				}
			}
		}
	}
	else {
		for (stu* p = head->next; p != NULL; p = p->next) {
			for (stu* q = p->next; q != NULL; q = q->next) {
				if (choic == 1 && (p->id > q->id)) {
					swap(p, q);
				}
				else if (choic == 3 && (p->chinese > q->chinese)) {
					swap(p, q);
				}
				else if (choic == 4 && (p->math > q->math)) {
					swap(p, q);
				}
				else if (choic == 5 && (p->english > q->english)) {
					swap(p, q);
				}
				else if (choic == 6 && (p->aver > q->aver)) {
					swap(p, q);
				}
			}
		}
	}
	return 1;
}
int Student::save(stu* head) {
	FILE* fp = NULL;//����ָ���ļ������ݵ�ָ�����(��һ���ṹ�����)fp
	char temp[5] = { 0 };
	int choic = 0;
	int n = 0;
	if (head->next == NULL) {
		return -1;
	}
	if ((fp = fopen("student.txt", "r")) == NULL) {
		choic = 1;
	}
	else {
		fseek(fp, 0, 2);
		n = ftell(fp);
		rewind(fp);
	}
	if(n != 0) {
		cout << "1.���� 2.����\n������ѡ��\n";
		n = scanf("%d", &choic);
		while (n != 1 || choic < 1 || choic > 2) {
			cout << "������������,����������\n";
			while (getchar() != '\n');
			n = scanf("%d", &choic);
		}
	}
	if (choic == 1) {
		if ((fp = fopen("student.txt", "w+")) == NULL) {//fopen(�ļ���,ʹ�÷�ʽ),�˴�wΪwrite,ֻд.
		//Ӧ����ָ������ļ���ָ��,�ļ��������������ļ�,�Ȳ������ִ������ļ�ʧ���򷵻�NULL
			return 0;//
		}
	}
	else {
		if ((fp = fopen("student.txt", "a+")) == NULL) {
			return 0;
		}
	}
	for (stu* p = head->next; p != NULL; p = p->next) {
		fprintf(fp, "%d ", p->id);
		fprintf(fp, "%s ", p->name);
		fprintf(fp, "%c ", p->sex);
		fprintf(fp, "%d ", p->age);
		fprintf(fp, "%f ", p->chinese);
		fprintf(fp, "%f ", p->math);
		fprintf(fp, "%f ", p->english);
		fprintf(fp, "%f ", p->aver);
		fprintf(fp, "%s\n", p->Tel);
	}
	fclose(fp);//�ر�
	return 1;
}