#include "head.h"
void *worker1(void *arg);
void *worker2(void *arg);
pthread_rwlock_t rwlock;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
int c=200;

int main()
{
	pthread_t tid[2];
	int i,ret;
	ret = pthread_create(&tid[0],NULL,worker1,NULL);
	if(ret!=0)
	{
		perror("thread1 init failed！\n");
		exit(1);
	}
	ret = pthread_create(&tid[1],NULL,worker2,NULL);
	if(ret!=0)
	{
		perror("thread2 init failed！\n");
		exit(1);
	}	
	for(i=0;i<2;i++)
	{
		pthread_join(tid[i],NULL);		
	}
	return 0;
}

void *worker1(void *arg)
{
	while(1)
	{
	pthread_mutex_lock(&mutex);
	if(c>0)
	{
		usleep(1000);
		printf("thread 1 sell tickit: %d\n",c--);
		pthread_mutex_unlock(&mutex);
	}
	else
	{
		pthread_mutex_unlock(&mutex);
		break;
	}
	pthread_yield();
	}
	return NULL;
}
void *worker2(void *arg)
{
	while(1)
	{
	pthread_mutex_lock(&mutex);
	if(c>0)
	{
		usleep(1000);
		printf("thread 2 sell tickit: %d\n",c--);
		pthread_mutex_unlock(&mutex);
	}
	else
	{
		pthread_mutex_unlock(&mutex);
		break;
	}
	pthread_yield();
	}
	return NULL;
}















