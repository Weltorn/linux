#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
int global1=1;
int main()
{	
	pid_t pid;
	int i = 10;
	static int k = 10;
	pid = vfork();
	if(pid<0)
	{
		perror("创建子进程失败\n");
		exit(1);
	}
	else if(pid == 0)
	{
		printf("child: pid: %d, ppid = %d,\n&i:%16p, &k:%16p, &global1: %16p\n"
						,getpid(),getppid(),&i,&k,&global1);
		i = 20;k = 20;//global1 = 3;
		printf("child after: pid: %d, ppid = %d,\ni:%d, k:%d, global1: %d\n"
						,getpid(),getppid(),i,k,global1);
		while(global1 == 1);
		_exit(0);
	}
	else
	{
		//sleep(5);
		global1 = 3;
		printf("parent: pid: %d, ppid = %d,\n&i:%16p, &k:%16p, &global1: %16p\n"
						,getpid(),getppid(),&i,&k,&global1);
		printf("parent after: pid: %d, ppid = %d,\ni:%d, k:%d, global1: %d\n"
						,getpid(),getppid(),i,k,global1);
		exit(0);
	}
	return 0;
}
