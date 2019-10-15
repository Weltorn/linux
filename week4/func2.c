#include "uhead.h"

struct opt uopterater(int* array, int num)
{
	struct opt temp;
	temp.sum = usum(array, num);
    temp.ave = (float)(temp.sum)/num;
	return temp;
}


