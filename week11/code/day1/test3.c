#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>

int main()
{
	int pid = 0,s;
	
	if((pid=fork())<0)
	{
		perror("failure to fork!\n");
		return -1;
	}	
	else if(pid == 0)
	{
		printf("child pid=%d,child is running now!\n",getpid());
		//while(1);
		printf("child pid=%d,child exit now!\n",getpid());
		exit(120);
	}
	else
	{
		printf("parent pid=%d,parent is waiting zombie now!\n",getpid());
		while((pid = wait(&s))!=-1)
		{
			printf("parent pid=%d,parent exit now!\n",getpid());
			if(WIFEXITED(s))
			{			
				printf("child %d is exiting normally code = %d\n",pid,WEXITSTATUS(s));
			}
			else if(WIFSIGNALED(s))
			{
				printf("child %d is exit by signal code = %d\n",pid,WTERMSIG(s));
			}
			else
			{
				printf("Not know\n");
			}

		}
		exit(0);		
	}
}
