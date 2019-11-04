#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	printf("call: pid: %d, ppid = %d\n",getpid(),getppid());
	system("./test1");
	printf("after system call\n");
	return 0;
}
