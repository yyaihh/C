#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void fun(char str[][80]) {
	int space = 0;
	int capital = 0;
	int lowercase = 0;
	int num = 0;
	int other = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 80; ++j) {
			if (str[i][j] == ' ') {
				space++;
			}
			else if (str[i][j] > 64 && str[i][j] < 91) {
				capital++;
			}
			else if (str[i][j] > 96 && str[i][j] < 123) {
				lowercase++;
			}
			else if (str[i][j] > 47 && str[i][j] < 58) {
				num++;
			}
			else if(str[i][j] != '\0'){
				other++;
			}
		}
	}
	printf("大写字母个数为%d\n小写字母个数为%d\n空格个数为%d\n数字个数为%d\n其他字符个数为%d\n", capital, lowercase, space, num, other);
}
void main() {
	char str[3][80] = { {"Mr.Johnson had never been up in an aerophane before and he had read a lot about"},
						{" air accidents, so one day when a friend offered to take him for a ride in his "},
						{"won small phane, Mr. Johnson was very worried about accepting. Finally, 1234 56"} };
	printf("文章为：\n");
	for (int i = 0; i < 3; ++i) {
		printf("%s", str[i]);
	}
	printf("\n");
	fun(str);
	system("pause");
}
