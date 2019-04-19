#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void output_vowel(char str1[], char str2[]) {
	for (int i = 0, j = 0;; ++i) {
		while (j <= (int)strlen(str1)) {
			j++;
			if (str1[j] == 'a' || str1[j] == 'o' || str1[j] == 'e' || str1[j] == 'i' || str1[j] == 'u') {
				str2[i] = str1[j];
				break;
			}
		}
		if (str1[j] == '\0') {
			break;
		}
	}
}
int main() {
	char str1[1024] = "srvafesosefefsiusfadubtevioacj";
	char str2[1024] = { 0 };
	printf("Ô­×Ö·û´®Îª:%s\n",str1);
	output_vowel(str1, str2);
	printf("ÔªÒô×Ö·û´®Îª:%s\n", str2);
	system("pause");
	return 0;
}