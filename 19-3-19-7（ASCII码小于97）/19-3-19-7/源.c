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
	printf("������һ���ַ�\n");
	fgets(str1, M + 1 , stdin);
	find = strchr(str1, '\n'); //���һ��з�
	if (find) {//���find��Ϊ��ָ��
		*find = '\0';//�Ͱ�һ�����ַ���������
	}             
	for (i = 0; i < M; ++i)
	{
		if (str1[i] < 'a')
		{
			str2[j] = str1[i];
			j++;
		}
	}
	printf("ASCII��С��97���ַ���ɵ��ַ���Ϊ%s\n", str2);

	return strlen(str2);
}
void main()
{
	printf("ASCII��С��97���ַ���Ϊ��%d\n", fun());
	system("pause");
}
