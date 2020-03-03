#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkQueue.h"

//��ʼ��
LinkQueue init_LinkQueue()
{
	struct LQueue* queue = malloc(sizeof(struct LQueue));
	if (queue == NULL)
	{
		return NULL;
	}
	queue->m_header.next = NULL;
	queue->m_size = 0;
	queue->pTail = &(queue->m_header);//β���ָ��ָ��ͷ���
	
	return queue;
}
//��β�����
void push_LinkQueue(LinkQueue lq, void* data)
{
	if (lq == NULL || data == NULL)
	{
		return;
	}
	struct LQueue* queue = lq;
	//ȡ���û���ǰ�ĸ��ֽ�
	struct QueueNode* newNode = data;
	//��ʼ��
	newNode->next = NULL;
	//������ϵ
	queue->pTail->next = newNode;//�������β�����
	queue->pTail = newNode;

	queue->m_size++;
}
//��ͷ������
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
	struct QueueNode* firstNode = queue->m_header.next;//ͷ���
	//����ָ��
	queue->m_header.next = firstNode->next;//����Ҫдfree���룬��Ϊ�������û����𿪱ٵġ�
	//���¶��г���
	queue->m_size--;
}
//����ͷ��Ԫ��ָ��
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
//����β��Ԫ��ָ��
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
//���ض����С
int size_LinkQueue(LinkQueue lq)
{
	if (lq == NULL)
	{
		return -1;
	}
	struct LQueue* queue = lq;
	return queue->m_size;
}

//����
void destroy_LinkQueue(LinkQueue lq)
{
	if (lq == NULL)
	{
		return;
	}
	free(lq);
	lq = NULL;
}