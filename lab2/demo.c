#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char cmd[128];
	while(1)
	{
		scanf("%s",cmd);
		if(0 == strcmp(cmd,"help"))
		{
			printf("This is Menu Help!\n");
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
