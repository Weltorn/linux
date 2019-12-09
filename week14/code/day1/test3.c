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
#include<time.h>

#define NUM_THREADS 4
 
struct info{
int no;
int n;
};
void hello(void *t)
{
	clock_t start, finish;  
   	double  duration;  
	pthread_t my_tid;
	struct info* y;
	int s=0;
 	start = clock();  
  
	y=(struct info*)t;
	for(int i = 0;i<=y->n;i++)
		s+=i;
	my_tid=pthread_self();
	printf("\tthread %d:my tid is %lx,hello world\n",(int)y->no,my_tid);
	finish = clock();  
	duration = (double)(finish - start) / CLOCKS_PER_SEC;  
	printf("\tthread %d:sum 1 to %d is %d,usetime =%f seconds\n",(int)y->no,y->n,s,duration);
	pthread_exit(NULL);
}

int main()
{
	pthread_t tid;
	int rv,t;
	struct info a[4];
	for(t = 0;t<NUM_THREADS;t++)
	{
		a[t].no = t;
		a[t].n = 100*(t+1);
		rv = pthread_create(&tid,NULL,(void*(*)())hello,(void*)&a[t]);
		if(rv!=0)
		{
			printf("thread create failed!\n");
			return -1;
		}
		printf("thread create %lx!\n",tid);
	}
	printf("good bye\n");
	//for(int i=0;i<NUM_THREADS;i++)
	//{
	//	double usetime = .0;
	//	pthread_join( a[i],(void*)&usetime);
	//	printf("\tthread %d:usetime =%f seconds\n",a[i].no,s,usetime);
	//}
	pthread_exit(NULL);
		
}

