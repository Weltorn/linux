#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<signal.h>
#include<wait.h>
#include<string.h>
#include<errno.h>
 
static int sig_cnt[NSIG];
static int number = 0;
int sigorder[128] = {0};

#define MSG "#%d: receiver signal %d\n"

void handler(int signo)
{
	sigorder[number++] = signo;
}

int main(int argc,char *argv[])
{
	int i = 0;
	int k = 0;
	sigset_t blockmask;
	sigset_t emptymask;
	sigset_t pendmask;
	struct sigaction sa;
	
	sigfillset(&blockmask);
	#ifdef USE_SIGACTION
	sa.sa_handler = handler;
	sa.sa_mask = blockmask;
	sa.sa_flags=SA_RESTART;
	#endif
	printf("%s PID is %d\n",argv[0],getpid());
	for(i = 0;i<NSIG,i++)
	{
		if(i==SIGKILL||I==SIGSTOP)
			continue;
		#ifdef USE_SIGACTION
		if(sigaction(i,&sa,NULL)!=0)
		#else
		if(signal(i,handler)==SIG_ERR)
		#endif
		{
			fprintf(stderr,"sigaction for signo(%d) failed (%s)\n",i,strerror(errno));
			return -1;
		}
	}
	int sleep_time = atoi(argv[1]);
	if(sigprocmask(SIG_SETMASK,&blockmask,NULL)==-1)
	{
		fprintf(stderr,"setmask to block all  failed (%s)\n",strerror(errno));
		return -2;
	}
	printf("I will sleep for %d seconds\n",sleep_time);
	sleep(sleep_time);
	sigemptyset(&emptymask);
	if(sigprocmask(SIG_SETMASK,&emptymask,NULL)==-1)
	{
		fprintf(stderr,"setmask to release all  failed (%s)\n",strerror(errno));
		return -3;
	}
	for(i=0;i<number;i++)
	{
		if(sigorder[i] != 0)
		{
			printf("%d : signo :%d\n",sigorder[i]);
		}
	}
	return 0;
}















