
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

int mainmenu_1();
unsigned inputMode_1();
int inputFileName_1(char*);

int createFile_1();
int addToFile_1();
int showFile_1();

int changeFileMode_1();
int showFileMode_1();





