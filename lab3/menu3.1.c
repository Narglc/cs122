#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define PRINTLINE printf("-------------------------------------\n");

#define CMD_MAX_LEN 128
#define DESC_LEN	10224
#define CMD_NUM		10

typedef struct DataNode{
	char*	cmd;
	char*	desc;
	int		(*handler)();
	struct DataNode *next;
}tDataNode;

int Help();
int Quit();

static tDataNode head[] = 
{
	{"help", 	"this is help cmd!", Help, 	&head[1]},
	{"version",	"menu program v1.0", NULL,	&head[2]},
	{"quit",	"Quit from menu",    Quit,	NULL}
};

int Help()
{
	PRINTLINE
	printf("Menu List:\n");
	tDataNode* p = head;
	while(NULL != p)
	{
		printf("%s - %s\n", p->cmd, p->desc);
		p = p->next;
	}
	PRINTLINE
	return 0;
}

int Quit()
{
	printf("Quit program : [%s:%s].\n", __FILE__, __FUNCTION__);
	exit(0);
}

int main()
{
	while(1)
	{
		char cmd[CMD_MAX_LEN];
		printf("Input a cmd number > ");
		scanf("%s",cmd);
		tDataNode *p = head;
		while(p != NULL)
		{
			if(0 == strcmp(p->cmd,cmd))
			{
				printf("%s - %s\n", p->cmd, p->desc);
				if(NULL != p->handler)
				{
					PRINTLINE
					p->handler();
				}
				break;
			}
			p = p->next;
		}
	}
	return 0;
}
