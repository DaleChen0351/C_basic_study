#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



//企业级开发使用的链表
//用户准备出四个字节供我们帮助其维护链接 
//用户自己维护数据域，我们只帮助其链接

typedef void* LinkList;

struct LinkNode
{
	struct LinkNode* next;
};

struct LList
{
	struct LinkNode m_header;
	int m_size;
};
//初始化链表
LinkList init_LinkList()
{
	struct LList* list = malloc(sizeof(struct LList));
	if (list == NULL)
	{
		return NULL;
	}
	list->m_header.next = NULL;
	list->m_size = 0;

	return list;
}
//插入数据
void insert_LinkList(LinkList list, int pos, void* data)
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	struct LList* mylist = list;
	if (pos < 0 || pos >mylist->m_size -1)
	{
		pos = mylist->m_size;
	}
	//找到插入的位置
	struct LinkNode* curNode = &mylist->m_header;
	for (int i = 0; i < pos; i++)
	{
		curNode = curNode->next;
	}
	//新建节点
	//将用户的数据的前四个字节转化为LinkNode类型
	struct LinkNode* newNode = data;//

	//建立关系
	newNode->next = curNode->next;
	curNode->next = newNode;

	//深度加加
	mylist->m_size++;
}

void foreach_LinkList(LinkList list, void(*myprint)(void*))
{
	if (list == NULL)
	{
		return;
	}
	struct LList* mylist = list;
	struct LinkNode* curNode = mylist->m_header.next;
	for (int i = 0; i < mylist->m_size; i++)
	{
		myprint(curNode);
		curNode = curNode->next;
	}
}

//用户类型
struct Person
{
	struct LinkNode* node;
	char name[64];
	int age;
};
//用户定义回调函数
void Myprint(void* data)
{
	struct Person* p = data;
	printf("name = %s   age = %d\n", p->name, p->age);
}
void test_01()
{
	struct Person p1 = { NULL,"aaa",111 };
	struct Person p2 = { NULL,"bbb",222 };
	struct Person p3 = { NULL,"ccc",333 };
	struct Person p4 = { NULL,"ddd",444 };
	struct Person p5 = { NULL,"eee",555 };
	
	
	LinkList* list = init_LinkList();
	insert_LinkList(list, 0, &p1);
	insert_LinkList(list, 0, &p2);
	insert_LinkList(list, 0, &p3);
	insert_LinkList(list, 1, &p4);
	insert_LinkList(list, 100, &p5);
	foreach_LinkList(list,Myprint );
}

int main()
{
	test_01();
	return 0;
}

