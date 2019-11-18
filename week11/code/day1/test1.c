#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>

int main()
{
	int pid;
	if((pid=fork())<0)
	{
		perror("failure to fork!\n");
		return -1;
	}
	else if(pid == 0)
	{
		printf("child pid=%d,child exit now!\n",getpid());
		exit(0);
	}
	else
	{
		printf("parent pid=%d,parent running now!\n",getpid());
		while(1);	
	}
}
