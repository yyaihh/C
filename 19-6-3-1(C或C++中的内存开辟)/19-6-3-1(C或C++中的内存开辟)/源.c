#include<stdio.h>
#include<stdlib.h>
int g_num1      = 1;
static s_g_num2 = 2;
int main() {
	static int num3 = 3;
	int num4    = 4;
	int arr[]   = { 1,2,3,4 };
	char str1[] = "abcde";
	char* pstr  = "abcde";
	int* ptr1   = (int*)malloc(num4 * sizeof(int));
	int* ptr2   = (int*)calloc(num4, sizeof(int));
	int* ptr3   = (int*)realloc(ptr1, num4 * sizeof(int));
	//free(ptr1);//²»ÐèÒª
	free(ptr2);
	free(ptr3);
	system("pause");
	return 0;
}