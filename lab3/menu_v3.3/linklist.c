#include "linklist.h"


tDataNode* FindCmd(tDataNode* head, char* cmd)
{
	if(NULL == head || NULL == cmd)
		return NULL;
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