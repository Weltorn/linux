#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<signal.h>
#include<wait.h>
#include<string.h>
#include<errno.h>

#define BUF_4K (4*1024)
#define BUF_8K (8*1024)
#define BUF_16K (16*1024)
int main(void)
{
	char a[BUF_4K];
	char b[BUF_8K];
	char c[BUF_16K];
	memset(a,'A',sizeof(a));
	memset(b,'B',sizeof(b));
	memset(c,'C',sizeof(c));
	int fd[2];
	int ret = 0;
	pid_t pid;
	
	if(pipe(fd)==-1)
	{
		fprintf(stderr,"create pipe error (%s)\n",strerror(errno));
		exit(-2);
	}
	pid = fork();
	if(pid == -1)
	{
		fprintf(stderr,"fork1 error (%s)\n",strerror(errno));
		exit(-3);
	}
	else if(pid == 0)
	{
		int loop = 0;
		close(fd[0]);
		
		while(loop++<10)
		{
			ret = write(fd[1],a,sizeof(a));
			printf("child %d write %d byte\n",getpid(),ret);
		}
		close(fd[1]);
		exit(0);
	}
	else
	{
		pid = fork();
		if(pid == -1)
		{
			fprintf(stderr,"fork2 error (%s)\n",strerror(errno));
			exit(-3);
		}
		else if(pid == 0)
		{
			int loop = 0;
			close(fd[0]);
		
			while(loop++<10)
			{
				ret = write(fd[1],b,sizeof(b));
				printf("child %d write %d byte\n",getpid(),ret);
			}
			close(fd[1]);
			exit(0);
		}
		else
		{
			pid = fork();
			if(pid == -1)
			{
				fprintf(stderr,"fork3 error (%s)\n",strerror(errno));
				exit(-3);
			}
			else if(pid == 0)
			{
				int loop = 0;
				close(fd[0]);
		
				while(loop++<10)
				{
					ret = write(fd[1],c,sizeof(c));
					printf("child %d write %d byte\n",getpid(),ret);
				}
				close(fd[1]);
				exit(0);
			}			
		}
		close(fd[1]);
		sleep(2);
		int fd1 = open("./test.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
		char buf[4*1024] = {0};
		int n = 1;
		while(1)
		{
			ret = read(fd[0],buf,sizeof(buf));
			if(ret <= 0)
				break;
			printf("%d: parent read %d bytes buf[4095]=%c\n",n++,ret,buf[4095]);
			write(fd1,buf,ret);
			
		}
		close(fd[0]);
		return 0;
	}
}
