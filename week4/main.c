#include "uhead.h"
int main()
{
	int array1[100];
	int array2[100];
	struct opt s;
	struct timeval begin;
	struct timeval end;
	struct timezone tz;
    urand(array1, 100);
	urand(array2, 100);
	writeFile("rawdata1.dat",array1,100);
	writeFile("rawdata2.dat",array2,100);
	//show(array, 100);
	
	gettimeofday(&begin, &tz);
	mySort(array1, 100);
	gettimeofday(&end, &tz);
	printf("mySort_usetime: %ld\n", end.tv_usec-begin.tv_usec);
	writeFile("sort1.dat",array1,100);

	gettimeofday(&begin, &tz);
	sysSort(array2, 100);
	gettimeofday(&end, &tz);
	printf("sysSort_usetime: %ld\n", end.tv_usec-begin.tv_usec);
	writeFile("sort2.dat",array2,100);

	printf("show sort2.dat: \n");
	showFile("sort2.dat");
	s = uopterater(array2, 100);
	printf("average=%.2f, sum=%d\n",s.ave,s.sum);

	printf("show sort1.dat: \n");
	showFile("sort1.dat");
	s = uopterater(array1, 100);
	printf("average=%.2f, sum=%d\n",s.ave,s.sum);
	return 0;
}
