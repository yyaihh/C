#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 50
void main()
{
	char a[M]=" ";
	printf("请输入需要加密的英文字符串\n");
	fgets(a, M, stdin);
	char* find;
	find = strchr(a, '\n'); //查找换行符
	if (find) {//如果find不为空指针
		*find = '\0';//就把一个空字符放在这里
	}
	for ( int i = 0; i < (int)strlen(a);i++)
	{
		if (a[i] > 64 && a[i] < 91 )//小写字母
		{
			if(a[i]<87)
				a[i]=a[i]+4; 
			else
				a[i] = a[i] - 22;
		}
		if(a[i] > 96 && a[i] < 123)//大写字母
		{
			if (a[i] < 118)
				a[i] = a[i] + 4;
			else
				a[i] = a[i] - 22;
		}
	}
	printf("加密后为:%s\n", a);
	system("pause");

}