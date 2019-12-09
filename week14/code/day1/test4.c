#include <stdio.h>
#include<signal.h>
#include<wait.h>
#include<string.h>
#include <pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>
#include<time.h>

#define RAND_NUM 100

int a[RAND_NUM],b[RAND_NUM];
void max(void *t)
{
	clock_t start, finish;  
   	double  duration;  
	pthread_t my_tid;
	int* s = t;
 	start = clock();  
  
	for(int i = 0;i<RAND_NUM;i++)
	{
		if(((int*)t)[i]>*s)s =&((int*)t)[i];
	}
	my_tid=pthread_self();
	printf("\tthread %d:my tid is %lx,hello world\n",(int)y->no,my_tid);
	finish = clock();  
	duration = (double)(finish - start) / CLOCKS_PER_SEC;  
	pthread_exit((void*)s);
}

int main()
{
	pthread_t tid1,tid2;
	int rv,t;
	for(int i = 0;i<RAND_NUM;i++)
	{
		a[i]=rand()%100+1;
	}
	for(int i = 0;i<RAND_NUM;i++)
	{
		b[i]=rand()%100+1;
	}
	rv = pthread_create(&tid1,NULL,(void*(*)())max,(void*)a);
	if(rv!=0)
	{
		printf("thread1 create failed!\n");
		return -1;
	}
	else
		printf("thread1 create %lx!\n",tid1);

	rv = pthread_create(&tid2,NULL,(void*(*)())max,(void*)b);
	if(rv!=0)
	{
		printf("thread2 create failed!\n");
		return -1;
	}
	else
		printf("thread2 create %lx!\n",tid2);
		
	int** maxa = NULL;
	int** maxb = NULL;
	pthread_join( tid1,(void **)maxa);
	pthread_join( tid2,(void **)maxb);
	printf("\tmax num = %d\n",(**maxa)>(**maxb)?(**maxa):(**maxb));
		
}

