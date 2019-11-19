#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>

int main()
{
	int pid1,pid2,s,p;
	
	if((pid1=fork())&&(pid2=fork())<0)
	{
		perror("failure to fork!\n");
		return -1;
	}	
	else if(pid1 == 0)
	{
		printf("child1 %d,child is running now!\n",getpid());
		//while(1);
		printf("child1 %d,child exit now!\n",getpid());
		exit(1);
	}
	else if(pid2 == 0)
	{
		printf("child2 %d,child is running now!\n",getpid());
		//while(1);
		printf("child2 %d,child exit now!\n",getpid());
		exit(2);
	}
	else
	{
		printf("parent %d,parent is waiting zombie now!\n",getpid());
		while((p = waitpid(pid1,&s,WNOHANG))!=-1 || (p = waitpid(pid2,&s,WNOHANG))!=-1 )
		{
			printf("parent pid=%d,parent exit now!\n",getpid());
			if(WIFEXITED(s))
			{			
				printf("child %d is exiting normally code = %d\n",p,WEXITSTATUS(s));
			}
			else if(WIFSIGNALED(s))
			{
				printf("child %d is exit by signal code = %d\n",p,WTERMSIG(s));
			}
			else
			{
				printf("Not know\n");
			}

		}
		exit(0);		
	}
}
