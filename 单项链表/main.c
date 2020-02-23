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
//��ʼ��LinkList
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
// ����ڵ�
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
	// λ���ж�
	struct LList* mylist = list;
	if (pos < 0 || pos > mylist->m_size - 1)
	{
		pos = mylist->m_size;
	}
	// �����½ڵ�
	struct LinkNode* newNode = malloc(sizeof(struct LinkNode));
	newNode->data = NULL;
	newNode->next = NULL;

	//����List�ҳ������
	struct LinkNode* pCurrent = &mylist->pHeader;
	for (int i = 0; i < pos; i++)// �ҳ�posλ�ýڵ��ǰ���ڵ�
	{
		pCurrent = pCurrent->next;
	}
	// �������
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	newNode->data = data;
	mylist->m_size++;
}
// ������������
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
// ��λ��ɾ���ڵ�
void removeByPos_LinkList(LinkList list, int pos)
{
	// ����
	if (list == NULL)
	{
		return;
	}
	struct LList* mylist = list;
	if (pos < 0 || pos > mylist->m_size - 1)
	{
		return;
	}
	// �ҳ�ǰ��
	struct LinkNode* pCurNode = &mylist->pHeader;
	for (int idx = 0; idx < pos; idx++)
	{
		pCurNode = pCurNode->next;
	}
	// ����Ҫɾ���Ľڵ�
	struct LinkNode* pDel = pCurNode->next;
	pCurNode->next = pDel->next;
	// ɾ����ǰ�ڵ�
	free(pDel);
	pDel = NULL;
	// �ڵ������һ
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
		// ���ûƥ��
		pPrevNode = pCurrNode;
		pCurrNode = pCurrNode->next;
	}
	
}
// ����б�
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
	//��β
	mylist->m_size = 0;
	mylist->pHeader.next = NULL;
}
// ��ȡsize
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

// �ص�����
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

	struct Person p1 = { "����",24 };
	struct Person p2 = { "����",24 };
	struct Person p3 = { "�ŷ�",34 };
	struct Person p4 = { "����",24 };
	struct Person p5 = { "��",54 };
	struct Person p6 = { "��Τ",22 };

	insert_LinkList(list, 0, &p1);
	insert_LinkList(list, 0, &p2);
	insert_LinkList(list, 0, &p3);
	insert_LinkList(list, 1, &p4);
	insert_LinkList(list, 100, &p5);
	insert_LinkList(list, 2, &p6);
	//�ŷ� ���� ��Τ ���� ���� ��
	foreach_LinkList(list, Myprint);

	removeByPos_LinkList(list, 2);
	printf("����λ��ɾ���ڵ�\n");
	foreach_LinkList(list, Myprint);

	struct Person p = { "��",54 };
	removeByValue_LinkList(list, &p,MyCompare);
	printf("����ֵɾ���ڵ�\n");
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