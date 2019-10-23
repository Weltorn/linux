#include "func.h"

int createFile()
{
	char *filepath = malloc(sizeof(char)*FILEPATHMAXLEN);
	FILE *currentFile = NULL;
	inputFileName(filepath);

	currentFile = fopen(filepath,"w");
	if(currentFile == NULL)
	{
		printf("create file error!\n");
	}
	fclose(currentFile);
	free(filepath);
}
int addToFile()
{
	char *filepath = malloc(sizeof(char)*FILEPATHMAXLEN);
	char ch;
	FILE *currentFile = NULL;
	inputFileName(filepath);

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
	free(filepath);
}
int showFile()
{
	char *filepath = malloc(sizeof(char)*FILEPATHMAXLEN);
	char ch;
	FILE *currentFile = NULL;
	inputFileName(filepath);

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
	fclose(currentFile);
	free(filepath);
}


