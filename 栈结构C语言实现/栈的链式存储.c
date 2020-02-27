#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//栈的链式存储
//头节点端做栈顶，头部插入和删除都很方便
//实现：使用企业级版本的链表//前四个字节分配给LInkNode

typedef void* LinkStack;
struct StackNode
{
	struct StackNode* next;//维护指针域
};
//链式的栈结构体
struct LStack
{
	struct StackNode m_header;
	int m_size;
};
//初始化
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
//入栈
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

	//建立关系
	newNode->next = stack->m_header.next;
	stack->m_header.next = newNode;

	stack->m_size++;

}
//出栈
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
//返回栈顶元素
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
//返回size
int size_LinkStack(LinkStack linkstack)
{
	if (linkstack == NULL)
	{
		return -1;
	}
	struct LStack* stack = linkstack;
	return stack->m_size;
}
//是否为空
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
//测试
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
		//先输出
		struct Person* p = top_LinkStack(stack);
		printf("name = %s,   age = %d\n", p->name, p->age);
		//再弹出
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
