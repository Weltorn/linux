#include <stdio.h>
#include <pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<signal.h>
#include<wait.h>
#include<string.h>
#include<errno.h>

#define NUM_THREADS 4
 
void hello(void *t)
{
	pthread_t my_tid;
	my_tid=pthread_self();
	printf("\tthread %d:my tid is %lx,hello world\n",t,my_tid);
}

int main()
{
	pthread_t tid;
	int rv,t;
	for(t = 0;t<NUM_THREADS;t++)
	{
		rv = pthread_create(&tid,NULL,(void*(*)())hello,(void*)t);
		if(rv!=0)
		{
			printf("thread create failed!\n");
			return -1;
		}
		printf("thread create %lx!\n",tid);
	}
	printf("good bye\n");
	pthread_exit(NULL);
		
}

