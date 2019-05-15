#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main() {
	FILE* fp;//定义指向文件型数据的指针变量(是一个结构体变量)fp
	char ch;
	char filename[20];//文件名
	printf("请输入需要创建的文件名(可以带文件后缀名)\n");
	scanf("%s", filename);
	if ((fp = fopen(filename, "w")) == NULL) {//fopen(文件名,使用方式),此处w为write,只写.
		//应返回指向这个文件的指针,文件不存在或出错则返回NULL
		printf("无法打开此文件\n");
		exit(0);//exit是stdlib.h中的标准C库函数,其作用是终止程序运行
	}
	ch = getchar();//用于接收最后键盘上输入的回车符(换行符)'\n'
	printf("请输入一个字符串(以!(英文!)结尾):\n");
	while (1) {
		ch = getchar();//从键盘接受一个字符
		if (ch == '!') {//必须是英文!
			break;
		}
		if (ch > 96 && ch < 123) {
			ch = ch - 32;
		}
		fputc(ch, fp);//向磁盘文件中输入一个字符
	}
		printf("所输入字符串已存入%s中\n", filename);
		fclose(fp);//关闭文件(使指针fp不再指向这个文件,防止误用或出错)
		printf("关闭文件\n");
		system("pause");
}