#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkList.h"


struct LinkNode* init_LinkList_C()
{
	//创建在堆区，写成动态链表。原因在于如果创建在栈区，则函数结束，链表就消失了
	struct LinkNode* pHeader = malloc(sizeof(struct LinkNode));
	//判断是否申请内存空间成功
	if (pHeader == NULL)
	{
		return NULL;
	}
	//初始化头结点
	pHeader->next = NULL;//头结点指针域为空

	//技巧：为了插入数据方便，增加一个尾结点指针
	struct LinkNode* pTail = pHeader;//开始的时候尾结点指向头结点

	//接受用户的输入
	int val = -1;
	while (1)
	{
		printf("请输入数据，输入-1则程序结束：\n");
		scanf("%d", &val);
		if (val == -1)
		{
			break;
		}
		//为插入的新数据新建一个节点
		struct LinkNode* newNode = malloc(sizeof(struct LinkNode));
		newNode->num = val;
		newNode->next = NULL;//注意，这里需要初始化为空的
		//建立关系
		pTail->next = newNode;
		pTail = newNode;	
	}

	return pHeader;
}

void foreach_LinkList_C(struct LinkNode* pH)
{
	if (pH == NULL)
	{
		return;
	}
	struct LinkNode* currentNode = pH->next;
	while (currentNode != NULL)
	{
		printf("%d\n", currentNode->num);
		currentNode = currentNode->next;
	}
}


