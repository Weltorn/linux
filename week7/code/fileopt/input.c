#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>


int mainmenu()
{
	int selection = 0;
	printf("                               MAIN MENU\n");
	printf("                               1.exit\n");
	printf("                               2.new file\n");
	printf("                               3.write file\n");
	printf("                               4.read file\n");
	printf("                               5.modify file access authority\n");
	printf("                               6.read file access authority\n");
	printf("Please enter your choice:");
	selection = getchar()-'0';
	//printf("your choice: %d\n",selection);
	getchar();
	return selection;
}

int inputFileName(char* filepath)
{
	if(filepath == NULL)
	{
		printf("filepath is NULL");
		return 1;
	}
	printf("input file name here: ");
	fgets(filepath,1024,stdin);
	if(filepath[strlen(filepath) - 1] == '\n')
		filepath[strlen(filepath) - 1] = '\0' ;
	return 0;
}

unsigned inputMode()
{
	int i = 0;
	char ch;
	unsigned mode = 0, var = 0;
	for (i = 3;i>=0;i--) 
	{						
		ch = fgetc(stdin);
		if(ch == '\n')
		{
			printf("%d :get an enter\n",i);
			i++;
			continue;
		}
		var = ch-'0';
		if(var>7||var<0)
		{
			printf("unleagle input\n");
			exit(1);
		}
		mode += var<<(3*i);
	}
	return mode;
}

