#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* output_long(char str[]) {
	static char s[1024];
	int right;//记录当前遍历的单词末尾字母的下标
	int count1 = 0;//记录当前遍历到的单词长度
	int count2 = 0;//记录遍历过的所有单词中最长的长度
	for (int i = 0; i < (int)strlen(str); ++i) {
		if (str[i] >= 'a'&&str[i] <= 'z' || str[i] >= 'A'&&str[i] <= 'Z')  {
			++count1;
			continue;
		}
		if (count1 > count2) {
			count2 = count1;
			right = i;
		}
		count1 = 0;//未跳出循环则说明上一个单词遍历结束，count1置0，便于记录下一个单词的长度
	}
	for (int i = 0; i < count2; ++i) {
		s[i] = str[i + right - count2];
	}
	return s;
}
void main() {
	char str[1024] = "I enjoy reading ,different kinds of books, but 'Harry Porter' is my favorite one.";
	printf("字符串为:%s\n", str);
	printf("字符串中最长的单词为:%s\n", output_long(str));
	system("pause");
}