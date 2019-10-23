
#include"func.h"

int main()
{
	int selection = 0;					

	while(1)
	{
		//system("clear");
	
		selection = mainmenu();									
		
		switch(selection)
		{
			case 1:
			{				
				exit(0);
				break;
			}
			case 2:
			{			
				createFile();//创建文件
				
				break;
			}
			case 3:
			{
				addToFile();//添加内容到文件
				
				break;
			}
			case 4:
			{
				showFile();//展示文件内容

				break;
			}
			case 5:
			{
				
				changeFileMode();//修改文件权限
				
				break;
			}
			
			case 6:
			{		
				showFileMode();//输出文件权限
				break;
			}
			default:
			{
				printf("\nInput error!Please input number 1~6!!\n");
			}

		}
	}

	return 0;
}
