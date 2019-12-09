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

void *threadfun(void *arg)
{
	printf("thread pid = %d\n",getpid());
}

int main()
{
	pthread_t tidp;
	int error;
	error = pthread_create(&tidp,NULL,threadfun,NULL);
	if(error !=0)
	{
		printf("thread create failed");
		return -1;
	}
	printf("main thread ended pid=%d\n",getpid());
	pthread_join(tidp,NULL);
	return 0;
}
