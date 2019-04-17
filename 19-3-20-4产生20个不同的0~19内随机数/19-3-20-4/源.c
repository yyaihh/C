#include  <stdlib.h>
#include  <stdio.h>
#include<time.h>
#define   N  20
void  fun(int  *a){
	int  i, x, n = 0;
	srand((unsigned int)time(0));
	x = rand() % 20;
	while (n < 20){
			for (i = 0; i < n; i++)
				if (x == a[i])
					break;
			if (i == n){
				a[n] = x;
				n++;
			}
			x = rand() % 20;
	}
}
void main()
{
	int  x[N] = { 0 }, i;
	fun(x);
	printf("The result :  \n");
	for (i = 0; i < N; i++)
	{
		printf("%4d", x[i]);
		if ((i + 1) % 5 == 0)printf("\n");
	}
	printf("\n\n");
	system("pause");
}
