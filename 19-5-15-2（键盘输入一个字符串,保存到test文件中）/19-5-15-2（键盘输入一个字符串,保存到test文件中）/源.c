#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main() {
	FILE* fp;//����ָ���ļ������ݵ�ָ�����(��һ���ṹ�����)fp
	char ch;
	char filename[20];//�ļ���
	printf("��������Ҫ�������ļ���(���Դ��ļ���׺��)\n");
	scanf("%s", filename);
	if ((fp = fopen(filename, "w")) == NULL) {//fopen(�ļ���,ʹ�÷�ʽ),�˴�wΪwrite,ֻд.
		//Ӧ����ָ������ļ���ָ��,�ļ������ڻ�����򷵻�NULL
		printf("�޷��򿪴��ļ�\n");
		exit(0);//exit��stdlib.h�еı�׼C�⺯��,����������ֹ��������
	}
	ch = getchar();//���ڽ���������������Ļس���(���з�)'\n'
	printf("������һ���ַ���(��!(Ӣ��!)��β):\n");
	while (1) {
		ch = getchar();//�Ӽ��̽���һ���ַ�
		if (ch == '!') {//������Ӣ��!
			break;
		}
		if (ch > 96 && ch < 123) {
			ch = ch - 32;
		}
		fputc(ch, fp);//������ļ�������һ���ַ�
	}
		printf("�������ַ����Ѵ���%s��\n", filename);
		fclose(fp);//�ر��ļ�(ʹָ��fp����ָ������ļ�,��ֹ���û����)
		printf("�ر��ļ�\n");
		system("pause");
}