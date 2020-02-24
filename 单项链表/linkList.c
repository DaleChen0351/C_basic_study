#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkList.h"


struct LinkNode* init_LinkList_C()
{
	//�����ڶ�����д�ɶ�̬����ԭ���������������ջ���������������������ʧ��
	struct LinkNode* pHeader = malloc(sizeof(struct LinkNode));
	//�ж��Ƿ������ڴ�ռ�ɹ�
	if (pHeader == NULL)
	{
		return NULL;
	}
	//��ʼ��ͷ���
	pHeader->next = NULL;//ͷ���ָ����Ϊ��

	//���ɣ�Ϊ�˲������ݷ��㣬����һ��β���ָ��
	struct LinkNode* pTail = pHeader;//��ʼ��ʱ��β���ָ��ͷ���

	//�����û�������
	int val = -1;
	while (1)
	{
		printf("���������ݣ�����-1����������\n");
		scanf("%d", &val);
		if (val == -1)
		{
			break;
		}
		//Ϊ������������½�һ���ڵ�
		struct LinkNode* newNode = malloc(sizeof(struct LinkNode));
		newNode->num = val;
		newNode->next = NULL;//ע�⣬������Ҫ��ʼ��Ϊ�յ�
		//������ϵ
		pTail->next = newNode;
		pTail = newNode;	
	}

	return pHeader;
}

//����һ�������ݣ���oldValǰ����newVal�����û��oldVal,��β��
void insert_LinkList_C(struct LinkNode* pHeader, int oldVal, int newVal)
{
	if (pHeader == NULL)
	{
		return;
	}
	//������������ָ�����
	struct LinkNode* preNode = pHeader;
	struct LinkNode* curNode = pHeader->next;

	while (curNode != NULL)
	{
		if (curNode->num == oldVal)
		{
			break;
		}
		else
		{
			//���û���ҵ�λ�ã����ø���ָ���������
			preNode = curNode;
			curNode = curNode->next;
		}
	}
	//����ҵ��ˣ����߱���������û�ҵ�������루β�壩
	//�½��ڵ�
	struct LinkNode* newNode = malloc(sizeof(struct LinkNode));
	newNode->num = newVal;
	newNode->next = NULL;
	//������ϵ
	newNode->next = curNode;
	preNode->next = newNode; 
}

//ɾ���б��е���
void remove_LinkList_C(struct LinkNode* pHeader, int val)
{
	if (pHeader == NULL)
	{
		return;
	}
	//��������ָ��
	struct LinkNode* preNode = pHeader;
	struct LinkNode* curNode = pHeader->next;

	//��������
	while (curNode != NULL)
	{
		if (curNode->num == val)//ע�� == ��
		{
			break;
		}
		//��ǰ�ƶ�
		preNode = curNode;
		curNode = curNode->next;
	}
	//���û�ҵ�Ҫɾ����ֵ����ֱָ�ӷ���
	if (curNode == NULL)
	{
		return;
	}
	//������ϵ
	preNode->next = curNode->next;
	//�ͷ�curNode�ڵ�
	free(curNode);
	curNode = NULL;
}
//�������
void clear_LinkList_C(struct LinkNode* pHeader)
{
	if (pHeader == NULL)
	{
		return;
	}
	//������ʱָ��
	struct LinkNode* curNode = pHeader->next;
	while (curNode != NULL)
	{
		//�ȱ����ɾ���ڵ����Ľڵ�
		struct LinkNode* nextNode = curNode->next;
		free(curNode);
		curNode = nextNode;
	}

	//��ͷ����nextָ����Ϊ��
	pHeader->next = NULL;
}
//��������
void destroy_LinkList(struct LinkNode* pHeader)
{
	if (pHeader == NULL)
	{
		return;
	}
	//���������
	clear_LinkList_C(pHeader);
	//���ͷ�ͷ�ڵ�
	free(pHeader);
	pHeader = NULL;
}

void foreach_LinkList_C(struct LinkNode* pH)//����ͷ���
{
	if (pH == NULL)
	{
		return;
	}
	struct LinkNode* currentNode = pH->next;
	while (currentNode != NULL)
	{
		printf("%d\n", currentNode->num);
		currentNode = currentNode->next;
	}
}


