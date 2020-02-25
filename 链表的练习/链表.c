#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkList.h"

struct Person
{
	char name[64];
	int age;
};
struct LinkNode
{
	void* data;
	struct LinkNode* next;
};

struct LList
{
	struct LinkNode m_header;
	int m_size;
};

typedef void*  LinkList;

LinkList init_LinkList_C()
{
	struct LList* plist = malloc(sizeof(struct LList));
	if (plist == NULL)
	{
		return NULL;
	}

	plist->m_header.data = NULL;
	plist->m_header.next = NULL;
	plist->m_size = 0;
	return plist;
}

void insert_LInkList_C(LinkList list, int pos, void* data)
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	struct LList* pList = list;
	if (pos < 0 || pos > pList->m_size)
	{
		pos = pList->m_size;
	}

	struct LinkNode* curNode = pList->m_header.next;
	//找到位置:插入点前一个
	for (int i = 0; i < pos; i++)
	{
		curNode = curNode->next;
	}

	//新建节点
	struct LinkNode* newNode = malloc(sizeof(struct LinkNode));
	newNode->data = data;
	newNode->next = NULL;

	//建立关系
	newNode->next = curNode->next;
	curNode->next = newNode;
}

void foreach_LinkList_C(LinkList list, void(*myprint)(void*))
{
	if (list == NULL)
	{
		return;
	}
	struct LList* plist = list;
	struct LinkNode* curNode = plist->m_header.next;

	while (curNode != NULL)
	{
		myprint(curNode->data);
		curNode = curNode->next;
	}
}
void Myprint(void* data)
{
	struct Person* pp = data;
	printf("name = %s  age = %d", pp->name, pp->age);
}
void test_61()
{
	LinkList list = init_LinkList_C();

	struct Person p1 = { "赵云",24 };
	struct Person p2 = { "吕布",24 };
	struct Person p3 = { "张飞",34 };
	struct Person p4 = { "关羽",24 };
	struct Person p5 = { "马超",54 };
	struct Person p6 = { "典韦",22 };

	insert_LInkList_C(list, 0, &p1);
	insert_LInkList_C(list, 0, &p2);
	insert_LInkList_C(list, 0, &p3);
	insert_LInkList_C(list, 1, &p4);
	insert_LInkList_C(list, 100, &p5);
	insert_LInkList_C(list, 2, &p6);
	//张飞 关羽 典韦 吕布 赵云 马超
	foreach_LinkList_C(list, Myprint);
}