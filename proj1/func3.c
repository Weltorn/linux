#include "uhead.h"

void mySort(int *array, int num)
{
	int i,j,k,temp;
	for(i = 0; i<num; i++)
	{
		k = i;
		for(j=i; j<num; j++)
		{
			if(array[k]<array[j])
				k=j;
		}
		if(i != k)
		{
			temp = array[k];
			array[k] = array[i];
			array[i] = temp;
		}
	}
	return;
}


int cmpfunc(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void sysSort(int *array, int num)
{
	qsort(array, num, sizeof(int), cmpfunc);
	return;
}
void  writeFile( char* filename, int *array, int num)
{
	int handle;
	if(-1 == (handle = open(filename, O_CREAT|O_TRUNC|O_RDWR, 0777)))
	{
		printf("fail to open file %s\n",filename);
		return;
	}
	write(handle,array,sizeof(int)*num);
	close(handle);
	return;
}

void showFile(char* filename)
{
	int handle,i;
    int array[100];
	if(-1 == (handle = open(filename, O_RDONLY)))
	{
		printf("fail to open file %s\n",filename);
		return;
	}
	if(-1 == read(handle,array,sizeof(int)*100))
	{
		printf("fail to read file %s\n",filename);
		return;
	}
	for(i = 0;i<100;i++)
	{
		printf("%d\t",array[i]);
	}
	close(handle);
	return;
}

















