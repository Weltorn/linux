#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
int global1=1,global2 = 2;
int main()
{	
	pid_t pid;
	int i = 10;
	static int k = 10;
	pid = fork();
	if(pid<0)
	{
		perror("创建子进程失败\n");
		exit(1);
	}
	else if(pid == 0)
	{
		printf("child: pid: %d, ppid = %d,\ni:%d, k:%d, global1: %d,global2: %d\n"
						,getpid(),getppid(),i,k,global1,global2);
		i = 20;k = 20;global1 = 3;global2 = 4;
		exit(0);
	}
	else
	{
		//sleep(5);
		printf("testfork: pid: %d, ppid = %d,\ni:%d, k:%d, global1: %d,global2: %d\n"
						,getpid(),getppid(),i,k,global1,global2);
		exit(0);
	}
	return 0;
}
