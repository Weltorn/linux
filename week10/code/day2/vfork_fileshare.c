#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
#include<wait.h>
#include<string.h>

int main()
{	
	pid_t pid;
	FILE* fp;
	char buf[20];
	if((fp = fopen("test.dat","a+")) ==NULL)
	{
		perror("failed to fopen\n");
		return -1;
	}
	
	pid = vfork();
	if(pid<0)
	{
		perror("创建子进程失败\n");
		exit(1);
	}
	else if(pid == 0)
	{
		sprintf(buf,"child:pid=%d",getpid());
		if(fputs(buf,fp) ==EOF)
		{
			perror("failed to fputs\n");
			return -1;
		}
		_exit(0);
	}
	else
	{
		sleep(2);
		sprintf(buf,"parent:pid=%d",getpid());
		if(fputs(buf,fp) ==EOF)
		{
			perror("failed to fputs\n");
			return -1;
		}
		exit(0);
	}
	return 0;
}
