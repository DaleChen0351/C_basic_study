#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



//��ҵ������ʹ�õ�����
//�û�׼�����ĸ��ֽڹ����ǰ�����ά������ 
//�û��Լ�ά������������ֻ����������

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
//��ʼ������
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
//��������
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
	//�ҵ������λ��
	struct LinkNode* curNode = &mylist->m_header;
	for (int i = 0; i < pos; i++)
	{
		curNode = curNode->next;
	}
	//�½��ڵ�
	//���û������ݵ�ǰ�ĸ��ֽ�ת��ΪLinkNode����
	struct LinkNode* newNode = data;//

	//������ϵ
	newNode->next = curNode->next;
	curNode->next = newNode;

	//��ȼӼ�
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

//�û�����
struct Person
{
	struct LinkNode* node;
	char name[64];
	int age;
};
//�û�����ص�����
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

