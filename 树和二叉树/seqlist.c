#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "seqlist.h"

typedef void* SeqStack;

//栈顶设计在数组的尾部，原因是尾部进行频繁插入和删除效率高
//内存上的栈也是有大小的，如果写个死循环，也会让系统崩掉


//栈的初始化
SeqStack init_SeqStack()
{
	struct SStack* stack = malloc(sizeof(struct SStack));
	memset(stack->data, 0, sizeof(stack->data));
	//printf(" sizeof(stack->data) = %d", sizeof(stack->data));//4096

	stack->m_size = 0;
	return stack;
}
//入栈
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
	//先还原类型
	struct SStack* mystack = stack;
	//是否满栈？
	if (mystack->m_size >= MAX)
	{
		return;
	}
	//入栈
	mystack->data[mystack->m_size] = data;
	mystack->m_size++;
}
//出栈
void* pop_SeqStack(SeqStack seqstack)
{
	if (seqstack == NULL)
	{
		return NULL;
	}
	//还原类型
	struct SStack* stack = seqstack;
	//是否为空栈
	if (stack->m_size <= 0)
	{
		return NULL;
	}
	//出栈
	void* temp = stack->data[stack->m_size - 1];
	stack->data[stack->m_size - 1] = NULL;
	stack->m_size--;
	return temp;
}
//获取栈顶元素
void* top_SeqStack(SeqStack seqstack)
{
	if (seqstack == NULL)
	{
		return NULL;
	}
	//还原类型
	struct SStack* stack = seqstack;
	//是否为空栈
	if (stack->m_size <= 0)
	{
		return NULL;
	}
	void* temp = stack->data[stack->m_size - 1];
	return temp;
}
//栈的大小
int size_SeqStack(SeqStack seqstack)
{
	if (seqstack == NULL)
	{
		return -1;
	}
	struct SStack* stack = seqstack;
	return stack->m_size;
}
//判断栈是否为空
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

//销毁栈
void destroy_SeqStack(SeqStack seqstack)
{
	if (seqstack == NULL)
	{
		return;
	}
	free(seqstack);
	seqstack = NULL;
}

