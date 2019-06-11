#pragma once
#include"AddressList.h"
int Menu() {//菜单
	int choic;
	int n = 0;
	printf("1.添加联系人         2.删除联系人\n"
		   "3.修改联系人信息     4.查找联系人\n"
		   "5.显示所有联系人     6.清空所有联系人\n"
		   "7.按名称排序         8.保存到文件\n"
		   "9.从文件中读取联系人 0.退出\n"
		   "请输入您的选项!\n");
	n = scanf("%d", &choic);
	while(n != 1 || choic < 0 || choic > 9) {
		printf("您的输入有误,请重新输入\n");
		while (getchar() != '\n');
		n = scanf("%d", &choic);
	}
	return choic;
}
void input(AL* p) {
	++num;
	int n = 0;
	printf("请输入姓名\n");
	scanf("%s", p->name);
	getchar();
	printf("请输入性别,男m,女f\n");
	n = scanf("%c", &p->sex);
	while (n != 1 || p->sex != 'm' && p->sex != 'f') {
		printf("您的输入有误,请重新输入\n");
		while (getchar() != '\n');
		n = scanf("%c", &p->sex);
	}
	printf("请输入年龄\n");
	n = scanf("%d", &p->age);
	while (n != 1 || p->age < 0 || p->age > 130) {
		printf("您的输入有误,请重新输入\n");
		while (getchar() != '\n');
		n = scanf("%d", &p->age);
	}
	printf("请输入地址\n");
	scanf("%s", p->Add);
	printf("请输入电话号码\n");
	scanf("%s", p->Tel);
}
AL* add(AL* temphead) {//增
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
		printf("继续输入请输入'y'\n");
		getchar();
		n = scanf("%c", &choic);
		while (n != 1 ) {
			printf("您的输入有误,请重新输入\n");
			while (getchar() != '\n');
			n = scanf("%c", &choic);
		}
	} while (choic == 'y');
	system("cls");
	return p;
}
void del(AL* p) {//删
	--num;
	AL* temp;
	temp = p->next;
	p->next = temp->next;
	free(temp);
}
int alter(AL* p) {//改
	input(p->next);
}
AL* find_1(AL* p, const char* str) {//按姓名找
	if (strstr(p->next->name, str)) {
		return p;
	}
	return NULL;
}
AL* find_2(AL* p, const char* str) {//按年龄找
	char temp[5];
	sprintf(temp, "%d", p->next->age);
	if (strstr(temp, str)) {
		return p;
	}
	return NULL;
}
AL* find_3(AL* p, const char* str) {//按电话号码找
	if (strstr(p->next->Tel, str)) {
		return p;
	}
	return NULL;
}
AL* find_4(AL* p, const char* str) {//按地址找
	if (strstr(p->next->Add, str)) {
		return p;
	}
	return NULL;
}
AL** allfind(AL* head) {//查
	if (head->next == NULL) {
		printf("还未添加联系人\n");
		return NULL;
	}
	char str[100] = { 0 };
	AL* find = NULL;
	AL** ptr = NULL;
	ptr = (AL**)calloc(4, sizeof(AL*));
	if (ptr == NULL) {
		exit(EXIT_FAILURE);
	}
	printf("请输入需要查找的信息\n");
	scanf("%s", str);
	static int count;
	count = 1;
	int m = 4;
	for (AL* p = head; p->next!= NULL; p = p->next) {
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
		printf("序号\t姓名\t性别\t年龄\t地址\t\t电话\t\t\n");
		for (int i = 1; i < count; ++i) {
			printf("%d\t", i);
			print(ptr[i]->next);
		}
		ptr[0] = (AL*)&count;
		return ptr;
	}
	return NULL;
}
void print(AL* p) {//输出
	printf("%s\t%c\t%d\t%s\t\t%s\t\t\n", p->name, p->sex, p->age, p->Add, p->Tel);
}
void allprint(AL* head) {//全部输出
	if (head->next == NULL) {
		printf("没有联系人\n");
		return;
	}
	printf("序号\t姓名\t性别\t年龄\t地址\t\t电话\t\t\n");
	int i = 1;
	for (AL* p = head->next; p != NULL; p = p->next, ++i) {
		printf("%d\t", i);
		print(p);
	}
}
int empty(AL* head) {//清空
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
	if (head->next == NULL) {
		return -1;
	}
	FILE* fp;//定义指向文件型数据的指针变量(是一个结构体变量)fp
	char temp[5] = { 0 };
	if ((fp = fopen("AL.txt", "w+")) == NULL) {//fopen(文件名,使用方式),此处w为write,只写.
		//应返回指向这个文件的指针,文件不存在则建立新文件,既不存在又创建新文件失败则返回NULL
		return 0;//
	}
	for (AL* p = head->next; p != NULL; p = p->next) {
		fputs(p->name,fp);
		fputc('\0', fp);
		fputc(p->sex, fp);
		fputc('\0', fp);
		sprintf(temp, "%d", p->age);
		fputc('\0', fp);
		fputs(temp, fp);
		fputc('\0', fp);
		fputs(p->Add, fp);
		fputc('\0', fp);
		fputs(p->Tel, fp);
		fputc('\n', fp);
	}
	fclose(fp);//关闭
	return 1;
}
void finput(AL* p,FILE* fp) {
	char temp[5];
	fgets(p->name, 50, fp);
	//fgetc(fp, p->sex);
	fgets(temp, 5, fp);
	//sprintf(p->age, "%s", temp);
	fgets(p->Add, 100, fp);
	fgets(p->Tel, 20, fp);
}
int read(AL* head) {
	FILE* fp;//定义指向文件型数据的指针变量(是一个结构体变量)fp
	if ((fp = fopen("AL.txt", "r+")) == NULL) {//fopen(文件名,使用方式),此处w为write,只写.
		//应返回指向这个文件的指针,文件不存在则返回NULL
		return 0;//
	}
	finput(head->next, fp);

}
void AddressList() {
	int n = 0;
	int choic_1;
	AL** find = NULL;
	int choic_2;
	AL* head = (AL*)malloc(sizeof(AL));//头结点
	head->next = NULL;
	if (head == NULL) {
		exit(EXIT_FAILURE);
	}
	AL* temphead = head;
	while (1) {
		choic_1 = Menu();
		switch (choic_1) {
		case 添加:
			temphead = add(temphead);
			break;
		case 删除:
			if ((find = allfind(head)) == NULL) {
				printf("未找到!\n");
			}
			else {
				printf("请输入需要删除的选项\n");
				n = scanf("%d", &choic_2);
				while (n != 1 || choic_2 < 1 || choic_2 > *(int*)find[0] - 1) {
					printf("您的输入有误,请重新输入\n");
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
		case 修改:
			if ((find = allfind(head)) == NULL) {
				printf("未找到!\n");
			}
			else {
				printf("请输入需要修改的选项\n");
				n = scanf("%d", &choic_2);
				while (n != 1 || choic_2 < 1 || choic_2 > *(int*)find[0] - 1) {
					printf("您的输入有误,请重新输入\n");
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
		case 查找:
			find = allfind(head);
			free(find);
			find = NULL;
			system("pause");
			system("cls");
			break;
		case 显示:
			allprint(head);
			system("pause");
			system("cls");
			break;
		case 清空://全部删除
			if (empty(head)) {
				temphead = head;
				printf("已清空\n");
			}
			else {
				printf("联系人为空\n");
			}
			system("pause");
			system("cls");
			break;
		case 排序:
			if (sort(head)) {
				printf("已排序!\n");
			}
			else {
				printf("联系人为空!\n");
			}
			system("pause");
			system("cls");
			break;
		case 保存:
			n = save(head);
			if (n == 1) {
				printf("保存成功!\n");
			}
			else if (n == 0) {
				printf("打开文件或创建文件失败!\n");
			}
			else {
				printf("联系人为空!\n");
			}
			system("pause");
			system("cls");
			break;
		case 读取:
			break;
		case 退出:
			printf("再见!\n");
			system("pause");
			exit(0);
			break;
		default:
			printf("出错!\n");
			system("pause");
			exit(0);
		}
	}
}