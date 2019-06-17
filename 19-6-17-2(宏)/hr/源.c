#include<stdio.h>
#include<stdlib.h>
#define M(a,b) ((a)*(b))
#define S (365UL*24*60*60*60*60*60*60)
#define PRINT(FORMAT, VALUE)\
printf("" #VALUE " = "FORMAT "\n", VALUE)
int main() {
	int i = 4;
	PRINT("%d", i + 5);
	system("pause");
	return 0;
}