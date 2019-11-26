#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
#include<wait.h>
#include<string.h>
#include<errno.h>

void sighandler(int signo);
int main()
{
	int fd[2];
	pid_t pid;
	if(signal(SIGPIPE,sighandler)==SIG_ERR)
	{
		fprintf(stderr,"signal error (%s)\n",strerror(errno));
		exit(-1);
	}
	if(pipe(fd)==-1)
	{
		fprintf(stderr,"create pipe error (%s)\n",strerror(errno));
		exit(-2);
	}
	pid = fork();
	if(pid == -1)
	{
		fprintf(stderr,"fork error (%s)\n",strerror(errno));
		exit(-3);
	}
	else if(pid == 0)
	{
	fprintf(stdout,"child will close last read pipe pid= %d,ppid=%d\n",getpid(),getppid());
		sleep(300);		
		close(fd[0]);
		exit(0);
	}
	else
	{
		sleep(500);
		close(fd[0]);
		sleep(1);
		int ret = 0;
		ret = write(fd[1],"hello",5);
		if(ret == -1)
		{
			fprintf(stderr,"pipe write error (%s)\n",strerror(errno));		
		}
		return 0;
	}
	
}

void sighandler(int signo)
{
	printf("parent chtch a PIPESIG error errnum= %d\n",signo);
}

