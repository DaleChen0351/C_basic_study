#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "seqlist.h"

typedef void* SeqStack;

//ջ������������β����ԭ����β������Ƶ�������ɾ��Ч�ʸ�
//�ڴ��ϵ�ջҲ���д�С�ģ����д����ѭ����Ҳ����ϵͳ����


//ջ�ĳ�ʼ��
SeqStack init_SeqStack()
{
	struct SStack* stack = malloc(sizeof(struct SStack));
	memset(stack->data, 0, sizeof(stack->data));
	//printf(" sizeof(stack->data) = %d", sizeof(stack->data));//4096

	stack->m_size = 0;
	return stack;
}
//��ջ
void push_SeqStack(SeqStack stack, void* data)
{
	if (stack == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	//�Ȼ�ԭ����
	struct SStack* mystack = stack;
	//�Ƿ���ջ��
	if (mystack->m_size >= MAX)
	{
		return;
	}
	//��ջ
	mystack->data[mystack->m_size] = data;
	mystack->m_size++;
}
//��ջ
void* pop_SeqStack(SeqStack seqstack)
{
	if (seqstack == NULL)
	{
		return NULL;
	}
	//��ԭ����
	struct SStack* stack = seqstack;
	//�Ƿ�Ϊ��ջ
	if (stack->m_size <= 0)
	{
		return NULL;
	}
	//��ջ
	void* temp = stack->data[stack->m_size - 1];
	stack->data[stack->m_size - 1] = NULL;
	stack->m_size--;
	return temp;
}
//��ȡջ��Ԫ��
void* top_SeqStack(SeqStack seqstack)
{
	if (seqstack == NULL)
	{
		return NULL;
	}
	//��ԭ����
	struct SStack* stack = seqstack;
	//�Ƿ�Ϊ��ջ
	if (stack->m_size <= 0)
	{
		return NULL;
	}
	void* temp = stack->data[stack->m_size - 1];
	return temp;
}
//ջ�Ĵ�С
int size_SeqStack(SeqStack seqstack)
{
	if (seqstack == NULL)
	{
		return -1;
	}
	struct SStack* stack = seqstack;
	return stack->m_size;
}
//�ж�ջ�Ƿ�Ϊ��
int isEmpty_SeqStack(SeqStack seqstack)
{
	if (seqstack == NULL)
	{
		return -1;
	}
	struct SStack* stack = seqstack;
	if (stack->m_size == 0)
	{
		return 1;
	}
	return 0;
}

//����ջ
void destroy_SeqStack(SeqStack seqstack)
{
	if (seqstack == NULL)
	{
		return;
	}
	free(seqstack);
	seqstack = NULL;
}

