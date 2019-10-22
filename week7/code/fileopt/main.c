
#include"func.h"



int main()
{
	int selection = 0;			
	FILE *currentFile = NULL;
	char *filepath = malloc(sizeof(char)*1024);
	char ch;
	unsigned mode;
	struct stat buf;		

	while(1)
	{
		//system("clear");
	
		selection = mainmenu();									
		
		switch(selection)
		{
			case 1:
			{				
				exit(0);
				break;
			}
			case 2:
			{
				printf("input file name here: ");
				fgets(filepath,1024,stdin);
				if(filepath[strlen(filepath) - 1] == '\n')
					filepath[strlen(filepath) - 1] = '\0' ;
				//printf("%s:%d\n",filepath,strlen(filepath));
				currentFile = fopen(filepath,"w");
				if(currentFile == NULL)
				{
					printf("Open file error!\n");
				}
				fclose(currentFile);
				break;
			}
			case 3:
			{
				printf("input file name here: ");
				fgets(filepath,1024,stdin);
				if(filepath[strlen(filepath) - 1] == '\n')
					filepath[strlen(filepath) - 1] = '\0' ;
				currentFile = fopen(filepath,"a+");
				if(currentFile == NULL)
				{
					printf("Open file error!\n");
				}
				printf("Input here: \n");
				ch = fgetc(stdin);
				 while (ch != '\n') 
				 {
					fputc(ch, currentFile); 	
					ch = fgetc(stdin);
				}
				 fclose(currentFile);
				break;
			}
			case 4:
			{
				printf("input file name here: ");
				fgets(filepath,1024,stdin);
				if(filepath[strlen(filepath) - 1] == '\n')
					filepath[strlen(filepath) - 1] = '\0' ;
				currentFile = fopen(filepath,"r");
				if(currentFile == NULL)
				{
					printf("Open file error!\n");
				}
				while((ch = fgetc(currentFile)) != EOF)
				{
					fputc(ch, stdout);
				}
				fclose(currentFile);
				printf("\n");
				break;
			}
			case 5:
			{
				printf("input file name here: ");
				fgets(filepath,1024,stdin);
				if(filepath[strlen(filepath) - 1] == '\n')
					filepath[strlen(filepath) - 1] = '\0' ;
				printf("input file mode here: ");			
				mode = inputMode();
				fgetc(stdin);
				if(chmod(filepath,mode) == -1)
				{
						printf("change mode error ");
				}
				break;
			}
			
			case 6:
			{		
				printf("input file name here: ");
				fgets(filepath,1024,stdin);
				if(filepath[strlen(filepath) - 1] == '\n')
					filepath[strlen(filepath) - 1] = '\0' ;
				if(lstat(filepath,&buf) == -1)
				{
				 printf("stat error:%s\n",strerror(errno));
				return -1;
				}
				printf("st_mode :%o\t",buf.st_mode);
 
				if(S_ISREG(buf.st_mode))
					printf("-");
				else if(S_ISDIR(buf.st_mode))
					printf("d");
				else if(S_ISCHR(buf.st_mode))
					printf("c");
				else if(S_ISBLK(buf.st_mode))
					printf("b");
				else if(S_ISFIFO(buf.st_mode))
					printf("p");
				else if(S_ISLNK(buf.st_mode))
					printf("l");
				else if(S_ISSOCK(buf.st_mode))
					printf("s");
				else
					printf("error");
				printf("\n");
				break;
			}
			default:
			{
				printf("\nInput error!Please input number 1~6!!\n");
			}

		}
	}

	return 0;
}
