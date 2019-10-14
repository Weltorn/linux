#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init(int* RandNum, int num)
{
	int i;
	for	(i=0;i<num;i++){
	RandNum[i]=(int)(rand()%(1000+1));
	}
	return;
}
void show(int* a, int n)
{
	int i;
	for(i = 0;i<n;i++)
	{		
		printf("%4d : %4d\n",i,a[i]);	
	}
	return;
}
