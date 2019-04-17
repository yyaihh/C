#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0;
	for(int i = 1; i <= 100; i++)
		a = a + i;
	printf("1+2+3...+100µÈÓÚ%d\n", a);
	system("pause");
	return 0;
}