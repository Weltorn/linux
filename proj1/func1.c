#include "uhead.h"
void urand(int *RandNum,int num)
{
	int i;
	for	(i=0;i<num;i++){
	RandNum[i]=(int)(rand()%(1000+1));
	}
}

void show(int *RandNum, int num)
{
	int i;
	for(i=0;i<num;i++){
		printf("%d\t",RandNum[i]);
    }
	return;
}

int usum(int *RandNum,int num){
    int i,sum=0;
	for(i=0;i<num;i++){
		sum+=RandNum[i];
    }
    return sum;
}
