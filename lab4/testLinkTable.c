#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linktable.h"

typedef struct Node
{
	tLinkTableNode *pNext;
	int data;
}tNode;

tNode* Search(tLinkTable *pLinkTable);

int main()
{
	int i;
	tLinkTable* pLinkTable = CreatLinkTable();
	if(NULL == pLinkTable)
	{
		printf("create fail.\n");
		exit(-1);
	}

	for(int i = 0; i < 10; i++)
	{
		tNode* pNode = (tNode*)malloc(sizeof(tNode));
		pNode->data = i;
		debug("AddLinkTableNode\n");
		AddLinkTableNode(pLinkTable,(tLinkTableNode*)pNode);
	}

	/* search one by one */
	tNode* pTempNode = Search(pLinkTable);
	printf("%d\n", pTempNode->data);
	debug("DelLinkTableNode\n");
	DelLinkTableNode(pLinkTable,(tLinkTableNode*)pTempNode);
	free(pTempNode);
	DeleteLinkTable(pLinkTable);
}

tNode* Search(tLinkTable* pLinkTable)
{
	debug("Search GetLinkTableHead\n");
	tNode* pNode = (tNode*)GetLinkTableHead(pLinkTable);
	while(pNode != NULL)
	{
		if(pNode->data == 5)
		{
			return pNode;
		}
		debug("GetNextLinkTableNode\n");
		pNode = (pNode*)GetNextLinkTableNode(pLinkTable,(pLinkTableNode*)pNode);
	}
	return NULL;
}
