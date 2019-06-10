#pragma once
#include"AddressList.h"
int Menu() {//菜单
	int choic;
	int n = 0;
	printf("1.添加联系人 2.删除联系人\n"
		"3.修改联系人信息 4.查找联系人\n"
		"5.显示所有联系人 6.清空所有联系人\n"
		"7.按名称排序 8.保存到文件\n"
		"9.从文件中读取联系人 0.退出\n"
		"请输入您的选项!\n");
	//for (n = scanf("%d", &choic); n != 1 || choic < 0 || choic > 9; printf("您的输入有误,请重新输入"), n = scanf("%d", &choic));
	n = scanf("%d", &choic);
	while(n != 1 || choic < 0 || choic > 9) {
		printf("您的输入有误,请重新输入\n");
		while (getchar() != '\n');
		n = scanf("%d", &choic);
	}
	return choic;
}
void input(AL* p) {
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
	char str[50] = { 0 };
	AL* find = NULL;
	AL** ptr = NULL;
	ptr = (AL**)calloc(5, sizeof(AL*));
	printf("请输入需要查找的信息\n");
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
		printf("序号\t姓名\t性别\t年龄\t地址\t\t电话\t\t\n");
		for (int i = 0; i < count; ++i) {
			printf("%d\t", i + 1);
			print(ptr[i]);
		}
	}
	return ptr;
}

void print(AL* p) {//输出
	printf("%s\t%c\t%d\t%s\t\t%s\t\t\n", p->name, p->sex, p->age, p->Add, p->Tel);
}
void allprint(AL* head) {//全部输出
	printf("序号\t姓名\t性别\t年龄\t地址\t\t电话\t\t\n");
	int i = 1;
	for (AL* p = head->next; p != NULL; p = p->next, ++i) {
		printf("%d\t", i);
		print(p);
	}
}
int empty() {//清空

}
int sort(AL* head) {

}
int fun() {
	int choic_1;
	AL** find;
	int choic_2;
	AL* head = (AL*)malloc(sizeof(AL));//头结点
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
			find = allfind(head);
			printf("请输入需要删除的选项\n");
			scanf("%d", &choic_2);
			del(find[choic_2 - 1]);
			free(find);
			find = NULL;
			break;
		case 修改:
			find = allfind(head);
			printf("请输入需要修改的选项\n");
			scanf("%d", &choic_2);
			alter(find[choic_2 - 1]);
			free(find);
			find = NULL;
			break;
		case 查找:
			find = allfind(head);
			free(find);
			find = NULL;
			break;
		case 显示:
			allprint(head);
			break;
		case 清空:
			break;
		case 排序:
			break;
		case 保存:
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