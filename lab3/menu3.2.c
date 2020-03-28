#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define PRINTLINE printf("-------------------------------------\n");

#define CMD_MAX_LEN 128
#define DESC_LEN	10224
#define CMD_NUM		10

/* data struct and its operations */
typedef struct DataNode{
	char*	cmd;
	char*	desc;
	int		(*handler)();
	struct DataNode *next;
}tDataNode;

tDataNode* FindCmd(tDataNode* head, char* cmd)
{
	if(NULL == head || NULL == cmd)
		return NULL:
	tDataNode *p = head;
	while(NULL != p)
	{
		if(0 == strcmp(p->cmd, cmd))
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

int ShowAllCmd(tDataNode *head)
{
	printf("Menu List:\n");
	tDataNode *p = head;
	while(NULL != p)
	{
		printf("%s - %s\n", p->cmd, p->desc);
		p = p->next;
	}
	return 0;
}

/* menu program */
int Help();
int Quit();

static tDataNode head[] = 
{
	{"help", 	"this is help cmd!", Help, 	&head[1]},
	{"version",	"menu program v1.0", NULL,	&head[2]},
	{"quit",	"Quit from menu",    Quit,	NULL}
};

int main()
{
	/* cmd line begins */
	while(1)
	{
		char cmd[CMD_MAX_LEN];
		printf("Input a cmd number > ");
		scanf("%s",cmd);
		tDataNode *p = FindCmd(head, cmd);
		if(NULL == p)
		{
			printf("This is a wrong cmd!\n");
			continue;
		}
		printf("%s - %s\n", p->cmd, p->desc);
		if(NULL != p->handler)
		{
			PRINTLINE
			p->handler();
		}
	}
	return 0;
}

int Help()
{
	ShowAllCmd(head);
	return 0;
}

int Quit()
{
	printf("Quit program : [%s:%s].\n", __FILE__, __FUNCTION__);
	exit(0);
}
