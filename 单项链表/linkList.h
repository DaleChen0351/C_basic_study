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
//���ض�����ǰ����������
void insert_LinkList_C(struct LinkNode* pHeader, int oldVal, int newVal);
//ɾ������
void remove_LinkList_C(struct LinkNode* pHeader, int val);
//�������
void clear_LinkList_C(struct LinkNode* pHeader);
//��������
void destroy_LinkList(struct LinkNode* pHeader);


//remove_if
