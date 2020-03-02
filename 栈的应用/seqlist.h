#pragma once

#define MAX 1024

typedef void* SeqStack;

//栈的结构体
struct SStack
{
	void* data[MAX];
	int m_size;
};
//栈的初始化
SeqStack init_SeqStack();

//入栈
void push_SeqStack(SeqStack stack, void* data);

//出栈
void* pop_SeqStack(SeqStack seqstack);

//获取栈顶元素
void* top_SeqStack(SeqStack seqstack);

//栈的大小
int size_SeqStack(SeqStack seqstack);

//判断栈是否为空
int isEmpty_SeqStack(SeqStack seqstack);

//销毁栈
void destroy_SeqStack(SeqStack seqstack);



