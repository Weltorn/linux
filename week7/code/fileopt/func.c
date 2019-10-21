#include "func.h"
int mainmenu()
{
	int selection = 0;
	printf("                               MAIN MENU\n");
	printf("                               1.exit\n");
	printf("                               2.new file\n");
	printf("                               3.write file\n");
	printf("                               4.read file\n");
	printf("                               5.modify file access authority\n");
	printf("                               6.read file access authority\n");
	printf("Please enter your choice:");
	selection = getchar()-'0';

	getchar();
	return selection;
}

