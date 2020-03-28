#ifndef _LINKLIST_H_20200328_
#define _LINKLIST_H_20200328_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define PRINTLINE printf("-------------------------------------\n");

#define CMD_MAX_LEN 128
#define DESC_LEN	1024
#define CMD_NUM		10

/* data struct and its operations */
typedef struct DataNode{
	char*	cmd;
	char*	desc;
	int		(*handler)();
	struct DataNode *next;
}tDataNode;


tDataNode* FindCmd(tDataNode* head, char* cmd);
int ShowAllCmd(tDataNode *head);

#endif