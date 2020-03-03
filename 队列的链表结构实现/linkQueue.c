#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkQueue.h"

//初始化
LinkQueue init_LinkQueue()
{
	struct LQueue* queue = malloc(sizeof(struct LQueue));
	if (queue == NULL)
	{
		return NULL;
	}
	queue->m_header.next = NULL;
	queue->m_size = 0;
	queue->pTail = &(queue->m_header);//尾结点指针指向头结点
	
	return queue;
}
//从尾部入队
void push_LinkQueue(LinkQueue lq, void* data)
{
	if (lq == NULL || data == NULL)
	{
		return;
	}
	struct LQueue* queue = lq;
	//取出用户的前四个字节
	struct QueueNode* newNode = data;
	//初始化
	newNode->next = NULL;
	//建立关系
	queue->pTail->next = newNode;//从链表的尾部入队
	queue->pTail = newNode;

	queue->m_size++;
}
//从头部出队
void pop_LinkQueue(LinkQueue lq)
{
	if (lq == NULL )
	{
		return;
	}
	struct LQueue* queue = lq;
	if (queue->m_size <= 0)
	{
		return ;
	}
	struct QueueNode* firstNode = queue->m_header.next;//头结点
	//更新指向
	queue->m_header.next = firstNode->next;//不需要写free代码，因为数据是用户负责开辟的。
	//更新队列长度
	queue->m_size--;
}
//返回头部元素指针
void* front_LinkQueue(LinkQueue lq)
{
	if (lq == NULL)
	{
		return NULL;
	}
	struct LQueue* queue = lq;
	if (queue->m_size <= 0)
	{
		return NULL;
	}
	return queue->m_header.next;
}
//返回尾部元素指针
void* back_LinkQueue(LinkQueue lq)
{
	if (lq == NULL)
	{
		return NULL;
	}
	struct LQueue* queue = lq;
	if (queue->m_size <= 0)
	{
		return NULL;
	}
	
	return queue->pTail;
}
//返回队伍大小
int size_LinkQueue(LinkQueue lq)
{
	if (lq == NULL)
	{
		return -1;
	}
	struct LQueue* queue = lq;
	return queue->m_size;
}

//销毁
void destroy_LinkQueue(LinkQueue lq)
{
	if (lq == NULL)
	{
		return;
	}
	free(lq);
	lq = NULL;
}