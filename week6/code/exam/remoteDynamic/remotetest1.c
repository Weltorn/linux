#include "mylib.h"
#include <stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

int main()
{
	int a[5];
	int s,m;
	char* error;
	void *hd;
	void (*init)(),(*show)();
	int (*sum)(),(*max)();
	hd = dlopen("../../dynamiclib/libdylib.so",RTLD_LAZY);
	if(!hd)
	{
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}

	init = dlsym(hd,"init");
	if((error = dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	show = dlsym(hd,"show");
	if((error = dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	sum = dlsym(hd,"sum");
	if((error = dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	max = dlsym(hd,"max");
	if((error = dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}

	
	printf("sum: %d, max: %d\n",s,m);
	
	
	init(a,5);
	m = max(a,5);
	s = sum(a,5);
	show(a,5);
	printf("sum: %d, max: %d\n",s,m);
	//关闭库
	if(dlclose(hd)<0)
	{
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	return 0;
}
