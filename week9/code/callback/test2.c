#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	char* argv[4] = {"test1","hello world","will",NULL};
	
	printf("test2: pid: %d, ppid = %d\n",getpid(),getppid());
	execvp("test1",argv);
	printf("after exec call\n");
	return 0;
}
