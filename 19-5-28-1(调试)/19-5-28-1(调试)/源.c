#if 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c }; 
	char*** cpp = cp;
	printf("%s\n", **++cpp); 
	printf("%s\n", *--*++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);
	system("pause");
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char* a[] = { "work","at","alibaba" }; 
	char** pa = a;
	pa++;
	printf("%s\n", *pa);//at
	system("pause");
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int	*ptr1 = (int*)(&aa + 1); 
	int	*ptr2 = (int*)(*(aa + 1));
	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));//10,5
	system("pause");
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
	int *p;
	p = a[1];
	int b = ("xaUxuBixaBIUXbIU", 5);
	printf("%d\n", b);
	printf("%d\n", p[0]);
	system("pause");
	return 0;
}
#endif
#if 1
#include<stdio.h>
#include<stdlib.h>
int main(){	
	char* str[] = { "welcome","to","Fortemedia","Nanjing" };
	char** p = str + 1;
	str[0] = (*p++) + 2;
	str[1] = *(p + 1);
	str[2] = p[1] + 3;
	str[3] = p[0] + (str[2] - str[1]);
	printf("%s\n", str[0]);//\n
	printf("%s\n", str[1]);//Nanjing
	printf("%s\n", str[2]);//jing
	printf("%s\n", str[3]);//g
	system("pause");
	return 0;
}
#endif