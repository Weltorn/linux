#include "func.h"
int changeFileMode()
{
	char *filepath = malloc(sizeof(char)*FILEPATHMAXLEN);
	char ch;
	unsigned mode;
	FILE *currentFile = NULL;
	inputFileName(filepath);

	printf("input file mode here: ");			
				mode = inputMode();
				fgetc(stdin);
				if(chmod(filepath,mode) == -1)
				{
						printf("change mode error ");
				}
	free(filepath);
}
int showFileMode()
{
	char *filepath = malloc(sizeof(char)*FILEPATHMAXLEN);
	char ch;
	struct stat buf;
	FILE *currentFile = NULL;
	inputFileName(filepath);

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
	free(filepath);
}
