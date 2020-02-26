#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1024

typedef void* SeqStack;

//ջ������������β����ԭ����β������Ƶ�������ɾ��Ч�ʸ�
//�ڴ��ϵ�ջҲ���д�С�ģ����д����ѭ����Ҳ����ϵͳ����


//ջ�Ľṹ��
struct SStack
{
	void* data[MAX];
	int m_size;
};
//ջ�ĳ�ʼ��
SeqStack init_SeqStack()
{
	struct SStack* stack = malloc(sizeof(struct SStack));
	memset(stack->data, NULL, sizeof(stack->data));
	printf(" sizeof(stack->data) = %d", sizeof(stack->data));//4096

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

//����
struct Person
{
	char name[64];
	int age;
};

void test_01()
{ 
	struct Person p1 = { "aaa",111 };
	struct Person p2 = { "bbb",222 };
	struct Person p3 = { "ccc",333 };
	struct Person p4 = { "ddd",444 };
	struct Person p5 = { "eee",555 };

	struct SeqStack* stack = init_SeqStack();
	push_SeqStack(stack, &p1);
	push_SeqStack(stack, &p2);
	push_SeqStack(stack, &p3);
	push_SeqStack(stack, &p4);
	push_SeqStack(stack, &p5);

	while (!isEmpty_SeqStack(stack))
	{
		//�����
		struct Person* p = top_SeqStack(stack);
		printf("name = %s,   age = %d\n", p->name, p->age);
		//�ٵ���
		pop_SeqStack(stack);
	}
	int size = size_SeqStack(stack);
	printf("size = %d", size);
}

int main()
{
	test_01();
}