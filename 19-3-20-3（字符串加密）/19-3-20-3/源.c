#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 50
void main()
{
	char a[M]=" ";
	printf("��������Ҫ���ܵ�Ӣ���ַ���\n");
	fgets(a, M, stdin);
	char* find;
	find = strchr(a, '\n'); //���һ��з�
	if (find) {//���find��Ϊ��ָ��
		*find = '\0';//�Ͱ�һ�����ַ���������
	}
	for ( int i = 0; i < (int)strlen(a);i++)
	{
		if (a[i] > 64 && a[i] < 91 )//Сд��ĸ
		{
			if(a[i]<87)
				a[i]=a[i]+4; 
			else
				a[i] = a[i] - 22;
		}
		if(a[i] > 96 && a[i] < 123)//��д��ĸ
		{
			if (a[i] < 118)
				a[i] = a[i] + 4;
			else
				a[i] = a[i] - 22;
		}
	}
	printf("���ܺ�Ϊ:%s\n", a);
	system("pause");

}