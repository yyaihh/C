#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* output_long(char str[]) {
	static char s[1024];
	int right;//��¼��ǰ�����ĵ���ĩβ��ĸ���±�
	int count1 = 0;//��¼��ǰ�������ĵ��ʳ���
	int count2 = 0;//��¼�����������е�������ĳ���
	for (int i = 0; i < (int)strlen(str); ++i) {
		if (str[i] >= 'a'&&str[i] <= 'z' || str[i] >= 'A'&&str[i] <= 'Z')  {
			++count1;
			continue;
		}
		if (count1 > count2) {
			count2 = count1;
			right = i;
		}
		count1 = 0;//δ����ѭ����˵����һ�����ʱ���������count1��0�����ڼ�¼��һ�����ʵĳ���
	}
	for (int i = 0; i < count2; ++i) {
		s[i] = str[i + right - count2];
	}
	return s;
}
void main() {
	char str[1024] = "I enjoy reading ,different kinds of books, but 'Harry Porter' is my favorite one.";
	printf("�ַ���Ϊ:%s\n", str);
	printf("�ַ�������ĵ���Ϊ:%s\n", output_long(str));
	system("pause");
}