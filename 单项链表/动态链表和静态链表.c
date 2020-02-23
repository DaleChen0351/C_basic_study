#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//�ڵ������
//�ڵ������
struct LinkNode
{
	int num;
	struct LinkNode* next;
};

//��̬����
void test_31()
{
	//�����ڵ�
	struct LinkNode p1 = { 1,NULL };
	struct LinkNode p2 = { 2,NULL };
	struct LinkNode p3 = { 3,NULL };
	struct LinkNode p4 = { 4,NULL };
	struct LinkNode p5 = { 5,NULL };
	//������ϵ
	p1.next = &p2;
	p2.next = &p3;
	p3.next = &p4;
	p4.next = &p5;
	//��������Ľڵ�
	struct LinkNode* currentNode = &p1;
	while (currentNode != NULL)
	{
		printf("%d", currentNode->num);
		currentNode = currentNode->next;
	}
}

//��̬����
//�����ڴ�
struct LinkNode** allocateNodeSpace(int len)
{
	struct LinkNode** temp = malloc(sizeof(struct LinkNode*)*len);
	for (int i = 0; i < len; i++)
	{
		temp[i] = malloc(sizeof(struct LinkNode));
		temp[i]->num = i + 1;
	}
	return temp;
}
//�ͷ��ڴ�
void freeNodeSpace(struct LinkNode** p, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (p[i] != NULL)
		{
			free(p[i]);
			p[i] = NULL;
		}
	}
	free(p);
	p = NULL;
}
void test_32()
{
	struct LinkNode** pNodeArr= NULL;
	pNodeArr = allocateNodeSpace(5);
	//������ϵ
	pNodeArr[0]->next = pNodeArr[1];
	pNodeArr[1]->next = pNodeArr[2];
	pNodeArr[2]->next = pNodeArr[3];
	pNodeArr[3]->next = pNodeArr[4];
	pNodeArr[4]->next = NULL;
	//��ӡ
	struct LinkNode * currentNode = pNodeArr[0];//������ָ��ͷ���
	while (currentNode != NULL)
	{
		printf("%d\n", currentNode->num);
		currentNode = currentNode->next;
	}
	//�ͷ��ڴ�
	freeNodeSpace(pNodeArr,5);
	pNodeArr = NULL;
}
void main_03()
{
	test_31();
	//test_32();
}