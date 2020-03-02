#pragma once

#define MAX 1024

typedef void* SeqStack;

//ջ�Ľṹ��
struct SStack
{
	void* data[MAX];
	int m_size;
};
//ջ�ĳ�ʼ��
SeqStack init_SeqStack();

//��ջ
void push_SeqStack(SeqStack stack, void* data);

//��ջ
void* pop_SeqStack(SeqStack seqstack);

//��ȡջ��Ԫ��
void* top_SeqStack(SeqStack seqstack);

//ջ�Ĵ�С
int size_SeqStack(SeqStack seqstack);

//�ж�ջ�Ƿ�Ϊ��
int isEmpty_SeqStack(SeqStack seqstack);

//����ջ
void destroy_SeqStack(SeqStack seqstack);



