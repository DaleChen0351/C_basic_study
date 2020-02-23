#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



struct LinkNode
{
	void* data;
	struct LinkNode* next;
};

struct LList
{
	struct LinkNode pHeader;
	int m_size;
};

typedef void* LinkList;
//初始化LinkList
LinkList init_LinkList()
{
	struct LList* mylist = malloc(sizeof(struct LList));
	if (mylist == NULL)
	{
		return NULL;
	}
	mylist->pHeader.data = NULL;
	mylist->pHeader.next = NULL;
	mylist->m_size = 0;

	return mylist;
}
// 插入节点
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
	// 位置判断
	struct LList* mylist = list;
	if (pos < 0 || pos > mylist->m_size - 1)
	{
		pos = mylist->m_size;
	}
	// 创建新节点
	struct LinkNode* newNode = malloc(sizeof(struct LinkNode));
	newNode->data = NULL;
	newNode->next = NULL;

	//遍历List找出插入点
	struct LinkNode* pCurrent = &mylist->pHeader;
	for (int i = 0; i < pos; i++)// 找出pos位置节点的前驱节点
	{
		pCurrent = pCurrent->next;
	}
	// 插入操作
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	newNode->data = data;
	mylist->m_size++;
}
// 遍历单项链表
void foreach_LinkList(LinkList list, void(*myprint)(void*))
{
	if (list == NULL)
	{
		return ;
	}
	if (myprint == NULL)
	{
		return ;
	}
	struct LList* mylist = list;
	struct LinkNode* pCurNode = mylist->pHeader.next;
	for (int idx = 0; idx < mylist->m_size; idx++)
	{
		myprint(pCurNode->data);
		pCurNode = pCurNode->next;
	}
}
// 按位置删除节点
void removeByPos_LinkList(LinkList list, int pos)
{
	// 保护
	if (list == NULL)
	{
		return;
	}
	struct LList* mylist = list;
	if (pos < 0 || pos > mylist->m_size - 1)
	{
		return;
	}
	// 找出前驱
	struct LinkNode* pCurNode = &mylist->pHeader;
	for (int idx = 0; idx < pos; idx++)
	{
		pCurNode = pCurNode->next;
	}
	// 缓存要删除的节点
	struct LinkNode* pDel = pCurNode->next;
	pCurNode->next = pDel->next;
	// 删除当前节点
	free(pDel);
	pDel = NULL;
	// 节点个数减一
	mylist->m_size--;
}

void removeByValue_LinkList(LinkList list, void* data, int(*mycompare)(void*, void* ))
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
	//struct node
	struct LinkNode* pPrevNode = &mylist->pHeader;
	struct LinkNode* pCurrNode = pPrevNode->next;

	for (int idx = 0; idx < mylist->m_size; idx++)
	{
		if (mycompare(pCurrNode->data, data))
		{
			pPrevNode->next = pCurrNode->next;

			pCurrNode->next = NULL;
			free(pCurrNode);
			mylist->m_size--;
			break;
		}
		// 如果没匹配
		pPrevNode = pCurrNode;
		pCurrNode = pCurrNode->next;
	}
	
}
// 清除列表
void clear_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}
	struct LList* mylist = list;
	struct LinkNode* pCurrNode = mylist->pHeader.next;
	for (int i = 0; i < mylist->m_size; i++)
	{
		struct LinkNode *pNext = pCurrNode->next;
		free(pCurrNode);
		pCurrNode = pNext;
	}
	//收尾
	mylist->m_size = 0;
	mylist->pHeader.next = NULL;
}
// 获取size
int size_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return -1;
	}
	struct LList* mylist = list;
	return mylist->m_size;
}
// destory List
void destory_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}
	clear_LinkList(list);
	free(list);
	list = NULL;

}



//Person
struct Person
{
	char name[64];
	int age;
};

// 回调函数
void Myprint(void* val)
{
	struct Person* p = val;
	printf("name = %s   age = %d\n", p->name, p->age);
}

int MyCompare(void* data1, void* data2)
{
	struct Person* p1 = data1;
	struct Person* p2 = data2;

	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

void test_01()
{
	LinkList list = init_LinkList();

	struct Person p1 = { "赵云",24 };
	struct Person p2 = { "吕布",24 };
	struct Person p3 = { "张飞",34 };
	struct Person p4 = { "关羽",24 };
	struct Person p5 = { "马超",54 };
	struct Person p6 = { "典韦",22 };

	insert_LinkList(list, 0, &p1);
	insert_LinkList(list, 0, &p2);
	insert_LinkList(list, 0, &p3);
	insert_LinkList(list, 1, &p4);
	insert_LinkList(list, 100, &p5);
	insert_LinkList(list, 2, &p6);
	//张飞 关羽 典韦 吕布 赵云 马超
	foreach_LinkList(list, Myprint);

	removeByPos_LinkList(list, 2);
	printf("按照位置删除节点\n");
	foreach_LinkList(list, Myprint);

	struct Person p = { "马超",54 };
	removeByValue_LinkList(list, &p,MyCompare);
	printf("按照值删除节点\n");
	foreach_LinkList(list, Myprint);

	printf("size of list = %d\n", size_LinkList(list));

	clear_LinkList(list);
	printf("size of list = %d\n", size_LinkList(list));
	destory_LinkList(list);

}

int main()
{
	//test_01();
	main_03();
	system("pause");
}