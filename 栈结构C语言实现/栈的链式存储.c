#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//ջ����ʽ�洢
//ͷ�ڵ����ջ����ͷ�������ɾ�����ܷ���
//ʵ�֣�ʹ����ҵ���汾������//ǰ�ĸ��ֽڷ����LInkNode

typedef void* LinkStack;
struct StackNode
{
	struct StackNode* next;//ά��ָ����
};
//��ʽ��ջ�ṹ��
struct LStack
{
	struct StackNode m_header;
	int m_size;
};
//��ʼ��
LinkStack init_LinkStack()
{
	struct LStack* stack = malloc(sizeof(struct LStack));
	if (stack == NULL)
	{
		return NULL;
	}
	stack->m_header.next = NULL;
	stack->m_size = 0;

	return stack;
}
//��ջ
void push_LinkStack(LinkStack linkstack, void* data)
{
	if (linkstack == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	struct LStack* stack = linkstack;

	struct StackNode* newNode = data;

	//������ϵ
	newNode->next = stack->m_header.next;
	stack->m_header.next = newNode;

	stack->m_size++;

}
//��ջ
void pop_LinkStack(LinkStack linkstack)
{
	if (linkstack == NULL)
	{
		return;
	}
	struct LStack* stack = linkstack;
	if (stack->m_size <= 0)
	{
		return;
	}

	struct StackNode* firstNode = stack->m_header.next;
	stack->m_header.next = firstNode->next;

	stack->m_size--;
}
//����ջ��Ԫ��
void* top_LinkStack(LinkStack linkstack)
{
	if (linkstack == NULL)
	{
		return NULL;
	}
	struct LStack* stack = linkstack;
	if (stack->m_size <= 0)
	{
		return NULL;
	}
	return stack->m_header.next;
}
//����size
int size_LinkStack(LinkStack linkstack)
{
	if (linkstack == NULL)
	{
		return -1;
	}
	struct LStack* stack = linkstack;
	return stack->m_size;
}
//�Ƿ�Ϊ��
int isEmpty_LinkStack(LinkStack linkstack)
{
	if (linkstack == NULL)
	{
		return -1;
	}
	struct LStack* stack = linkstack;
	if (stack->m_size <= 0)
	{
		return 1;
	}
	return 0;
}

void destory_LinkStack(LinkStack linkstack)
{
	if (linkstack == NULL)
	{
		return;
	}
	free(linkstack);
	linkstack = NULL;
}
//����
struct Person
{
	struct StackNode;
	char name[64];
	int age;
};
void test_11()
{
	struct Person p1 = { NULL,"aaa",111 };
	struct Person p2 = { NULL,"bbb",222 };
	struct Person p3 = { NULL,"ccc",333 };
	struct Person p4 = { NULL,"ddd",444 };
	struct Person p5 = { NULL,"eee",555 };

	struct LinkStack* stack = init_LinkStack();
	push_LinkStack(stack, &p1);
	push_LinkStack(stack, &p2);
	push_LinkStack(stack, &p3);
	push_LinkStack(stack, &p4);
	push_LinkStack(stack, &p5);

	while (!isEmpty_LinkStack(stack))
	{
		//�����
		struct Person* p = top_LinkStack(stack);
		printf("name = %s,   age = %d\n", p->name, p->age);
		//�ٵ���
		pop_LinkStack(stack);
	}
	int size = size_LinkStack(stack);
	printf("size = %d", size);
	destory_LinkStack(stack);
	stack = NULL;
}

int main()
{
	test_11();
}
