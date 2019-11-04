#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char* argv[])
{
	int i = 1;
	printf("test: pid: %d, ppid = %d\n",getpid(),getppid());
	for(i;i<argc;i++)
	{
		printf("argv[%d]: %s\n",i,argv[i]);
	}
	return 0;
}
