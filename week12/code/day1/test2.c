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
	int pipe_fd[2],r_num,i;
	char buf_r[4096];
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
		sleep(2);
		close(pipe_fd[1]);
		while((r_num = read(pipe_fd[0],buf_r,100))>0)		
			printf("子进程读取了%d个字符，内容为：%s\n",r_num,buf_r);
		close(pipe_fd[0]);
		exit(0);
	}	
	else
	{
		close(pipe_fd[0]);
		for(i = 0;i<=65536;i++)
		{
			if(write(pipe_fd[1],"0",1) == -1)
				break;		
			printf("write line: %d\n",i);					
		}				
		close(pipe_fd[1]);
		waitpid(pid,NULL,0);
		exit(0);
	}
}
