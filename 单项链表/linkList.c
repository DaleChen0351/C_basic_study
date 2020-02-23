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

void foreach_LinkList_C(struct LinkNode* pH)
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


