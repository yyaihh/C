#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 20
int fun()
{
	int i,j = 0;
	char str1[M];
	char str2[M]=" ";
	char* find;
	printf("请输入一串字符\n");
	fgets(str1, M + 1 , stdin);
	find = strchr(str1, '\n'); //查找换行符
	if (find) {//如果find不为空指针
		*find = '\0';//就把一个空字符放在这里
	}             
	for (i = 0; i < M; ++i)
	{
		if (str1[i] < 'a')
		{
			str2[j] = str1[i];
			j++;
		}
	}
	printf("ASCII码小于97的字符组成的字符串为%s\n", str2);

	return strlen(str2);
}
void main()
{
	printf("ASCII码小于97的字符数为：%d\n", fun());
	system("pause");
}
