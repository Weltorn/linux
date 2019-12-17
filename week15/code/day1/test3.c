#include "head.h"
void *reader(void *param);
void *writer(void *param);
pthread_rwlock_t rwlock;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
int share=0;

int main()
{
	int i=0,ret=0;
	pthread_t tid[TN];
	pthread_rwlockattr_t rwlock_attr;
	pthread_rwlockattr_init( &rwlock_attr);
	#ifdef WRITE_FIRST
		pthread_rwlockattr_setkind_np(&rwlockattr,PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP);
	#endif
	pthread_rwlock_rdlock(&rwlock);
	for(i=0;i<TN;i++)
	{
		if(i%2 ==0)
		{
			ret = pthread_create(&tid[i],NULL,reader,(void*)i);
		}
		else
		{
			ret = pthread_create(&tid[i],NULL,writer,(void*)i);
		}
		if(ret!=0)
		{
			perror("thread init failed！\n");
			exit(1);
		}
	}
	pthread_rwlock_unlock(&rwlock);
	while(i-- > 0)
	{
		pthread_join(tid[i],NULL);		
	}
	pthread_rwlockattr_destroy(&rwlock_attr);
	pthread_rwlock_destroy(&rwlock);
	return 0;
}

void *reader(void *param)
{
	int i=(int)param;
	while(1)
	{
		
		pthread_rwlock_rdlock(&rwlock);
		fprintf(stderr,"reader--%d the share= %d\n",i,share);
		pthread_rwlock_unlock(&rwlock);	
	}
	return NULL;
}
void *writer(void *param)
{
	int i=(int)param;
	while(1)
	{
		
		pthread_rwlock_rdlock(&rwlock);
		share++;
		fprintf(stderr,"reader--%d the share= %d\n",i,share);
		pthread_rwlock_unlock(&rwlock);	
		sleep(1);
	}
	return NULL;
}















