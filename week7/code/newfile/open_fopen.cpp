#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>

int main()
{
	pid_t id;
	FILE* file;
	char* s="hello,world\n";
	if(fd = open("test.txt",O_WRONLY|O_CTEAT,S_IRUSR|S_IWUSR)==-1)
	{
		cout<<"Error open file"<<endl;
		return -1;
	}
	if(file = fopen("test2.txt","w+")==NULL)
	{
		cout<<"Error open file"<<endl;
		return -1;
	}
	cout<<"open file ok"<<endl;
	sleep(15);
	if(write(fd,s,strlen(s))<strlen(s))
	{
		cout<<"write error"<<endl;
		return -1;
	}
	if(fwrite(s,sizeof(char),strlen(s),file)<strlen(s))
	{
		cout<<"write error in fwrite"<<endl;
		return -1;
	}
	cout<<"after write"<<endl;
	sleep(15);
	cout<<"after sleep"<<endl;
	close(fd);
	return 0;
}
