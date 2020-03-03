#pragma once

typedef void* LinkQueue;
// ���еĽڵ�
struct QueueNode
{
	struct QueLQueueueNode* next;
};
//��ʽʵ�ֵĶ��еĽṹ��
struct LQueue
{
	//ͷ���
	struct QueueNode m_header;
	//���д�С
	int m_size;
	//ά��β����ָ��
	struct QueueNode* pTail;
};

//��ʼ��
LinkQueue init_LinkQueue();

//��β�����
void push_LinkQueue(LinkQueue lq, void* data);

//��ͷ������
void pop_LinkQueue(LinkQueue lq);

//����ͷ��Ԫ��ָ��
void* front_LinkQueue(LinkQueue lq);

//����β��Ԫ��ָ��
void* back_LinkQueue(LinkQueue lq);

//���ض����С
int size_LinkQueue(LinkQueue lq);

//����
void destroy_LinkQueue(LinkQueue lq);