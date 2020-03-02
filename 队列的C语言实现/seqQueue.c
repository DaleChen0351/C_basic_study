#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "seqQueue.h"
//初始化队列
SeqQueue init_SeqQueue()
{
	struct dynamicArray* mysq = init_DynamicArray(MAX);
	return mysq;
}

//入队
void push_SeqQueue(SeqQueue sq, void* data)
{
	if (sq == NULL || data == NULL)
	{
		return;
	}
	struct dynamicArray* mysq = sq;
	if (mysq->m_size >= MAX)
	{
		return;
	}
	insert_dynamicArray(mysq, mysq->m_size, data);
}
//出队
void pop_SeqQueue(SeqQueue sq)
{
	if (sq == NULL)
	{
		return;
	}
	struct dynamicArray* mysq = sq;
	//判断是否为空
	if (mysq->m_size <= 0)
	{
		return;
	}
	removeByPos_dynamicArray(mysq, 0);//从队头位置出队
}

//返回front
void* front_SeqQueue(SeqQueue sq)
{
	if (sq == NULL)
	{
		return NULL;
	}
	struct dynamicArray* mysq = sq;
	return mysq->pAddr[0];
}

//返回back
void* back_SeqQueue(SeqQueue sq)
{
	if (sq == NULL)
	{
		return NULL;
	}
	struct dynamicArray* mysq = sq;
	return mysq->pAddr[mysq->m_size - 1];
}

//返回队伍大小
int size_SeqQueue(SeqQueue sq)
{
	if (sq == NULL)
	{
		return -1;
	}
	struct dynamicArray* mysq = sq;
	return mysq->m_size;
}

//销毁
void destroy_SeqQueue(SeqQueue sq)
{
	if (sq == NULL)
	{
		return;
	}
	destory_dynamicArray(sq);
}