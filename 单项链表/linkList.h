#pragma once


//�ڵ������
struct LinkNode
{
	int num;
	struct LinkNode *next;
};

//��ʼ������
struct LinkNode* init_LinkList_C();
//��������
void foreach_LinkList_C(struct LinkNode* pH);
