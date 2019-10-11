#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>

struct opt
{
float ave;
int sum;
};

int usum(int *,int);
void urand(int *,int);
struct opt uopterater(int*, int);
void show(int *array, int num);

int cmpfunc (const void * a, const void * b);
void sysSort(int *array, int num);
void mySort(int *array, int num);
void writeFile( char* filename, int *array, int num);
void showFile(char* filename);


