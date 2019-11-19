#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
#include<wait.h>
#include<string.h>

int main()
{	
	pid_t pid;
	int pipe_fd[2],r_num;
	char buf_r[100];
	memset(buf_r,0,sizeof(buf_r));
	if((pipe(pipe_fd))<0)
	{
		perror("创建管道失败\n");
		return -1;
	}
	if((pid=fork())<0)
	{
		perror("创建子进程失败!\n");
		return -1;
	}	
	if(pid == 0)
	{
		close(pipe_fd[1]);
		if((r_num = read(pipe_fd[0],buf_r,100))>0)
			printf("子进程读取了%d个字符，内容为：%s\n",r_num,buf_r);
		close(pipe_fd[0]);
		exit(0);
	}	
	else
	{
		close(pipe_fd[0]);
		if(write(pipe_fd[1],"first line",10) != -1)
			printf("父进程向管道写入‘first line’\n");
		if(write(pipe_fd[1],"second line",10) != -1)
			printf("父进程向管道写入‘second line’\n");
		close(pipe_fd[1]);
		waitpid(pid,NULL,0);
		exit(0);
	}
}
