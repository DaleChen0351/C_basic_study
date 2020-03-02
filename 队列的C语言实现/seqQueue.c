#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "seqQueue.h"
//��ʼ������
SeqQueue init_SeqQueue()
{
	struct dynamicArray* mysq = init_DynamicArray(MAX);
	return mysq;
}

//���
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
//����
void pop_SeqQueue(SeqQueue sq)
{
	if (sq == NULL)
	{
		return;
	}
	struct dynamicArray* mysq = sq;
	//�ж��Ƿ�Ϊ��
	if (mysq->m_size <= 0)
	{
		return;
	}
	removeByPos_dynamicArray(mysq, 0);//�Ӷ�ͷλ�ó���
}

//����front
void* front_SeqQueue(SeqQueue sq)
{
	if (sq == NULL)
	{
		return NULL;
	}
	struct dynamicArray* mysq = sq;
	return mysq->pAddr[0];
}

//����back
void* back_SeqQueue(SeqQueue sq)
{
	if (sq == NULL)
	{
		return NULL;
	}
	struct dynamicArray* mysq = sq;
	return mysq->pAddr[mysq->m_size - 1];
}

//���ض����С
int size_SeqQueue(SeqQueue sq)
{
	if (sq == NULL)
	{
		return -1;
	}
	struct dynamicArray* mysq = sq;
	return mysq->m_size;
}

//����
void destroy_SeqQueue(SeqQueue sq)
{
	if (sq == NULL)
	{
		return;
	}
	destory_dynamicArray(sq);
}