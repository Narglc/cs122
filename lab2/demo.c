#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define PRINTLINE printf("-------------------------------------\n");

void printMenuHelp()
{
	PRINTLINE
	printf("Help Page:\n");
	printf("1. help 	|	print help info.\n");
	printf("2. ls   	|	list files cwd\n");	
	printf("8. quit  	|	quit with 10.\n");
	PRINTLINE
}

void lsFilesAtWorkPlace()
{
	printf("%s:%s.\n", __FILE__, __FUNCTION__);
}

int main()
{
	char cmd[128];
	while(1)
	{
		scanf("%s",cmd);
		if(0 == strcmp(cmd, "help"))
		{
			printMenuHelp();
		}
		else if(0 == strcmp(cmd, "ls"))
		{
			lsFilesAtWorkPlace();
		}
		else if(0 == strcmp(cmd, "quit"))
		{
			exit(10);
		}
		else
		{
			printf("Wrong cmd!\n");
		}
	}
	return 0;
}
