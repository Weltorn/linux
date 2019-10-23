
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <langinfo.h>

#define FILEPATHMAXLEN 20

int mainmenu();
unsigned inputMode();
int inputFileName(char*);

int createFile();
int addToFile();
int showFile();

int changeFileMode();
int showFileMode();





