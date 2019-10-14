#include "mylib.h"
#include <stdio.h>
int main()
{
	int a[5];
	int s,m;
	init(a,5);
	m = max(a,5);
	s = sum(a,5);
	show(a,5);
	printf("sum: %d, max: %d\n",s,m);
	return 0;
}
