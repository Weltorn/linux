#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	char* argv[4] = {"./test2","hello world","will",NULL};
	
	printf("execall: pid: %d, ppid = %d\n",getpid(),getppid());
	execv("./test2",argv);
	printf("after exec call\n");
	return 0;
}
