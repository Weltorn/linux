#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
#include<wait.h>
#include<string.h>

int main()
{	
	pid_t pid1,pid2,p;
	FILE* fp;
	int s;
	char c;
	char buf[255];
	if((fp = fopen("test7.dat","a+")) ==NULL)
	{
		perror("failed to fopen\n");
		return -1;
	}
	if((pid1=fork())&&(pid2=fork())<0)
	{
		perror("failure to fork!\n");
		return -1;
	}	
	else if(pid1 == 0)
	{
		fprintf(fp,"pid=%d, 0123456789\n",getpid());
		return 0;
	}
	else if(pid2 == 0)
	{
		fprintf(fp,"pid=%d ,0123456789\n",getpid());	
		return 0;
	}	
	else
	{
		while((p = waitpid(pid1,&s,WNOHANG))!=-1 || (p = waitpid(pid2,&s,WNOHANG))!=-1 );
		printf("test7.dat:  \n");
		while((c = fgetc(fp)) != EOF)
		{			
			printf("%c", c );
		}
		//fgets(buf, 255, fp);
   		//printf("test7.dat:  %s\n", buf );	
		return 0;
	}
	return 0;
}
