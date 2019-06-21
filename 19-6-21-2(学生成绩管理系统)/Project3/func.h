#pragma once
#include"student.h"
void Student::Menu() {
	cout << "\t ******************欢迎使用******************\n";
	cout << "\t **************学生成绩管理系统**************\n";
	cout << "\t *------------------------------------------*\n";
	cout << "\t *         1——添加学生信息                *\n";
	cout << "\t *         2——删除学生信息                *\n";
	cout << "\t *         3——修改学生信息                *\n";
	cout << "\t *         4——查找学生信息                *\n";
	cout << "\t *         5——显示学生信息                *\n";
	cout << "\t *         6——清空学生信息                *\n";
	cout << "\t *         7——排序学生信息                *\n";
	cout << "\t *         8——保存学生信息                *\n";
	cout << "\t *         0——退出                        *\n";
	cout << "\t *------------------------------------------*\n";
	cout << "\t 你要输入的编号是（0--8）:\n";
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
	FILE* fp;//定义指向文件型数据的指针变量(是一个结构体变量)fp
	stu* p = head;
	stu* s = NULL;
	if ((fp = fopen("student.txt", "r+")) == NULL) {//fopen(文件名,使用方式),此处r为read,只写.
		//应返回指向这个文件的指针,文件不存在则返回NULL
		cout << "没有本地文件\n";
		return p;//
	}
	getc(fp);
	if (feof(fp)) {//遇见EOF返回非0
		cout << "没有本地数据!\n";
		fclose(fp);
		return p;
	}
	else {
		cout << "本地已有数据是否读入?\n读入请输入1, 其他输入均为不读入\n";
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
		if (feof(fp)) {//遇见EOF返回非0
			break;
		}
		s->next = p->next;
		p->next = s;
		p = p->next;
		p->next = NULL;
	}
	fclose(fp);
	cout << "读取成功!\n";
	return p;
}
void Student::student() {
	int n = 0;
	int choic_1;
	stu** find = NULL;
	int choic_2;
	//int choic_3;
	stu* head = new stu;
	//stu* head = (stu*)malloc(sizeof(stu));//头结点
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
			printf("您的输入有误,请重新输入\n");
			while (getchar() != '\n');
			cin >> choic_1;
		}
		switch (choic_1) {
		case 添加:
			temphead = add(temphead);
			break;
		case 删除:
			if ((find = allfind(head)) == NULL) {
				cout << "未找到!\n";
			}
			else {
				cout << "请输入需要删除的学生的序号\n";
				n = scanf("%d", &choic_2);
				while (n != 1 || choic_2 < 1 || choic_2 > *(int*)find[0] - 1) {
					cout << "您的输入有误,请重新输入\n";
					while (getchar() != '\n');
					n = scanf("%d", &choic_2);
				}
				del(find[choic_2]);
				//free(find);
				delete[]find;
				find = NULL;
				cout << "删除成功!\n";
			}
			system("pause");
			system("cls");
			break;
		case 修改:
			if ((find = allfind(head)) == NULL) {
				cout << "未找到!\n";
			}
			else {
				cout << "请输入需要修改的学生的选项\n";
				n = scanf("%d", &choic_2);
				while (n != 1 || choic_2 < 1 || choic_2 > *(int*)find[0] - 1) {
					cout << "您的输入有误,请重新输入\n";
					while (getchar() != '\n');
					n = scanf("%d", &choic_2);
				}
				alter(find[choic_2]);
				//free(find);
				delete[]find;
				find = NULL;
				cout << "修改成功!\n";
			}
			system("pause");
			system("cls");
			break;
		case 查找:
			find = allfind(head);
			//free(find);
			delete[]find;
			find = NULL;
			system("pause");
			system("cls");
			break;
		case 显示:
			allprint(head);
			system("pause");
			system("cls");
			break;
		case 排序:
			if (sort(head)) {
				cout << "已排序!\n";
			}
			else {
				cout << "联系人为空!\n";
			}
			system("pause");
			system("cls");
			break;
		case 清空://全部删除
			if (empty(head)) {
				temphead = head;
				cout << "已清空\n";
			}
			else {
				cout << "联系人为空\n";
			}
			system("pause");
			system("cls");
			break;
		case 保存:
			n = save(head);
			if (n == 1) {
				cout << "保存成功!\n";
			}
			else if (n == 0) {
				cout << "打开文件或创建文件失败!\n";
			}
			else {
				cout << "联系人为空!\n";
			}
			system("pause");
			system("cls");
			break;
		case 退出:
			cout << "再见!\n";
			system("pause");
			exit(0);
			break;
		default:
			cout << "出错!\n";
			system("pause");
			exit(0);
		}
	}
}
void Student::input(stu* p) {
	int n = 0;
	cout << "请输入学号\n";
	n = scanf("%d", &p->id);
	while (n != 1 || p->id < 0) {
		cout << "您的输入有误,请重新输入\n";
		while (getchar() != '\n');
		n = scanf("%d", &p->id);
	}
	cout << "请输入姓名\n";
	cin >> p->name;
	getchar();
	cout << "请输入性别,男m,女f\n";
	n = scanf("%c", &p->sex);
	while (n != 1 || p->sex != 'm' && p->sex != 'f') {
		cout << "您的输入有误,请重新输入\n";
		while (getchar() != '\n');
		n = scanf("%c", &p->sex);
	}
	cout << "请输入年龄\n";
	n = scanf("%d", &p->age);
	while (n != 1 || p->age <= 0 || p->age > 130) {
		cout << "您的输入有误,请重新输入\n";
		while (getchar() != '\n');
		n = scanf("%d", &p->age);
	}
	cout << "请输入语文成绩\n";
	n = scanf("%lf", &p->chinese);
	while (n != 1 || p->chinese < 0 || p->chinese > 100) {
		cout << "您的输入有误,请重新输入\n";
		while (getchar() != '\n');
		n = scanf("%lf", &p->chinese);
	}
	cout << "请输入数学成绩\n";
	n = scanf("%lf", &p->math);
	while (n != 1 || p->math < 0 || p->math > 100) {
		cout << "您的输入有误,请重新输入\n";
		while (getchar() != '\n');
		n = scanf("%lf", &p->math);
	}
	cout << "请输入英语成绩\n";
	n = scanf("%lf", &p->english);
	while (n != 1 || p->english <= 0 || p->english > 130) {
		cout << "您的输入有误,请重新输入\n";
		while (getchar() != '\n');
		n = scanf("%lf", &p->english);
	}
	p->aver = (p->chinese + p->math + p->english) / 3.0;
	cout << "请输入电话号码\n";
	cin >> p->Tel;
}
void Student::print(stu* p) {
	cout << p->id << "\t" << p->name << "\t" << p->sex << "\t" << p->age << "\t" << p->chinese << "\t" << p->math << "\t" << p->english << "\t" << p->aver << "\t" << p->Tel << endl;
}
void Student::allprint(stu* head) {
	if (head->next == NULL) {
		cout << "没有联系人\n";
		return;
	}
	cout << "学号\t姓名\t性别\t年龄\t语文\t数学\t英语\t平均\t电话\n";
	for (stu* p = head->next; p != NULL; p = p->next) {
		print(p);
	}
}
stu* Student::add(stu* temphead) {//增
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
		cout << "继续输入请输入'y'\n";
		getchar();
		cin >> choic;
	} while (choic == 'y');
	system("cls");
	return p;
}
stu* Student::find_1(stu* p, const char* str) {//按姓名
	if (strstr(p->next->name, str)) {
		return p;
	}
	return NULL;
}
stu* Student::find_2(stu* p, const char* str) {//按年龄
	char temp[5];
	sprintf(temp, "%d", p->next->age);
	if (strstr(temp, str)) {
		return p;
	}
	return NULL;
}
stu* Student::find_3(stu* p, const char* str) {//按成绩/学号
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
stu** Student::allfind(stu* head) {//查
	if (head->next == NULL) {
		cout << "还未添加学生\n";
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
	cout << "请输入需要查找的信息\n";
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
		cout << "序号\t学号\t姓名\t性别\t年龄\t语文\t数学\t英语\t平均\t电话\n";
		for (int i = 1; i < count; ++i) {
			cout << i << "\t";
			print(ptr[i]->next);
		}
		ptr[0] = (stu*)&count;
		return ptr;
	}
	return NULL;
}
void Student::del(stu* p) {//删
	stu* temp;
	temp = p->next;
	p->next = temp->next;
	delete temp;
}
void Student::alter(stu* p) {//改
	input(p->next);
}
int Student::empty(stu* head) {//清空
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
	cout << "1.按学号排序\n2.按姓名排序\n";
	cout << "3.按语文成绩排序\n4.按数学成绩排序\n";
	cout << "5.按英语成绩排序\n6.按平均成绩排序\n";
	n = scanf("%d", &choic);
	while (n != 1 || choic < 1 || choic > 6) {
		cout << "您的输入有误,请重新输入\n";
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
	FILE* fp = NULL;//定义指向文件型数据的指针变量(是一个结构体变量)fp
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
		cout << "1.覆盖 2.并入\n请输入选择\n";
		n = scanf("%d", &choic);
		while (n != 1 || choic < 1 || choic > 2) {
			cout << "您的输入有误,请重新输入\n";
			while (getchar() != '\n');
			n = scanf("%d", &choic);
		}
	}
	if (choic == 1) {
		if ((fp = fopen("student.txt", "w+")) == NULL) {//fopen(文件名,使用方式),此处w为write,只写.
		//应返回指向这个文件的指针,文件不存在则建立新文件,既不存在又创建新文件失败则返回NULL
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
	fclose(fp);//关闭
	return 1;
}