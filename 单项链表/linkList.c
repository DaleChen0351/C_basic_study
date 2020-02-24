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

//插入一个新数据，在oldVal前插入newVal，如果没有oldVal,就尾插
void insert_LinkList_C(struct LinkNode* pHeader, int oldVal, int newVal)
{
	if (pHeader == NULL)
	{
		return;
	}
	//创建两个辅助指针变量
	struct LinkNode* preNode = pHeader;
	struct LinkNode* curNode = pHeader->next;

	while (curNode != NULL)
	{
		if (curNode->num == oldVal)
		{
			break;
		}
		else
		{
			//如果没有找到位置，则让辅助指针们向后移
			preNode = curNode;
			curNode = curNode->next;
		}
	}
	//如果找到了，或者遍历结束都没找到，则插入（尾插）
	//新建节点
	struct LinkNode* newNode = malloc(sizeof(struct LinkNode));
	newNode->num = newVal;
	newNode->next = NULL;
	//建立关系
	newNode->next = curNode;
	preNode->next = newNode; 
}

//删除列表中的数
void remove_LinkList_C(struct LinkNode* pHeader, int val)
{
	if (pHeader == NULL)
	{
		return;
	}
	//创建辅助指针
	struct LinkNode* preNode = pHeader;
	struct LinkNode* curNode = pHeader->next;

	//遍历链表
	while (curNode != NULL)
	{
		if (curNode->num == val)//注意 == 号
		{
			break;
		}
		//往前移动
		preNode = curNode;
		curNode = curNode->next;
	}
	//如果没找到要删除的值，则指直接返回
	if (curNode == NULL)
	{
		return;
	}
	//建立关系
	preNode->next = curNode->next;
	//释放curNode节点
	free(curNode);
	curNode = NULL;
}
//清空链表
void clear_LinkList_C(struct LinkNode* pHeader)
{
	if (pHeader == NULL)
	{
		return;
	}
	//创建临时指针
	struct LinkNode* curNode = pHeader->next;
	while (curNode != NULL)
	{
		//先保存待删除节点后面的节点
		struct LinkNode* nextNode = curNode->next;
		free(curNode);
		curNode = nextNode;
	}

	//将头结点的next指针置为空
	pHeader->next = NULL;
}
//销毁链表
void destroy_LinkList(struct LinkNode* pHeader)
{
	if (pHeader == NULL)
	{
		return;
	}
	//先清空链表
	clear_LinkList_C(pHeader);
	//再释放头节点
	free(pHeader);
	pHeader = NULL;
}

void foreach_LinkList_C(struct LinkNode* pH)//传入头结点
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


